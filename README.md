ArduinoToaster
==============


Client
==============
This folder contains various clients for the toaster. Their job is to simply send the 
time, in seconds, over a raw socket to port 9001 of the server.

Server
==============
This folder contains the server, which has the job of listening for connections from the
client, and sending the time serially to the Arduino (Toaster).

Toaster
==============
This folder contains the toaster .ino code (labeled as .c for the sake of syntax highlighting).
The Arduino's job is to listen for any serial connections, and operate the motor and
heating element relay accordingly.
