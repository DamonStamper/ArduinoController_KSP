/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/
  const int RightPitch = A6;
  const int RightYaw = A7;
  const int RightRoll = A2;
  const int LeftPitch = A3;
  const int LeftYaw = A4;
  const int LeftRoll = A5;

  int RightPitchVal;
  int RightYawVal;
  int RightRollVal;
  int LeftPitchVal;
  int LeftYawVal;
  int LeftRollVal;
  
void setup() {
  pinMode(RightPitch, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  RightPitchVal = analogRead(RightPitch);
  RightYawVal = analogRead(RightYaw);
  RightRollVal = analogRead(RightRoll);
  LeftPitchVal = analogRead(LeftPitch);
  LeftYawVal = analogRead(LeftYaw);
  LeftRollVal = analogRead(LeftRoll);
  
  Serial.print("RightPitchVal: ");
  Serial.print(RightPitchVal);
  
  Serial.print("   RightYawVal: ");
  Serial.print(RightYawVal);
  
  Serial.print("   RightRollVal: ");
  Serial.print(RightRollVal);
  
  
  Serial.print("   LeftPitchVal: ");
  Serial.print(LeftPitchVal);
  
  Serial.print("   LeftYawVal: ");
  Serial.print(LeftYawVal);
  
  Serial.print("   LeftRollVal: ");
  Serial.print(LeftRollVal);
  
  Serial.println("");
  delay(500);
}
