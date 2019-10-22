// Copyright (c) 1999-2018 David Muse
// See the file COPYING for more information

#include <sqlrelay/sqlrserver.h>
#include <rudiments/process.h>
#include <rudiments/charstring.h>
#include <rudiments/file.h>
#include <rudiments/permissions.h>
#include <rudiments/filesystem.h>
#include <rudiments/stringbuffer.h>


class SQLRSERVER_DLLSPEC sqlrfilter_frequency : public sqlrfilter {
	public:
			sqlrfilter_frequency(sqlrservercontroller *cont,
						sqlrfilters *fs,
						domnode *parameters);
		bool	run(sqlrserverconnection *sqlrcon,
					sqlrservercursor *sqlrcur,
					const char *query);
	private:
		const char		*pattern;

		bool	enabled;

		bool	debug;
		
		//Fields related to debugging
		char		*querylogname;
		file		querylog;
		bool		usecommand;

		file		debuggerfile;
};

sqlrfilter_frequency::sqlrfilter_frequency(sqlrservercontroller *cont,
						sqlrfilters *fs,
						domnode *parameters) :
						sqlrfilter(cont,fs,parameters) {
	charstring::printf(&querylogname, "/tmp/recentqueries.log");
	//Debugger file
	debuggerfile.open("/tmp/debugger.txt", O_WRONLY|O_CREAT, permissions::evalPermString("rw-rw-rw-"));
	debuggerfile.write("Ready to accept reads.");
	//pid_t   pid=process::getProcessId();
	enabled=!charstring::isNo(parameters->getAttributeValue("enabled"));
	if (!enabled) {
		return;
	}
	
	pattern=parameters->getAttributeValue("pattern");
}


bool sqlrfilter_frequency::run(sqlrserverconnection *sqlrcon,
				sqlrservercursor *sqlrcur,
				const char *query) {
	
	querylog.open(querylogname, O_WRONLY|O_CREAT, permissions::evalPermString("rw-rw-rw-"));
	querylog.setPositionRelativeToEnd(0);

	if (!enabled) {
		return true;
	}
	else {
		stringbuffer debugger;
		file f;
		debuggerfile.write("line 63\n");

                if (!f.open("/tmp/recentqueries.log",O_RDONLY)) {
			debuggerfile.write("Failure opening the file\n");
                }
		
		time_t  mod=f.getLastModificationTime();
                datetime        dm;
                dm.initialize(mod);
                debuggerfile.write(dm.getString());

		debuggerfile.write("line 67\n");
		stringbuffer logentry;
                ssize_t bytesread=0;
                do {
                       	char    *line=NULL;
                       	bytesread=f.read(&line,"\n");
                       	if (bytesread>0) {
				char ** parts;
				uint64_t partcount;
				charstring::split(line,"\n",true, &parts, &partcount);
				line=parts[0];
				debuggerfile.write(debugger.getString());
				if (!charstring::compare(query,line)) {
					logentry.append(query);
					logentry.append("\n");
					querylog.write(logentry.getString());
					f.close();
					querylog.close();
					delete[] line;
					return false;
				}
                       	}
                        delete[] line;
                } while (bytesread>0);
		logentry.append(query);
		logentry.append("\n");
		querylog.write(logentry.getString());
		querylog.close();
		f.close();
		return true;
	
	}
	return true;
}

extern "C" {
	SQLRSERVER_DLLSPEC sqlrfilter *new_sqlrfilter_frequency(
						sqlrservercontroller *cont,
						sqlrfilters *fs,
						domnode *parameters) {
		return new sqlrfilter_frequency(cont,fs,parameters);
	}
}
