# Communication

## Communication v1
### Create connection
* connect to application (for example telnet 127.0.0.1:5123) 
* You receive Welcome message with aviable options, for example `HELLO;SUPPORT:v1`
* For any action You must authorize with sending `AUTH_REQUEST`
* After confirm on device You will receive `AUTH_SUCCESS`
* Now you can setup your mouse. For v1 you can type `v1rel`. It creates communication v1 with relative positioning mouse 
* After setup You will receive `SETUP_SUCCESS`
* After all, you can type mouse commands

### Commands list:
1. rxN - move mouse X axis for N pixels
2. ryN - move mouse Y axis for N pixels
3. ml1 - start mouse left button press
4. ml0 - end mouse left button press
5. mr1 - start mouse right button press
6. mr0 - end mouse right button press
7. mm1 - start mouse middle button press
8. mm0 - end mouse middle button press