/*
* This is the source code for the gfunctions
* Write here the actions you want to execute when a Gcode is called
* Note: P, S, T, F are passed as int parameters and their default value (meaning they didn't appear in the command) is -2!
* Created:	2/2/2019
* Author:	TinoXMR
*/

#include "gcodefunctions.h"
#include "Arduino.h"

gcodefunctions::gcodefunctions()
{
}


gcodefunctions::~gcodefunctions()
{
}

/*
* NOTE: if no value was read for a coordinate, NaN is returned on that coordinate
* If no value is read for P, S, F, -1 is returned
* If no value is read for T, -1 is returned
*/

void gcodefunctions::G0(double X, double Y, double Z, int F) {
	Serial.print("G0 XYZ - Feedrate: "); Serial.print(X); Serial.print(" "); Serial.print(Y); Serial.print(" "); Serial.print(Z); Serial.print(" "); Serial.println(F);
}

void gcodefunctions::G1(double X, double Y, double Z, int F) {
	
}

void gcodefunctions::G2(double X, double Y, double Z, double I, double J, int F) {

}

void gcodefunctions::G3(double X, double Y, double Z, double I, double J, int F) {

}

void gcodefunctions::G4(int P, int S) {

}

void gcodefunctions::G28() {

}