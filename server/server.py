#!/usr/bin/env python2
# -*- coding: utf-8 -*-
'''
Copyright (C) 2014 
     
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or 
    (at your option) any later version. 
 
    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
    GNU General Public License for more details. 
 
    You should have received a copy of the GNU General Public License 
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
'''

import serial
import socket
import logging
import sys
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

host = ''
port = 9001
size = 1024
backlog = 5

def int_to_list(num):
    return list ("%05d" % num)

def sendTimeOverSerial(time):
    ser.write(chr(time))


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((host,port))
s.listen(backlog)
while 1:
    try:
        client, address = s.accept()
        data = client.recv(size)
        if data:
            sendTimeOverSerial(int(data))
            client.send("Toasting. \n")
            time.sleep(float(data))
            print "successfully waited ", data, " seconds"
        client.close()
        print "Client DCed"
    except KeyboardInterrupt:
        print "Closing due to C-c.."
        sys.exit()
