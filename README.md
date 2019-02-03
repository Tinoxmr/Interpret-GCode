### Interpret-GCode
A simple, light, ISO G-Code interpreter for Arduino, with customizable G and M routines.

**Warning: this is still a very primitive version of the project, so contains a bunch of bugs. Yet the calls to the simpler M-code routines should work fine**

The code executed upon calling a G or M function is customizable. For example:
```
void gcodefunctions::G0(double X, double Y, double Z, int F) {
  .
  .
  .
}
```
This is the function called when the Arduino reads G0, followed by its parameters X Y Z F, from the Serial. You can find this in the file *gcodefunctions.cpp* and fill it with the code you want to execute when G0 is read.
Analogously, you can edit M routines in the file *mcodefunctions.cpp*
