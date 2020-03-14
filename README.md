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
## Can it connect? 
0. Upload https://github.com/cardy64/ksp-controller/blob/cd409729e335bcae6965e7676d88f2ac10e5f1c1/ksp-controller.ino to your Arduno, 
0. Plug the Arduino in, 
0. Start the kRPC server, 
0. Confirm that above the "start" button in kRPC it says "Milo's KSP controller @ COMx". 
	I also noted that the 
		- tx and rx LEDs on the Ardino Nano were flashing rapidly
		- "show info" button in the kRPC window was showing data being read/written to as a constantly changing number
		- the radial button next to "Milo's KSP controller @ COMx" was rapidly changing from green to black.
	![](./images/kRPC_Server_ConnectionEstablished.png)

## Can it send commands?
0. In KSP create a simple rocket with two stages. I used and SRB stage and a parachute stage.  
0. Upload the sketch from ./InitialTesting/StageOnReset/StageOnReset.ino, which is the same as https://github.com/cardy64/ksp-controller/blob/cd409729e335bcae6965e7676d88f2ac10e5f1c1/ksp-controller.ino with the button logic replaced with "true"s.  
	- This ended up resulting in pushing the reset button on the Arduino causing the next stage to be triggered--thus confirming that commands can be sent from the Arduino to KSP via kRPC.