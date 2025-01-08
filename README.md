# Remote-mouse
Remote mouse/touchpad/graphics tablet input for linux

## Communication v1
### Create connection
* connect to application (for example telnet 127.0.0.1:5123) 
* You receive Welcome message with aviable options, for example `HELLO;SUPPORT:v1`
* For any action You must authorize with sending `AUTH_REQUEST`
* After confirm on device You should receive `SETUP_SUCCESS`
* Now you can setup your mouse. For v1 you can type `v1rel`. It creates communication v1 with relativ positioning mouse 
* After all, you can type commands
### Commands list:
1. rxN - move mouse X axys for n
2. ryN - move mouse Y axys for n
3. ml1 - start mouse left button press
4. ml2 - end mouse left button press

## Build
To build: 
1. `git clone https://github.com/CatInBeard/remote-mouse/`
2. `cd remote-mouse`
3. `cd src`
4. `make`