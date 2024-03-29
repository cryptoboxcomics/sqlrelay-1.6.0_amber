#! /usr/bin/env python

# Copyright (c) 2000 Roman Milner
# See the file COPYING for more information

import sys
from time import localtime, time, mktime

import weakref
from SQLRelay import CSQLRelay

apilevel='2.0'
threadsafety=1
paramstyle='named'


class Error(Exception):
    pass

class Warning(Exception):
    pass

class InterfaceError(Error):
    pass

class DatabaseError(Error):
    pass

class InternalError(DatabaseError):
    pass

class OperationalError(DatabaseError):
    pass

class ProgrammingError(DatabaseError):
    pass

class IntegrityError(DatabaseError):
    pass

class DataError(DatabaseError):
    pass

class NotSupportedError(DatabaseError):
    pass


def connect(host, port, socket, user, password, retrytime=0, tries=1, krb='no', krbservice='', krbmech='', krbflags='', tls='no', tlsversion='', tlscert='', tlspassword='', tlsciphers='', tlsvalidate='', tlsca='', tlsdepth=0, db='', debug=0, columnnamecase='mixed', resultsetbuffersize=0, dontgetcolumninfo=0, nullsasnone=1, lazyconnect=1, bindvariabledelimiters="?:@$"):
    return SQLRConnection(host, port, socket, user, password, retrytime, tries, krb, krbservice, krbmech, krbflags, tls, tlsversion, tlscert, tlspassword, tlsciphers, tlsvalidate, tlsca, tlsdepth, db, debug, columnnamecase, resultsetbuffersize, dontgetcolumninfo, nullsasnone, lazyconnect, bindvariabledelimiters)


class SQLRConnection:

    connection=None

    def __init__(self, host, port, socket, user, password, retrytime, tries, krb, krbservice, krbmech, krbflags, tls, tlsversion, tlscert, tlspassword, tlsciphers, tlsvalidate, tlsca, tlsdepth, db, debug, columnnamecase, resultsetbuffersize, dontgetcolumninfo, nullsasnone, lazyconnect, bindvariabledelimiters):

        # create the connection
        self.connection=CSQLRelay.sqlrcon_alloc(host, port, socket, user, password, retrytime, tries)

        # enable kerberos or tls if requested
        if CSQLRelay.isYes(str(krb)):
                CSQLRelay.enableKerberos(self.connection, krbservice, krbmech, krbflags)
        elif CSQLRelay.isYes(str(tls)):
                CSQLRelay.enableTls(self.connection, tlsversion, tlscert, tlspassword, tlsciphers, tlsvalidate, tlsca, tlsdepth)

        # select db if requested
        if db!='':
                CSQLRelay.selectDatabase(self.connection, db)

        # enable debug if requested
        if CSQLRelay.isYes(str(debug)):
                CSQLRelay.debugOn(self.connection)
        elif not CSQLRelay.isNo(str(debug)):
                CSQLRelay.debugOn(self.connection)
                CSQLRelay.setDebugFile(self.connection, str(debug))

        # set flags
        self.columnnamecase=columnnamecase
        self.resultsetbuffersize=resultsetbuffersize
        self.dontgetcolumninfo=dontgetcolumninfo
        self.nullsasnone=nullsasnone
        CSQLRelay.setBindVariableDelimiters(self.connection, bindvariabledelimiters)

        # if we're not doing lazy connects then do something
        # lightweight to connect to the server now
        if CSQLRelay.isNo(str(lazyconnect)):
                CSQLRelay.identify();

        # create the cursor dictionary
        self._cursors=weakref.WeakValueDictionary()

    def __del__(self):
        self.close()

    def close(self):
        if self.connection is not None:
                # first we close any remaining cursors to avoid segfaults
                for cursor in self._cursors.values():
                        cursor.close()
                # then we close the connection
                CSQLRelay.sqlrcon_free(self.connection)
                del self.connection

    def commit(self):
        self.rowcount=0
        if self.connection is not None:
                return CSQLRelay.commit(self.connection)

    def rollback(self):
        self.rowcount=0
        if self.connection is not None:
                return CSQLRelay.rollback(self.connection)

    def cursor(self):
        cursor=SQLRCursor(self.connection, self.columnnamecase, self.resultsetbuffersize, self.dontgetcolumninfo, self.nullsasnone)
        self._cursors[id(cursor)]=cursor
        return cursor


class SQLRCursor:

    cursor=None

    def __init__(self, con, columnnamecase='mixed', resultsetbuffersize=0, dontgetcolumninfo=0, nullsasnone=1):
        self.cursor=CSQLRelay.sqlrcur_alloc(con)
        self.arraysize=1

        # set column case
        if columnnamecase=='upper':
            CSQLRelay.upperCaseColumnNames(self.cursor)
        elif columnnamecase=='lower':
            CSQLRelay.lowerCaseColumnNames(self.cursor)
        else:
            CSQLRelay.mixedCaseColumnNames(self.cursor)

        # set result set buffer size
        CSQLRelay.setResultSetBufferSize(self.cursor, resultsetbuffersize)

        # set column info
        if CSQLRelay.isYes(str(dontgetcolumninfo)):
            CSQLRelay.dontGetColumnInfo(self.cursor)
        else:
            CSQLRelay.getColumnInfo(self.cursor)

        # set null/none behavior for nulls
        if CSQLRelay.isYes(str(nullsasnone)):
            CSQLRelay.getNullsAsNone(self.cursor)
        else:
            CSQLRelay.getNullsAsEmptyStrings(self.cursor)
    

    def __del__(self):
        self.close()

    def setinputsizes(self):
        pass

    def setoutputsize(self):
        pass
        
    def execute(self, operation, parameters=None):
        self.rowcount=0
        self.cur_row=0
        CSQLRelay.prepareQuery(self.cursor,operation)
        if parameters is not None:
                for i in parameters.keys():
                        precision=0
                        scale=0
                        if type(parameters.keys())==type(1.1):
                                precision=len(str(parameters.keys()))-1
                                scale=precision-len(str(int(parameters.keys())))-1
                        CSQLRelay.inputBind(self.cursor,i,parameters[i],precision,scale)
        CSQLRelay.executeQuery(self.cursor)
        the_error=CSQLRelay.cursorErrorMessage(self.cursor)
        if the_error:
            raise DatabaseError('<pre>%s</pre>' % the_error)
        self.__set_description()
        self.rowcount=CSQLRelay.totalRows(self.cursor)
        if CSQLRelay.affectedRows(self.cursor)>0:
                self.rowcount=CSQLRelay.affectedRows(self.cursor)

    def executemany(self, operation, parameters=None):
        if parameters is None:
                self.execute(operation)
        else:
                self.rowcount=0
                self.cur_row=0
                CSQLRelay.prepareQuery(self.cursor,operation)
                for p in parameters:
                        CSQLRelay.clearBinds(self.cursor)
                        if p is not None:
                                for i in p.keys():
                                        precision=0
                                        scale=0
                                        if type(p.keys())==type(1.1):
                                                precision=len(str(p.keys()))-1
                                                scale=precision-len(str(int(p.keys())))-1
                                        CSQLRelay.inputBind(self.cursor,i,p[i],precision,scale)
                        CSQLRelay.executeQuery(self.cursor)
                        the_error=CSQLRelay.cursorErrorMessage(self.cursor)
                        if the_error:
                                raise DatabaseError('<pre>%s</pre>' % the_error)
                        self.__set_description()
                        self.rowcount=CSQLRelay.totalRows(self.cursor)
                        if CSQLRelay.affectedRows(self.cursor)>0:
                                self.rowcount=CSQLRelay.affectedRows(self.cursor)
        
    def callproc(self, procname, parameters=None):
        self.execute(procname,parameters)
        
    def fetchone(self):
        row=self.__getRow(self.cur_row)
        self.cur_row=self.cur_row+1
        return row

    def fetchmany(self, size=None):
        if not size:
            size=self.arraysize
        num_rows=CSQLRelay.rowCount(self.cursor)
        if num_rows==0:
            return None
        if size>=num_rows:
            size=num_rows-1
        rc=self.__getRowRange(self.cur_row, size)
        self.cur_row=size
        return rc

    def fetchall(self):
        rc=[]
        num_rows=CSQLRelay.rowCount(self.cursor)
        for row in range(self.cur_row, num_rows):
            row=self.__getRow(self.cur_row)
            self.cur_row=self.cur_row+1
            rc.append(row)
        return rc

    def close(self):
        if self.cursor is not None:
                CSQLRelay.sqlrcur_free(self.cursor)
                del self.cursor

    def __set_description(self):
        desc=[]
        col_c=CSQLRelay.colCount(self.cursor)
        if not col_c:
            self.description=[]
            return None
        for field in range(col_c):
            row=[]
            row.append(CSQLRelay.getColumnName(self.cursor,field),)
            row.append(CSQLRelay.getColumnType(self.cursor,field),)
            row.append(CSQLRelay.getColumnLength(self.cursor,field))
            desc.append(tuple(row))
        self.description=tuple(desc)
        return tuple(desc)

    def __getRow(self, row):
        # FIXME: go through each field, if the column type is a date/time
        # column, then create a DateTime object and return it instead of
        # a string
        rc=CSQLRelay.getRow(self.cursor,row)
        return rc

    def __getRowRange(self, row, size):
        # FIXME: go through each field, if the column type is a date/time
        # column, then create a DateTime object and return it instead of
        # a string
        rc=CSQLRelay.getRowRange(self.cursor,row,size)
        return rc
