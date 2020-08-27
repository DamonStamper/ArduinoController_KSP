# Requirements
Hardware for controller (I plan to post BOM and a schematic)
Arduino drivers for your OS

KRPC 0.4.8 (game mod)
kRPC 0.4.8 (Arduino library)

# Gotchas!
## Configuring the KSP kRPC in-game for SerialIO
0. Switch the in-game server to SerialIO not TCP! Per https://www.reddit.com/r/krpc/comments/9lviup/krpc_not_connecting_with_arduino/e7aok6d?utm_source=share&utm_medium=web2x
0. ![](./images/kRPC_HUD_button.png)
0. ![](./images/kRPC_ServerEdit_button.png)
0. ![](./images/kRPC_ServerProtocol_button.png)
0. ![](./images/kRPC_ServerProtocol_Menu_SerialIO.png)
0. You may need to specify a different COM port. 
0. ![](./images/kRPC_ServerEdit_Save.png)

The below is to be done every time you start Kerbal Space Program

0. Ensure the Ardino controller is plugged in.
0. ![](./images/kRPC_HUD_button.png)
0. ![](./images/kRPC_ServerStart_button.png)

## Arduino IDE "avrdude: ser_open(): can't open device "\\.\COMx": Access is denied."
You can't have the kRPC server running at the same time as having the Arduino IDE uploading the sketch. Thus to correct this stop the server in KSP, upload the sketch via the Arduino IDE, then start the server in KSP for testing.

#Process of building up to making your own controller
I started with sketches from https://raw.githubusercontent.com/cardy64/ksp-controller/master/ksp-controller.ino.

# Stages of confirming functionality
0. [Can it connect?](./InitialTesting/CanItConnect/README.md)
0. [Can it send commands, on start?](./InitialTesting/StageOnReset/README.md)
0. [Can it send commands, via button?](./InitialTesting/StageOnReset/README.md)
	* Requires a momentary push button.
	