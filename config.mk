SQLR_VERSION = 1.6.0
SRV_SONAME_VERSION_INFO = 9:0:1
CLT_SONAME_VERSION_INFO = 5:0:0

SQLRELAY_ENABLE_SHARED = yes

SQLR=sqlr
SQLRELAY=sqlrelay

# installation directories
prefix = ${DESTDIR}/usr/local/firstworks
exec_prefix= ${prefix}
includedir = ${prefix}/include
libdir = ${exec_prefix}/lib
javadir = ${exec_prefix}/java
dotnetdir = $(libdir)
libexecdir = ${exec_prefix}/libexec/$(SQLRELAY)
bindir = ${exec_prefix}/bin
localstatedir = ${prefix}/var
sysconfdir = ${prefix}/etc
mandir = ${prefix}/share/man
datadir = ${prefix}/share
docdir = ${datadir}/doc/$(SQLRELAY)
licensedir = ${datadir}/licenses/$(SQLRELAY)
EXAMPLEDIR = ${datadir}/$(SQLRELAY)/examples
tmpdir = ${localstatedir}/run/$(SQLRELAY)
cachedir = ${localstatedir}/cache/$(SQLRELAY)
logdir = ${localstatedir}/log/$(SQLRELAY)
debugdir = ${logdir}/debug
initscript_prefix = 


# command separator
AND = ;


# "this directory" prefix
THISDIR = ./


# script extension
SCRIPTINT =
SCRIPTEXT = .sh


# slash
SLASH = /


# shell
SHELL = /bin/sh


# libtool command
LIBTOOL = $(SHELL) $(top_builddir)/libtool


# compile commands
LTCOMPILE = $(LIBTOOL) --mode=compile
CC = gcc
CXX = g++
COMPILE = -c
OUT = -o 
BASECPPFLAGS = 
EXTRACPPFLAGS =
CXXFLAGS =   -Wall -pipe   
CFLAGS =   -Wall -pipe   
WERROR = -Werror
WNOUNKNOWNPRAGMAS = -Wno-unknown-pragmas
WNOMISMATCHEDTAGS = 
INC = -I
OBJ = lo
DIRCPPFLAG = -DBINDIR=\"$(bindir)/\" -DLOCALSTATEDIR=\"$(localstatedir)/\" -DSYSCONFDIR=\"$(sysconfdir)/\" -DLIBEXECDIR=\"$(libexecdir)/\"


# linker flags
LTLINK = $(LIBTOOL) --mode=link
LINK = g++
CCLINK = gcc
AR = ar
LDFLAGS = 
SRVLINKFLAGS = -rpath $(libdir) -version-info $(SRV_SONAME_VERSION_INFO) -no-undefined
CLTLINKFLAGS = -rpath $(libdir) -version-info $(CLT_SONAME_VERSION_INFO) -no-undefined
MODLINKFLAGS = -rpath $(libexecdir) -avoid-version -module -no-undefined
INSTALLLIB = installlib
UNINSTALLLIB = uninstalllib
LIBEXT = la


# install commands
LTINSTALL = $(LIBTOOL) --mode=install
MV = mv
CP = cp
CHMOD = chmod
MKINSTALLDIRS = $(top_builddir)/mkinstalldirs
LTFINISH = $(LIBTOOL) --mode=finish
REPLACE = $(top_builddir)/replace.sh


#uninstall/clean commands
LTUNINSTALL = $(LIBTOOL) --mode=uninstall
LTCLEAN = $(LIBTOOL) --mode=clean
RM = rm -f
RMTREE = rm -rf
RMDIR = rmdir


# command to create a symbolic link
SYMLINK = ln -s


# uname -s
UNAME = Linux


# client/server rpath flags
CLIENTUSERPATH = 
SERVERUSERPATH = 


# math library
MATHLIB = 


# extra libs
EXTRALIBS = -lz 


# windows environment
MINGW32 = 
CYGWIN = 
UWIN = 
MICROSOFT = 


# rudiments library
RUDIMENTSPATH = 
RUDIMENTSINCLUDES = 
RUDIMENTSLIBS = -L/usr/lib64 -lrudiments -lpthread -ledit -ltermcap -lssl -lcrypto -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err -lkrb5 -lk5crypto -lcom_err -lpcre -lcurl -lcrypt -ldl
RUDIMENTSLIBSPATH =  


#iconv
HAVE_ICONV = yes
ICONVINCLUDES = 
ICONVLIBS = 


# dmalloc
LIBDMALLOC = 


# ElectricFence
LIBEFENCE = 


# c++
ENABLE_CPP = yes
CPPCPPFLAGS = $(WERROR) $(BASECPPFLAGS) -I./ -I$(top_builddir)/ -I$(top_builddir)/src/common $(RUDIMENTSINCLUDES)
CPPLIBS = $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE)


# c
CUSERPATH = 
CCPPFLAGS = $(WERROR) $(BASECPPFLAGS) $(WNOMISMATCHEDTAGS) -I./ -I$(top_builddir)/ -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
CLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE)
ifneq ($(strip $(libdir)),)
ifeq ($(CUSERPATH),yes)
CLIBS += -R $(libdir)
endif
endif


# c#
HAVE_MONO = 
CSC = /bin/mcs
CSCFLAGS = 
SN = /bin/sn
ILDASM = 
ILDASMOUT = > 
ILASM = 
GACUTIL = /bin/gacutil


# perl
HAVE_PERL = yes
PERL = perl
PERLPREFIX = /usr
PERLLIB = /usr/share/perl5
PERLINC = -I/usr/lib64/perl5/CORE
PERLCCFLAGS = -D_REENTRANT -D_GNU_SOURCE -fno-strict-aliasing -pipe -fstack-protector -I/usr/local/include -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64  
PERLOPTIMIZE = -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fexceptions -fstack-protector-strong --param=ssp-buffer-size=4 -grecord-gcc-switches -m64 -mtune=generic
PERLSITEARCH = /usr/local/lib64/perl5
PERLSITELIB = /usr/local/share/perl5
PERLARCHLIBEXP = /usr/lib64/perl5
PERLINSTALLMAN3DIR = /usr/share/man/man3
PERLMAN3EXT = 3pm
PERLMANCLASSSEPARATOR = ::
XSUBPP = /usr/bin/xsubpp
POD2MAN = pod2man
OVERRIDEPERLSITEARCH = 
OVERRIDEPERLSITELIB = 
OVERRIDEPERLINSTALLMAN3DIR = 
OVERRIDEPERLMAN3EXT = 
PERLCCFLAGS_LOCAL = $(shell echo "$(PERLCCFLAGS)" | sed -e 's| -belf||g' -e 's|-KPIC||g' -e 's|-x.* | |g' -e 's|-x.*$$||g' -e "s|UNKNOWN||g" -e "s|-Dbool=char||g" -e "s|-mtune=.* | |g" -e "s|-arch .* ||g" -e "s|-Kalloca ||g")
PERLOPTIMIZE_LOCAL = $(shell echo "$(PERLOPTIMIZE)" | sed -e 's| -belf||g' -e 's|-KPIC||g' -e 's|-x.* | |g' -e 's|-x.*$$||g' -e "s|UNKNOWN||g" -e "s|-Dbool=char||g" -e "s|-mtune=.* | |g")
ifeq ($(OVERRIDEPERLSITEARCH),)
PERLSITEARCH_LOCAL = $(DESTDIR)$(shell echo "$(PERLSITEARCH)" | sed -e "s|UNKNOWN||g" )
else
PERLSITEARCH_LOCAL = $(DESTDIR)$(OVERRIDEPERLSITEARCH)
endif
ifeq ($(OVERRIDEPERLSITELIB),)
PERLSITELIB_LOCAL = $(DESTDIR)$(shell echo "$(PERLSITELIB)" | sed -e "s|UNKNOWN||g" )
else
PERLSITELIB_LOCAL = $(DESTDIR)$(OVERRIDEPERLSITELIB)
endif
PERLINC_LOCAL = $(DESTDIR)$(shell echo "$(PERLINC)" | sed -e "s|UNKNOWN||g" )
ifeq ($(OVERRIDEPERLINSTALLMAN3DIR),)
PERLINSTALLMAN3DIR_LOCAL = $(DESTDIR)$(shell echo "$(PERLINSTALLMAN3DIR)" | sed -e "s|UNKNOWN||g" )
else
PERLINSTALLMAN3DIR_LOCAL = $(DESTDIR)$(OVERRIDEPERLINSTALLMAN3DIR)
endif
ifeq ($(OVERRIDEPERLMAN3EXT),)
PERLMAN3EXT_LOCAL = $(shell echo "$(PERLMAN3EXT)" | sed -e "s|UNKNOWN||g" )
else
PERLMAN3EXT_LOCAL = $(OVERRIDEPERLMAN3EXT)
endif
PERLCPPFLAGS = $(BASECPPFLAGS) $(PERLOPTIMIZE_LOCAL) $(PERLCCFLAGS_LOCAL) -I$(top_builddir) -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES) $(PERLINC_LOCAL)
PERLCONLIBS = $(PERLLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE) -rpath $(PERLSITEARCH_LOCAL)/auto/SQLRelay/Connection
PERLCURLIBS = $(PERLLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE) -rpath $(PERLSITEARCH_LOCAL)/auto/SQLRelay/Cursor
ifneq ($(strip $(libdir)),)
ifeq ($(PERLUSERPATH),yes)
PERLCONLIBS += -R $(libdir)
PERLCURLIBS += -R $(libdir)
endif
endif
PERLINSTALLMAN =
ifneq ($(POD2MAN),)
ifneq ($(PERLINSTALLMAN3DIR_LOCAL),)
PERLINSTALLMAN = installman
endif
endif


# python
HAVE_PYTHON = yes
PYTHONINCLUDES =  -I/usr/include/python2.7
PYTHONDIR = /usr/lib64/python2.7
PYTHONSITEDIR = site-packages
PYTHONUSERPATH = 
PYTHONLIB = 
PYTHON = /usr/bin/python2.7
PYTHONCPPFLAGS = -DHAVE_CONFIG $(BASECPPFLAGS) $(PYTHONINCLUDES) -I$(top_builddir)/src/common -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
PYTHONLIBS = $(PYTHONLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE) -rpath $(PYTHONDIR)/$(PYTHONSITEDIR)/SQLRelay
ifneq ($(strip $(libdir)),)
ifeq ($(PYTHONUSERPATH),yes)
PYTHONLIBS += -R $(libdir)
endif
endif
IMPORTEXCEPTIONS = 
EXCEPTIONSSTANDARDERROR = Exception


# ruby
HAVE_RUBY = yes
RUBY = ruby
RUBYLIB = 
OVERRIDERUBYSITEARCHDIR = 

RUBYCFLAGS = $(shell LANG=POSIX $(RUBY) getcflags.rb | sed -e "s|-x.* | |g" -e "s|-belf||g" -e "s|-mtune=.* | |g" | $(MAKE) -s -f - | grep -v Entering | grep -v Leaving )

ifeq ($(OVERRIDERUBYSITEARCHDIR),)
RUBYSITEARCHDIR = $(shell LANG=POSIX $(RUBY) getsitearchdir.rb | $(MAKE) -s -f - | grep -v Entering | grep -v Leaving )
else
RUBYSITEARCHDIR = $(OVERRIDERUBYSITEARCHDIR)
endif

RUBYCPPFLAGS = -DHAVE_CONFIG $(BASECPPFLAGS) $(RUBYCFLAGS) -I./ -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
RUBYLIBS = $(RUBYLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE) -rpath $(RUBYSITEARCHDIR)
ifneq ($(strip $(libdir)),)
ifeq ($(RUBYUSERPATH),yes)
RUBYLIBS += -R $(libdir)
endif
endif


# php
HAVE_PHP = yes
PHPINCLUDES = -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib
PHPEXTDIR = /usr/lib64/php/modules
PHPUSERPATH = 
PHPVERSION = 5.4.16
PHPMAJORVERSION = 5
PHPLIB = 
PHPCONFDIR = /etc/php.d
PHPCONFSTYLE = fedora
HAVE_PHP_PDO = yes
PHPCPPFLAGS = $(BASECPPFLAGS) -I$(top_builddir) -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES) $(PHPINCLUDES) -DCOMPILE_DL=1
PHPLIBS = $(PHPLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) -rpath $(PHPEXTDIR)
ifneq ($(strip $(libdir)),)
ifeq ($(PHPUSERPATH),yes)
PHPLIBS += -R $(libdir)
endif
endif
PHPPDOCPPFLAGS = $(BASECPPFLAGS) -I$(top_builddir) -I$(top_builddir)/src/common -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES) $(PHPINCLUDES) -DCOMPILE_DL=1
PHPPDOLIBS = $(PHPLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) -rpath $(PHPEXTDIR)
ifneq ($(strip $(libdir)),)
ifeq ($(PHPUSERPATH),yes)
PHPPDOLIBS += -R $(libdir)
endif
endif


# java
HAVE_JAVA = yes
JAVAC = /etc/alternatives/java_sdk/bin/javac
JAR = /etc/alternatives/java_sdk/bin/jar
JAVAINCLUDES = -I/etc/alternatives/java_sdk/include -I/etc/alternatives/java_sdk/include/linux
JAVAUSERPATH = 
JAVACPPFLAGS = $(WERROR) $(WNOUNKNOWNPRAGMAS) $(BASECPPFLAGS) -I./ -I$(top_builddir) -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES) $(JAVAINCLUDES)
JAVALIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) -rpath $(javadir)/com/firstworks/sqlrelay
CURSORCLASSPATH=-classpath $(top_builddir)/src/api/java
ifneq ($(strip $(libdir)),)
ifeq ($(JAVAUSERPATH),yes)
JAVALIBS += -R $(libdir)
endif
endif


# tcl
HAVE_TCL = yes
TCLINCLUDE = -I/usr/include/
TCLLIB = -L/usr/lib64 -ltcl8.5
TCLLIBSPATH = /usr/lib64
TCLUSERPATH = 
TCLCPPFLAGS = -DHAVE_CONFIG $(BASECPPFLAGS) $(TCLINCLUDE) -I$(top_builddir) -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
TCLLIBS = $(TCLLIB) -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE) -rpath $(TCLLIBSPATH)/sqlrelay
ifneq ($(strip $(libdir)),)
ifeq ($(TCLUSERPATH),yes)
TCLLIBS += -R $(libdir)
endif
endif


# erlang
HAVE_ERLANG = yes
ERLC = ERLC_EMULATOR=/usr/bin/erl /usr/bin/erlc
ERLCFLAGS = 
ERLANGINCLUDES = -I/usr/lib64/erlang/lib/erl_interface-3.7.15/include
ERLANGLIB = -L/usr/lib64/erlang/lib/erl_interface-3.7.15/lib -lerl_interface -lei
ERLANG_ROOT_DIR = /usr/lib64/erlang
ERLANG_LIB_DIR = /usr/lib64/erlang/lib/erl_interface-3.7.15/lib
ERLANG_INSTALL_LIB_DIR = %{libdir}/erlang/lib
ERLANGUSERPATH = 
ERLANGCPPFLAGS = -DHAVE_CONFIG $(BASECPPFLAGS) $(ERLANGINCLUDES) -I$(top_builddir)/src/common -I$(top_builddir)/src/api/c -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
ERLANGLIBS = $(ERLANGLIB) -L$(top_builddir)/src/api/c -L$(top_builddir)/src/api/c++ -l$(SQLR)clientwrapper -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBDMALLOC) $(LIBEFENCE)
ifneq ($(strip $(libdir)),)
ifeq ($(ERLANGUSERPATH),yes)
ERLANGLIBS += -R $(libdir)
endif
endif


# node.js
HAVE_NODEJS = yes
NODE = /usr/bin/node
NODEGYP = /usr/bin/node /usr/lib/node_modules/npm/node_modules/node-gyp/bin/node-gyp.js
NODEMODULEDIR = /usr/lib/node_modules
NODEJSCFLAGS = -std=c++11 -I/root/sqlrelay-1.6.0/src/api/c++ $(RUDIMENTSINCLUDES)
NODEJSLIBS = -L/root/sqlrelay-1.6.0/src/api/c++/.libs -l$(SQLR)client $(RUDIMENTSLIBS)


# mysql drop-in
ENABLE_MYSQL_DROP_IN = yes


# postgresql drop-in
ENABLE_POSTGRESQL_DROP_IN = yes
PSQLUSERPATH = 


# libsocket
SOCKETLIBS = 


# oracle
ENABLE_ORACLE = 
ORACLEINCLUDES = 
ORACLELIBS = 
ORACLELIBSPATH = 
ORACLEUSERPATH = yes
ifneq ($(strip $(ORACLELIBS)),)
ifneq ($(strip $(ORACLELIBSPATH)),)
ifeq ($(ORACLEUSERPATH),yes)
ORACLELIBS += -Wl,--disable-new-dtags -R $(ORACLELIBSPATH)
endif
endif
endif


# mysql
MYSQLINCLUDES = -I/usr/include/mysql
MYSQLLIBS = -L/usr/lib64/mysql -lmysqlclient -lpthread -lz -lm -ldl -lssl -lcrypto
MYSQLLIBSPATH = /usr/lib64/mysql
MYSQLUSERPATH = 
ifneq ($(strip $(MYSQLLIBS)),)
ifneq ($(strip $(MYSQLLIBSPATH)),)
ifeq ($(MYSQLUSERPATH),yes)
MYSQLLIBS += -R $(MYSQLLIBSPATH)
endif
endif
endif
MYSQLDRLIBCPPFLAGS = $(WERROR) $(BASECPPFLAGS) -I./ -I$(top_builddir)/ -I$(top_builddir)/src/common -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
MYSQLDRLIBLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS)
ifneq ($(strip $(libdir)),)
ifeq ($(MYSQLUSERPATH),yes)
MYSQLDRLIBLIBS = -R $(libdir)
endif
endif


# postgresql
POSTGRESQLINCLUDES = 
POSTGRESQLLIBS = -lpq
POSTGRESQLLIBSPATH = /lib64
POSTGRESQLUSERPATH = 
ifneq ($(strip $(POSTGRESQLLIBS)),)
ifneq ($(strip $(POSTGRESQLLIBSPATH)),)
ifeq ($(POSTGRESQLUSERPATH),yes)
POSTGRESQLLIBS += -R $(POSTGRESQLLIBSPATH)
endif
endif
endif
POSTGRESQLDRLIBCPPFLAGS = $(WERROR) $(BASECPPFLAGS) -I./ -I$(top_builddir)/ -I$(top_builddir)/src/common -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
POSTGRESQLDRLIBLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS)
ifneq ($(strip $(libdir)),)
ifeq ($(PSQLUSERPATH),yes)
POSTGRESQLDRLIBLIBS += -R $(libdir)
endif
endif


# sqlite
SQLITEINCLUDES = -DSQLITE3 
SQLITELIBS = -lsqlite3
SQLITELIBSPATH = /lib64
SQLITEUSERPATH = 
ifneq ($(strip $(SQLITELIBS)),)
ifneq ($(strip $(SQLITELIBSPATH)),)
ifeq ($(SQLITEUSERPATH),yes)
SQLITELIBS += -R $(SQLITELIBSPATH)
endif
endif
endif


# freetds
FREETDSINCLUDES = 
FREETDSLIBS = 
FREETDSLIBSPATH = 
FREETDSUSERPATH = yes
ifneq ($(strip $(FREETDSLIBS)),)
ifneq ($(strip $(FREETDSLIBSPATH)),)
ifeq ($(FREETDSUSERPATH),yes)
FREETDSLIBS += -R $(FREETDSLIBSPATH)
endif
endif
endif


# sap/sybase
ENABLE_SYBASE = 
SYBASEINCLUDES = 
SYBASELIBS = 
SYBASELIBSPATH = 
SYBASEUSERPATH = yes
ifneq ($(strip $(SYBASELIBS)),)
ifneq ($(strip $(SYBASELIBSPATH)),)
ifeq ($(SYBASEUSERPATH),yes)
SYBASELIBS += -Wl,--disable-new-dtags -R $(SYBASELIBSPATH)
endif
endif
endif


# odbc
ENABLE_ODBC = @ENABLE_ODBC@
ENABLE_ODBC_DRIVER = yes
ODBCINCLUDES =  
ODBCLIBS = -lodbc -lodbcinst
ODBCLIBSPATH = /lib64
ODBCUSERPATH = 
ifneq ($(strip $(ODBCLIBS)),)
ifneq ($(strip $(ODBCLIBSPATH)),)
ifeq ($(ODBCUSERPATH),yes)
ODBCLIBS += -R $(ODBCLIBSPATH)
endif
endif
endif
ODBCUNICODE = yes
ODBCDRIVERCPPFLAGS = $(BASECPPFLAGS) -I$(top_builddir)/ -I$(top_builddir)/src/common -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES) $(ODBCINCLUDES)
ODBCDRIVERLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(ODBCLIBS)
ifneq ($(strip $(libdir)),)
ifeq ($(ODBCUSERPATH),yes)
ODBCDRIVERLIBS += -R $(libdir)
endif
endif


# mdbtools
MDBTOOLSINCLUDES = 
MDBTOOLSLIBS = 
MDBTOOLSLIBSPATH = 
MDBTOOLSUSERPATH = 
ifneq ($(strip $(MDBTOOLSLIBS)),)
ifneq ($(strip $(MDBTOOLSLIBSPATH)),)
ifeq ($(MDBTOOLSUSERPATH),yes)
MDBTOOLSLIBS += -R $(MDBTOOLSLIBSPATH)
endif
endif
endif


# db2
ENABLE_DB2 = 
DB2INCLUDES = 
DB2LIBS = 
DB2LIBSPATH = 
DB2USERPATH = yes
ifneq ($(strip $(DB2LIBS)),)
ifneq ($(strip $(DB2LIBSPATH)),)
ifeq ($(DB2USERPATH),yes)
DB2LIBS += -Wl,--disable-new-dtags -R $(DB2LIBSPATH)
endif
endif
endif


# firebird
FIREBIRDINCLUDES = 
FIREBIRDLIBS = 
FIREBIRDLIBSPATH = 
FIREBIRDUSERPATH = 
ifneq ($(strip $(FIREBIRDLIBS)),)
ifneq ($(strip $(FIREBIRDLIBSPATH)),)
ifeq ($(FIREBIRDUSERPATH),yes)
FIREBIRDLIBS += -R $(FIREBIRDLIBSPATH)
endif
endif
endif


# informix
ENABLE_INFORMIX = 
INFORMIXINCLUDES = 
INFORMIXLIBS = 
INFORMIXCLILIBSPATH = 
INFORMIXESQLLIBSPATH = 
INFORMIXUSERPATH = yes
ifneq ($(strip $(INFORMIXLIBS)),)
ifneq ($(strip $(INFORMIXCLILIBSPATH)),)
ifeq ($(INFORMIXUSERPATH),yes)
INFORMIXLIBS += -Wl,--disable-new-dtags -R $(INFORMIXCLILIBSPATH)
endif
endif
endif
ifneq ($(strip $(INFORMIXLIBS)),)
ifneq ($(strip $(INFORMIXESQLLIBSPATH)),)
ifeq ($(INFORMIXUSERPATH),yes)
INFORMIXLIBS += -Wl,--disable-new-dtags -R $(INFORMIXESQLLIBSPATH)
endif
endif
endif


# router
ENABLE_ROUTER = yes
ROUTERLIBSPATH =
ROUTERUSERPATH =


# auth modules
AUTHALLOPTIONALTARGETS =
AUTHINSTALLSHAREDLIBOPTIONALTARGETS =
ifneq ($(ENABLE_CPP),)
AUTHALLOPTIONALTARGETS += all-sqlrelay
ifeq ($(SQLRELAY_ENABLE_SHARED),yes)
AUTHINSTALLSHAREDLIBOPTIONALTARGETS += installsharedlib-sqlrelay
endif
endif


# util
STATICUTILPLUGINSRCS = 
ifeq ($(SQLRELAY_ENABLE_SHARED),no)
STATICUTILPLUGINSRCS += sqlrconfigdeclarations.cpp \
			sqlrconfigassignments.cpp
STATICUTILPLUGINLOBJS = $(shell ls ../configs/*.$(OBJ))
endif
UTILCPPFLAGS = $(WERROR) $(BASECPPFLAGS) $(DIRCPPFLAG) -I./ -I$(top_builddir)/ -I$(top_builddir)/src/common $(RUDIMENTSINCLUDES)
UTILLIBS = $(RUDIMENTSLIBS)


# cmdline
ENABLE_CMDLINE = yes
CMDLINECPPFLAGS = $(WERROR) $(BASECPPFLAGS) -I$(top_builddir)/ -I$(top_builddir)/src/common -I$(top_builddir)/src/util -I$(top_builddir)/src/server -I$(top_builddir)/src/api/c++ $(RUDIMENTSINCLUDES)
CMDLINELIBS = -L$(top_builddir)/src/util -l$(SQLR)util -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(RUDIMENTSLIBS) $(MATHLIB) $(EXTRALIBS) $(LIBDMALLOC) $(LIBEFENCE)


# util
ENABLE_UTIL = yes


# server
ENABLE_SERVER = yes
STATICPLUGINSRCS =
ifeq ($(SQLRELAY_ENABLE_SHARED),no)
STATICPLUGINSRCS += sqlrserverconnectiondeclarations.cpp \
		sqlrserverconnectionassignments.cpp \
		sqlrprotocoldeclarations.cpp \
		sqlrprotocolassignments.cpp \
		sqlrparserdeclarations.cpp \
		sqlrparserassignments.cpp \
		sqlrloggerdeclarations.cpp \
		sqlrloggerassignments.cpp \
		sqlrnotificationdeclarations.cpp \
		sqlrnotificationassignments.cpp \
		sqlrscheduledeclarations.cpp \
		sqlrscheduleassignments.cpp \
		sqlrrouterdeclarations.cpp \
		sqlrrouterassignments.cpp \
		sqlrpwdencdeclarations.cpp \
		sqlrpwdencassignments.cpp \
		sqlrauthdeclarations.cpp \
		sqlrauthassignments.cpp \
		sqlrdirectivedeclarations.cpp \
		sqlrdirectiveassignments.cpp \
		sqlrtranslationdeclarations.cpp \
		sqlrtranslationassignments.cpp \
		sqlrbindvariabletranslationdeclarations.cpp \
		sqlrbindvariabletranslationassignments.cpp \
		sqlrresultsettranslationdeclarations.cpp \
		sqlrresultsettranslationassignments.cpp \
		sqlrresultsetrowtranslationdeclarations.cpp \
		sqlrresultsetrowtranslationassignments.cpp \
		sqlrresultsetrowblocktranslationdeclarations.cpp \
		sqlrresultsetrowblocktranslationassignments.cpp \
		sqlrresultsetheadertranslationdeclarations.cpp \
		sqlrresultsetheadertranslationassignments.cpp \
		sqlrfilterdeclarations.cpp \
		sqlrfilterassignments.cpp \
		sqlrtriggerdeclarations.cpp \
		sqlrtriggerassignments.cpp \
		sqlrquerydeclarations.cpp \
		sqlrqueryassignments.cpp \
		sqlrmoduledatadeclarations.cpp \
		sqlrmoduledataassignments.cpp
STATICPLUGINLOBJS = $(shell ls ../connections/*.$(OBJ)) \
		$(shell ls ../protocols/*.$(OBJ)) \
		$(shell ls ../parsers/*.$(OBJ)) \
		$(shell ls ../loggers/*.$(OBJ)) \
		$(shell ls ../notifications/*.$(OBJ)) \
		$(shell ls ../schedules/*.$(OBJ)) \
		$(shell ls ../routers/*.$(OBJ)) \
		$(shell ls ../pwdencs/*.$(OBJ)) \
		$(shell ls ../auths/*.$(OBJ)) \
		$(shell ls ../directives/*.$(OBJ)) \
		$(shell ls ../translations/*.$(OBJ)) \
		$(shell ls ../bindvariabletranslations/*.$(OBJ)) \
		$(shell ls ../resultsettranslations/*.$(OBJ)) \
		$(shell ls ../resultsetrowtranslations/*.$(OBJ)) \
		$(shell ls ../resultsetrowblocktranslations/*.$(OBJ)) \
		$(shell ls ../resultsetheadertranslations/*.$(OBJ)) \
		$(shell ls ../filters/*.$(OBJ)) \
		$(shell ls ../triggers/*.$(OBJ)) \
		$(shell ls ../queries/*.$(OBJ)) \
		$(shell ls ../moduledatas/*.$(OBJ))
STATICPLUGINLIBS =
STATICPLUGINLIBS += $(DB2LIBS)
STATICPLUGINLIBS += $(FIREBIRDLIBS)
STATICPLUGINLIBS += $(FREETDSLIBS)
STATICPLUGINLIBS += $(MDBTOOLSLIBS)
STATICPLUGINLIBS += $(MYSQLLIBS)
STATICPLUGINLIBS += $(ODBCLIBS)
STATICPLUGINLIBS += $(ORACLELIBS)
STATICPLUGINLIBS += $(POSTGRESQLLIBS)
STATICPLUGINLIBS += $(SQLITELIBS)
STATICPLUGINLIBS += $(SYBASELIBS)
STATICPLUGINLIBS += -L$(top_builddir)/src/api/c++ -l$(SQLR)client
endif

SERVERCPPFLAGS = $(WERROR) $(BASECPPFLAGS) -I./ -I$(top_builddir)/ -I$(top_builddir)/src/common -I$(top_builddir)/src/util $(RUDIMENTSINCLUDES)
LIBSQLRSERVERLIBS = -L$(top_builddir)/src/util -l$(SQLR)util
SERVERLIBS = -L./ -l$(SQLR)server $(STATICPLUGINLIBS) -L$(top_builddir)/src/util -l$(SQLR)util $(RUDIMENTSLIBS) $(MATHLIB) $(EXTRALIBS) $(LIBDMALLOC) $(LIBEFENCE)
CACHEMANAGERLIBS = -L$(top_builddir)/src/util -l$(SQLR)util $(RUDIMENTSLIBS) $(MATHLIB) $(EXTRALIBS) $(LIBDMALLOC) $(LIBEFENCE)
ifneq ($(strip $(libdir)),)
ifeq ($(SERVERUSERPATH),yes)
	SERVERLIBS += -R $(libdir)
endif
endif


# plugins
PLUGINCPPFLAGS = $(BASECPPFLAGS) -I$(top_builddir) -I$(top_builddir)/src/util -I$(top_builddir)/src/server -I$(top_builddir)/src/api/c++ -I$(top_builddir)/src/common $(RUDIMENTSINCLUDES)
PLUGINLIBS = -L$(top_builddir)/src/server -l$(SQLR)server -L$(top_builddir)/src/util -l$(SQLR)util $(RUDIMENTSLIBS) $(EXTRALIBS)
ROUTERPLUGINLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client -L$(top_builddir)/src/server -l$(SQLR)server -L$(top_builddir)/src/util -l$(SQLR)util $(RUDIMENTSLIBS) $(EXTRALIBS)
CONFIGPLUGINLIBS = -L$(top_builddir)/src/util -l$(SQLR)util $(RUDIMENTSLIBS) $(EXTRALIBS)

AUTHCPPFLAGS = $(PLUGINCPPFLAGS) -I$(top_builddir)/src/api/c++
SQLRAUTH_SQLRELAYLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client
SQLRLOGGER_STALECURSORSLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client

ifeq ($(SQLRELAY_ENABLE_SHARED),yes)
INSTALLSHAREDLIB = installsharedlib
else
INSTALLSHAREDLIB =
endif


# connections
CONNECTIONCPPFLAGS = $(BASECPPFLAGS) -I$(top_builddir)/ -I$(top_builddir)/src/common -I$(top_builddir)/src/util -I$(top_builddir)/src/server $(RUDIMENTSINCLUDES)
CONNECTIONLIBS = -L$(top_builddir)/src/server -l$(SQLR)server -L$(top_builddir)/src/util -l$(SQLR)util $(RUDIMENTSLIBS) $(MATHLIB) $(EXTRALIBS)

DB2CONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(DB2INCLUDES)
DB2CONNECTIONLIBS = $(DB2LIBS) $(CONNECTIONLIBS)

FIREBIRDCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(FIREBIRDINCLUDES)
FIREBIRDCONNECTIONLIBS = $(FIREBIRDLIBS) $(CONNECTIONLIBS)

FREETDSCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(FREETDSINCLUDES)
FREETDSCONNECTIONLIBS = $(FREETDSLIBS) $(CONNECTIONLIBS)

INFORMIXCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(INFORMIXINCLUDES)
INFORMIXCONNECTIONLIBS = $(INFORMIXLIBS) $(CONNECTIONLIBS)

MDBTOOLSCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(MDBTOOLSINCLUDES)
MDBTOOLSCONNECTIONLIBS = $(MDBTOOLSLIBS) $(CONNECTIONLIBS)

MYSQLCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(MYSQLINCLUDES)
MYSQLCONNECTIONLIBS = $(MYSQLLIBS) $(CONNECTIONLIBS)

ODBCCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(ODBCINCLUDES) $(ICONVINCLUDES)
ODBCCONNECTIONLIBS = $(ODBCLIBS) $(ICONVLIBS) $(CONNECTIONLIBS)

ORACLECONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(ORACLEINCLUDES)
ORACLECONNECTIONLIBS = $(ORACLELIBS) $(CONNECTIONLIBS)

POSTGRESQLCONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(POSTGRESQLINCLUDES)
POSTGRESQLCONNECTIONLIBS = $(POSTGRESQLLIBS) $(CONNECTIONLIBS)

ROUTERCONNECTIONCPPFLAGS = -I$(top_builddir)/src/api/c++ $(CONNECTIONCPPFLAGS)
ROUTERCONNECTIONLIBS = -L$(top_builddir)/src/api/c++ -l$(SQLR)client $(CONNECTIONLIBS)
ifneq ($(strip $(ROUTERLIBSPATH)),)
ifeq ($(ROUTERUSERPATH),yes)
ROUTERCONNECTIONLIBS += -R $(ROUTERLIBSPATH)
endif
endif

SQLITECONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(SQLITEINCLUDES)
SQLITECONNECTIONLIBS = $(SQLITELIBS) $(CONNECTIONLIBS)

SYBASECONNECTIONCPPFLAGS = $(CONNECTIONCPPFLAGS) $(SYBASEINCLUDES)
SYBASECONNECTIONLIBS = $(SYBASELIBS) $(CONNECTIONLIBS)


# connections
CONNECTIONSALLTARGETS =
CONNECTIONSINSTALLTARGETS =

ifeq ($(strip $(ENABLE_DB2)),yes)
CONNECTIONSALLTARGETS += all-db2
CONNECTIONSINSTALLTARGETS += installsharedlib-db2
endif
ifneq ($(strip $(FREETDSLIBS)),)
CONNECTIONSALLTARGETS += all-freetds
CONNECTIONSINSTALLTARGETS += installsharedlib-freetds
endif
ifneq ($(strip $(FIREBIRDLIBS)),)
CONNECTIONSALLTARGETS += all-firebird
CONNECTIONSINSTALLTARGETS += installsharedlib-firebird
endif
ifeq ($(strip $(ENABLE_INFORMIX)),yes)
CONNECTIONSALLTARGETS += all-informix
CONNECTIONSINSTALLTARGETS += installsharedlib-informix
endif
ifneq ($(strip $(MDBTOOLSLIBS)),)
CONNECTIONSALLTARGETS += all-mdbtools
CONNECTIONSINSTALLTARGETS += installsharedlib-mdbtools
endif
ifneq ($(strip $(MYSQLLIBS)),)
CONNECTIONSALLTARGETS += all-mysql
CONNECTIONSINSTALLTARGETS += installsharedlib-mysql
endif
ifneq ($(strip $(ENABLE_ODBC)),)
ifneq ($(strip $(ODBCLIBS)),)
ifneq ($(strip $(ODBCUNICODE)),)
CONNECTIONSALLTARGETS += all-odbc
CONNECTIONSINSTALLTARGETS += installsharedlib-odbc
endif
endif
endif
ifeq ($(strip $(ENABLE_ORACLE)),yes)
CONNECTIONSALLTARGETS += all-oracle
CONNECTIONSINSTALLTARGETS += installsharedlib-oracle
endif
ifneq ($(strip $(POSTGRESQLLIBS)),)
CONNECTIONSALLTARGETS += all-postgresql
CONNECTIONSINSTALLTARGETS += installsharedlib-postgresql
endif
ifneq ($(strip $(SQLITELIBS)),)
CONNECTIONSALLTARGETS += all-sqlite
CONNECTIONSINSTALLTARGETS += installsharedlib-sqlite
endif
ifeq ($(strip $(ENABLE_SYBASE)),yes)
CONNECTIONSALLTARGETS += all-sap
CONNECTIONSINSTALLTARGETS += installsharedlib-sap
endif
ifneq ($(strip $(ENABLE_ROUTER)),)
CONNECTIONSALLTARGETS += all-router
CONNECTIONSINSTALLTARGETS += installsharedlib-router
endif


# config scripts
INSTALLCONFIG =
ifneq ($(ENABLE_CPP),)
INSTALLCONFIG += install-clientconfig
endif
ifneq ($(ENABLE_SERVER),)
INSTALLCONFIG += install-serverconfig
endif


# tests
TESTALLSUBDIRS = all-dropin all-c all-cpp all-java all-stress all-tcl
ifneq ($(HAVE_MONO),)
	TESTALLSUBDIRS += all-cs
endif

CPPTESTCPPFLAGS = $(BASECPPFLAGS) -I$(includedir) $(RUDIMENTSINCLUDES)
CPPTESTLIBS = -L$(libdir) -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBEFENCE)

CTESTCPPFLAGS = $(BASECPPFLAGS) -I$(includedir) $(RUDIMENTSINCLUDES)
CTESTLIBS = -L$(libdir) -l$(SQLR)client -l$(SQLR)clientwrapper $(RUDIMENTSLIBS) $(LIBEFENCE)

ODBCTESTCPPFLAGS = $(BASECPPFLAGS) -I$(includedir) $(ODBCINCLUDES)
ODBCTESTLIBS = $(RUDIMENTSLIBS) $(ODBCLIBS) $(LIBEFENCE)

DROPTINTESTTARGETS = 
ifneq ($(strip $(MYSQLLIBS)),)
	DROPINTESTTARGETS += mysql
endif
ifneq ($(strip $(POSTGRESQLLIBS)),)
	DROPINTESTTARGETS += postgresql
endif
DROPINTESTCPPFLAGS = $(BASECPPFLAGS) -I$(top_builddir) -I$(includedir) $(RUDIMENTSINCLUDES)
DROPINTESTLIBS = $(RUDIMENTSLIBS)


# bench
BENCHCPPFLAGS = $(BASECPPFLAGS) $(RUDIMENTSINCLUDES) -I$(top_builddir)/src/api/c++
BENCHLIBS = $(RUDIMENTSLIBS) $(EXTRALIBS)


# stress tests
STRESSCPPFLAGS = $(BASECPPFLAGS) -I$(includedir) $(RUDIMENTSINCLUDES)
STRESSLIBS = -L$(libdir) -l$(SQLR)client $(RUDIMENTSLIBS) $(LIBEFENCE)


# docs
ENABLE_DOC = yes


# microsoft-specific
EXE = 


# shared object and module
SOSUFFIX = so
MODULESUFFIX = so
JNISUFFIX = so
MODULERENAME = $(top_builddir)/modulerename.sh


# build directories
INSTALLSUBDIRS = install-src install-bin install-etc install-init install-license
ifeq ($(ENABLE_CPP),yes)
INSTALLSUBDIRS += install-pkgconfig
endif
ifeq ($(ENABLE_DOC),yes)
INSTALLSUBDIRS += install-man install-doc
endif
UNINSTALLSUBDIRS = uninstall-src uninstall-bin uninstall-etc uninstall-init uninstall-license uninstall-pkgconfig uninstall-man uninstall-doc

ifeq ($(SQLRELAY_ENABLE_SHARED),yes)
SRCALLSUBDIRS = all-api
SRCINSTALLSUBDIRS = install-api
ifeq ($(ENABLE_UTIL),yes)
SRCALLSUBDIRS += all-util all-configs
SRCINSTALLSUBDIRS += install-util install-configs
endif
ifeq ($(ENABLE_SERVER),yes)
SRCALLSUBDIRS += all-server all-parsers all-queries all-loggers all-notifications all-schedules all-routers all-protocols all-pwdencs all-auths all-directives all-translations all-bindvariabletranslations all-resultsettranslations all-resultsetrowtranslations all-resultsetrowblocktranslations all-resultsetheadertranslations all-filters all-triggers all-moduledatas all-connections
SRCINSTALLSUBDIRS += install-server install-parsers install-queries install-loggers install-notifications install-schedules install-routers install-protocols install-pwdencs install-auths install-directives install-translations install-bindvariabletranslations install-resultsettranslations install-filters install-triggers install-moduledatas install-connections
endif
else
SRCALLSUBDIRS = all-api
SRCINSTALLSUBDIRS = install-api
ifeq ($(ENABLE_UTIL),yes)
SRCALLSUBDIRS += all-configs all-util
SRCINSTALLSUBDIRS += install-configs install-util
endif
ifeq ($(ENABLE_SERVER),yes)
SRCALLSUBDIRS += all-parsers all-queries all-loggers all-notifications all-schedules all-routers all-protocols all-pwdencs all-auths all-directives all-translations all-bindvariabletranslations all-resultsettranslations all-resultsetrowtranslations all-resultsetrowblocktranslations all-resultsetheadertranslations all-filters all-triggers all-moduledatas all-connections all-server
SRCINSTALLSUBDIRS += install-parsers install-queries install-loggers install-notifications install-schedules install-routers install-protocols install-pwdencs install-auths install-directives install-translations install-bindvariabletranslations install-resultsettranslations install-filters install-triggers install-moduledatas install-connections install-server
endif
endif
ifeq ($(ENABLE_CMDLINE),yes)
SRCALLSUBDIRS += all-cmdline
SRCINSTALLSUBDIRS += install-cmdline
endif


APIALLSUBDIRS =
APICLEANSUBDIRS = clean-cpp clean-c clean-cs clean-mysql clean-postgresql clean-odbc clean-python clean-perl clean-ruby clean-php clean-phppdo clean-java clean-jdbc clean-tcl clean-erlang
APIINSTALLSUBDIRS =
APIUNINSTALLSUBDIRS = uninstall-cpp uninstall-c uninstall-cs uninstall-mysql uninstall-postgresql uninstall-odbc uninstall-java uninstall-jdbc
ifneq ($(ENABLE_CPP),)
APIALLSUBDIRS += all-cpp all-c
APIINSTALLSUBDIRS += install-cpp install-c
endif
ifneq ($(HAVE_MONO),)
APIALLSUBDIRS += all-cs
APIINSTALLSUBDIRS += install-cs
endif
ifeq ($(SQLRELAY_ENABLE_SHARED),yes)
ifeq ($(ENABLE_MYSQL_DROP_IN),yes)
APIALLSUBDIRS += all-mysql
APIINSTALLSUBDIRS += install-mysql
endif
ifeq ($(ENABLE_POSTGRESQL_DROP_IN),yes)
APIALLSUBDIRS += all-postgresql
APIINSTALLSUBDIRS += install-postgresql
endif
ifneq ($(ENABLE_ODBC_DRIVER),)
ifneq ($(ODBCLIBS),)
APIALLSUBDIRS += all-odbc
APIINSTALLSUBDIRS += install-odbc
endif
endif
ifneq ($(HAVE_PYTHON),)
APIALLSUBDIRS += all-python
APIINSTALLSUBDIRS += install-python
APIUNINSTALLSUBDIRS += uninstall-python
endif
ifneq ($(HAVE_PERL),)
APIALLSUBDIRS += all-perl
APIINSTALLSUBDIRS += install-perl
APIUNINSTALLSUBDIRS += uninstall-perl
endif
ifneq ($(HAVE_RUBY),)
APIALLSUBDIRS += all-ruby
APIINSTALLSUBDIRS += install-ruby
APIUNINSTALLSUBDIRS += uninstall-ruby
endif
ifneq ($(HAVE_PHP),)
APIALLSUBDIRS += all-php
APIINSTALLSUBDIRS += install-php
APIUNINSTALLSUBDIRS += uninstall-php
endif
ifneq ($(HAVE_PHP_PDO),)
APIALLSUBDIRS += all-phppdo
APIINSTALLSUBDIRS += install-phppdo
APIUNINSTALLSUBDIRS += uninstall-phppdo
endif
ifneq ($(HAVE_JAVA),)
APIALLSUBDIRS += all-java all-jdbc
APIINSTALLSUBDIRS += install-java install-jdbc
endif
ifneq ($(HAVE_TCL),)
APIALLSUBDIRS += all-tcl
APIINSTALLSUBDIRS += install-tcl
APIUNINSTALLSUBDIRS += uninstall-tcl
endif
ifneq ($(HAVE_ERLANG),)
APIALLSUBDIRS += all-erlang
APIINSTALLSUBDIRS += install-erlang
APIUNINSTALLSUBDIRS += uninstall-erlang
endif
ifneq ($(HAVE_NODEJS),)
APIALLSUBDIRS += all-nodejs
APICLEANSUBDIRS += clean-nodejs
APIINSTALLSUBDIRS += install-nodejs
APIUNINSTALLSUBDIRS += uninstall-nodejs
endif
endif
