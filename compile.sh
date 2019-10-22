#!/bin/bash
./configure; make; make install
cp sqlrelay_frequency.service /etc/systemd/system
cp deleterecent.sh /usr/local/firstworks
systemctl enable sqlrelay_frequency.service
systemctl start sqlrelay_frequency.service
