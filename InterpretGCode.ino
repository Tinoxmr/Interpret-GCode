/*
 Name:		InterpretGCode.ino
 Created:	2/2/2019 3:04:13 PM
 Author:	TinoXMR
*/

#include "src\gcode.h"

String incomingCMD;
gcode g;

void setup() {
	Serial.begin(9600);
}

void loop() {
	if(Serial.available()){
		incomingCMD = Serial.readString();
		g.interpret(incomingCMD);
	}
	Serial.flush(); incomingCMD = "";
}