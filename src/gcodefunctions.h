#pragma once

class gcodefunctions
{
public:
	gcodefunctions();
	~gcodefunctions();

	void G0(double X, double Y, double Z, int F);
	void G1(double X, double Y, double Z, int F);
	void G2(double X, double Y, double Z, double I, double J, int F);
	void G3(double X, double Y, double Z, double I, double J, int F);
	void G4(int P, int S);
	void G28();
};