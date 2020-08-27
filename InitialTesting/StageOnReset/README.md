0. Plug the Arduino in, 
0. Upload the [StageOnReset.ino](StageOnReset.ino) sketch,
0. In KSP create a simple rocket with a stage.
0. Start the kRPC server, 
0. Confirm that above the "start" button in kRPC it says "KSP controller @ COMx". 
	I also noted that the 
		- tx and rx LEDs on the Ardino Nano were flashing rapidly
		- "show info" button in the kRPC window was showing data being read/written to as a constantly changing number
		- the radial button next to "KSP controller @ COMx" was rapidly changing from green to black.
	![](../images/kRPC_Server_ConnectionEstablished.png)
0. Press the reset button on the Arduio,
0. Wait roughly 4 seconds (let the Arduino boot after the reset),
0. Observe that the next stage is triggered.