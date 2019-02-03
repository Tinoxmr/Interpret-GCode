/*
* This is the source code for the 'mfunctions'
* Write here the actions you want to execute when a Mcode is called
* Note: P, S, T are passed as int parameters and their default value (meaning they didn't appear in the command) is -2!
* Created:	2/2/2019
* Author:	TinoXMR
*/

#include "mcodefunctions.h"

mcodefunctions::mcodefunctions()
{
}


mcodefunctions::~mcodefunctions()
{
}

void mcodefunctions::M0(int P, int S) {
	
}

void mcodefunctions::M2() {

}

void mcodefunctions::M3(int S) {

}

void mcodefunctions::M4(int S) {

}

void mcodefunctions::M5() {

}

void mcodefunctions::M6(int T) {
	int &tool = T;
	switch (tool) {
	case 0:
	case 1:
	case 2:
	default: break;
	}
}

void mcodefunctions::M7() {

}

void mcodefunctions::M8() {

}

void mcodefunctions::M9() {

}

void mcodefunctions::M10() {

}

void mcodefunctions::M11() {

}

void mcodefunctions::M17() {

}