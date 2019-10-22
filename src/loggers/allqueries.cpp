// Copyright (c) 1999-2018 David Muse
// See the file COPYING for more information

#include <sqlrelay/sqlrserver.h>
#include <rudiments/process.h>
#include <rudiments/charstring.h>
#include <rudiments/file.h>
#include <rudiments/permissions.h>
#include <rudiments/filesystem.h>
#include <rudiments/stringbuffer.h>

class SQLRSERVER_DLLSPEC sqlrlogger_allqueries : public sqlrlogger {
	public:
			sqlrlogger_allqueries(sqlrloggers *ls,
						domnode *parameters);
			~sqlrlogger_allqueries();

		bool	init(sqlrlistener *sqlrl, sqlrserverconnection *sqlrcon);
		bool	run(sqlrlistener *sqlrl,
					sqlrserverconnection *sqlrcon,
					sqlrservercursor *sqlrcur,
					sqlrlogger_loglevel_t level,
					sqlrevent_t event,
					const char *info);
	private:
		char		*querylogname;
		file		querylog;
		uint64_t	sec;
		uint64_t	usec;
		uint64_t	totalusec;
		bool		usecommand;
		bool		enabled;
		//For debugging
		file	debuggerfile;
};

sqlrlogger_allqueries::sqlrlogger_allqueries(sqlrloggers *ls,
						domnode *parameters) :
						sqlrlogger(ls,parameters) {
	querylogname=NULL;
	sec=charstring::toInteger(parameters->getAttributeValue("sec"));
	usec=charstring::toInteger(parameters->getAttributeValue("usec"));
	totalusec=sec*1000000+usec;
	usecommand=!charstring::compareIgnoringCase(
			parameters->getAttributeValue("timer"),"command");
	enabled=!charstring::isNo(parameters->getAttributeValue("enabled"));
	debuggerfile.open("/tmp/debugger.txt", O_WRONLY|O_CREAT, permissions::evalPermString("rw-------"));
        debuggerfile.setPositionRelativeToEnd(0);

}

sqlrlogger_allqueries::~sqlrlogger_allqueries() {
	querylog.flushWriteBuffer(-1,-1);
	delete[] querylogname;
}

bool sqlrlogger_allqueries::init(sqlrlistener *sqlrl,
					sqlrserverconnection *sqlrcon) {

	if (!enabled) {
		return true;
	}

	// don't log anything for the listener
	if (!sqlrcon) {
		return true;
	}

	// get the pid
	pid_t	pid=process::getProcessId();

	// build up the query log name
	delete[] querylogname;
	charstring::printf(&querylogname,
				"%s/sqlr-connection-%s-querylog.%ld",
				sqlrcon->cont->getLogDir(),
				sqlrcon->cont->getId(),(long)pid);

	// remove any old log file
	file::remove(querylogname);

	// create the new log file
	if (!querylog.create(querylogname,
				permissions::evalPermString("rw-------"))) {
		return false;
	}

	// optimize
	filesystem	fs;
	fs.open(querylogname);
	querylog.setWriteBufferSize(fs.getOptimumTransferBlockSize());
	return true;
}

static const char *days[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

bool sqlrlogger_allqueries::run(sqlrlistener *sqlrl,
					sqlrserverconnection *sqlrcon,
					sqlrservercursor *sqlrcur,
					sqlrlogger_loglevel_t level,
					sqlrevent_t event,
					const char *info) {
	if (!enabled) {
		return true;
	}

	// don't log anything for the listener
	if (!sqlrcon) {
		return true;
	}

	// don't do anything unless we got INFO/QUERY
	if (level!=SQLRLOGGER_LOGLEVEL_INFO || event!=SQLREVENT_QUERY) {
		return true;
	}
	// reinit the log if the file was switched
	file	querylog2;
	if (querylog2.open(querylogname,O_RDONLY)) {
		ino_t	inode1=querylog.getInode();
		ino_t	inode2=querylog2.getInode();
		querylog2.close();
		if (inode1!=inode2) {
			querylog.flushWriteBuffer(-1,-1);
			querylog.close();
			init(sqlrl,sqlrcon);
		}
	}


	// log times
		debuggerfile.write("The method before the write is getting reached\n");
		datetime	dt;
		dt.getSystemDateAndTime();
		char	datebuffer[26];
		charstring::printf(datebuffer,sizeof(datebuffer),
					"%s %d %s % 2d  %02d:%02d:%02d",
					days[dt.getDayOfWeek()-1],
					dt.getYear(),
					dt.getMonthAbbreviation(),
					dt.getDayOfMonth(),
					dt.getHour(),
					dt.getMinutes(),
					dt.getSeconds());
		
		stringbuffer	logentry;
		logentry.append(datebuffer)->append(" :\n");
		logentry.append(sqlrcur->getQueryBuffer());
		logentry.append("\n");
		if ((size_t)querylog.write(logentry.getString(),
					logentry.getStringLength())!=
						logentry.getStringLength()) {
			return false;
		}
		//querylog.flushWriteBuffer(-1,-1);
	return true;
}

extern "C" {
	SQLRSERVER_DLLSPEC sqlrlogger *new_sqlrlogger_allqueries(
						sqlrloggers *ls,
						domnode *parameters) {
		return new sqlrlogger_allqueries(ls,parameters);
	}
}
