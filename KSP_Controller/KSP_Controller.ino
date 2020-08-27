#include <krpc.h>
#include <krpc/services/krpc.h>
#include <krpc/services/space_center.h>

HardwareSerial * conn;

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
  

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  conn = &Serial;
  // Open the serial port connection
  krpc_open(&conn, 'COM4');
  // Set up communication with the server
  krpc_connect(conn, "Arduino Example");

  // Indicate succesful connection by lighting the on-board LED
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  RightPitchVal = analogRead(RightPitch);
  RightYawVal = analogRead(RightYaw);
  RightRollVal = analogRead(RightRoll);
  LeftPitchVal = analogRead(LeftPitch);
  LeftYawVal = analogRead(LeftYaw);
  LeftRollVal = analogRead(LeftRoll);
  
  krpc_connect(conn, "Remote Procedures example");

  krpc_SpaceCenter_Vessel_t vessel; //declare variable of type vessel
  krpc_SpaceCenter_ActiveVessel(conn, &vessel); //get active vessel from connection conn and assign the vessel to the address (hence &) of the variable vessel.

  krpc_SpaceCenter_AutoPilot_t control;
  krpc_SpaceCenter_Vessel_Control(conn, &control, vessel);
  
  krpc_SpaceCenter_Control_ActivateNextStage(conn, vessel, control);
  
  //rocket = ksc.active_vessel
  //rocket.control.activate_next_stage()
}
