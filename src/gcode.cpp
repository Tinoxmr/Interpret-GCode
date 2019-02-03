/*
* This is the source code for the "gcode" library 
* Interpreter function and calls to m and g functions are defined
* Usage: pass the string containing the command to the 'interpret' function from your .ino code
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Created:	2/2/2019
* Author:	TinoXMR
*/

#include "gcode.h"

gcode::gcode()
{
}

gcode::~gcode()
{
}

int gcode::num(char *c, int i) {
	int cnt = 0;
	int n = -1;
	while ((*(c + i) != ' ') && (*(c+i) != '\0')) {
		if (*(c + i) >= 48) {
			if (*(c + i) <= 57) {
				if (cnt == 0) { n++; }
				if (cnt >= 1) { n = n * 10; }
				n += ((*(c + i) - 48));
				cnt++;
			}
		}
		i++;
	}
	return n;
}

double gcode::coord(char *c, int i) {
	int cnt = 0;
	double n = -1;
	int8_t signflag=1;
	while ((*(c + i) != ' ') && (*(c + i) != '\0') && (*(c+i) != '.')) {
		if (*(c + i) == '-') { 
			signflag = -1;  
		}
		else {
			if (*(c + i) >= 48) {
				if (*(c + i) <= 57) {
					if (cnt == 0) { n++; }
					if (cnt >= 1) { n = n * 10; }
					n += ((*(c + i) - 48));
					cnt++;
				}
			}
		}
		i++;
	}
	cnt = 0;
	while ((*(c + i) != ' ') && (*(c + i) != '\0')) {
		double a = 0;
		if (*(c + i) >= 48) {
			if (*(c + i) <= 57) {
				a = ((*(c + i) - 48))*pow(10, --cnt);
				n += a;
			}
		}
		i++;
	}
	return (n*signflag);
}

void gcode::comp(String cmd, int *codes, double *coords) {
	char c[30];
	int i = 0, e = 0;

	strcpy(c, cmd.c_str());
	while (*(c + i) != '\0') {
		if (*(c + i) == 'G' || *(c + i) == 'g') {
			codes[0] = num(c, i + 1);
		}
		if (*(c + i) == 'M' || *(c + i) == 'm') {
			codes[1] = num(c, i + 1);
		}
		if (*(c + i) == 'P' || *(c + i) == 'p') {
			codes[2] = num(c, i + 1);
		}
		if (*(c + i) == 'S' || *(c + i) == 's') {
			codes[3] = num(c, i + 1);
		}
		if (*(c + i) == 'F' || *(c + i) == 'f') {
			codes[4] = num(c, i + 1);
		}
		if (*(c + i) == 'T' || *(c + i) == 't') {
			codes[5] = num(c, i + 1);
		}
		if (*(c + i) == 'X' || *(c + i) == 'x') {
			coords[0] = coord(c, i + 1);
		}
		if (*(c + i) == 'Y' || *(c + i) == 'y') {
			coords[1] = coord(c, i + 1);
		}
		if (*(c + i) == 'Z' || *(c + i) == 'z') {
			coords[2] = coord(c, i + 1);
		}
		if (*(c + i) == 'I' || *(c + i) == 'i') {
			coords[3] = coord(c, i + 1);
		}
		if (*(c + i) == 'J' || *(c + i) == 'j') {
			coords[4] = coord(c, i + 1);
		}
		i++;
	}
}

void gcode::interpret(String cmd) {
	int codes[6] = { -2/*G*/, -2/*M*/, -1/*P*/, -1/*S*/, -1/*F*/, -1/*T*/};
	double coords[5] = { NAN,NAN,NAN,NAN,NAN }; //if no data was passed for a coordinate, we know thanks to NAN operator
	comp(cmd, codes, coords);

	/****Switch G****/
    switch (codes[0]) {
	case 0: gfunction.G0(coords[0]/*X*/, coords[1]/*Y*/, coords[2]/*Z*/, codes[4]/*F*/); break;
	case 1: gfunction.G1(coords[0]/*X*/, coords[1]/*Y*/, coords[2]/*Z*/, codes[4]/*F*/); break;
	case 2: gfunction.G2(coords[0]/*X*/, coords[1]/*Y*/, coords[2]/*Z*/, coords[3] /*I*/, coords[4]/*J*/, codes[4]/*F*/); break;
	case 3: gfunction.G3(coords[0]/*X*/, coords[1]/*Y*/, coords[2]/*Z*/, coords[3] /*I*/, coords[4]/*J*/, codes[4]/*F*/); break;
	case 4: gfunction.G4(codes[2]/*P*/, codes[3]/*S*/); break;
	case 28: gfunction.G28(); break;
	default: break;
	}

	/****Switch M****/
	switch (codes[1]) {
	case 0: mfunction.M0(codes[2]/*P*/, codes[3]/*S*/); break;
	case 2: mfunction.M2(); break;
	case 3: mfunction.M3(codes[3]/*S*/); break;
	case 4: mfunction.M4(codes[3]/*S*/); break;
	case 5: mfunction.M5(); break;
	case 6: mfunction.M6(codes[5]/*T*/); break;
	case 7: mfunction.M7(); break;
	case 8: mfunction.M8(); break;
	case 9: mfunction.M9(); break;
	case 10: mfunction.M10(); break;
	case 11: mfunction.M11(); break;
	case 17: mfunction.M17(); break;
	default: break;
	}
}