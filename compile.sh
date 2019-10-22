#!/bin/bash
rm -f /tmp/recentqueries.log
rm -f /tmp/debugger.txt
/usr/local/firstworks/bin/sqlr-stop -id mssql2test
./configure; make; make install
