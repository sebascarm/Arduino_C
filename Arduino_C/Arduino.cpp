#include "Arduino.h"

#include "WinApi.h"

extern std::vector <Win_Shape*> Pin;

void _Serial::begin(int x) {
	int a = 10;
}


//***************************************
//**** PINMODE 						 ****
//***************************************
void pinMode(int Pin, string Conector) {
	//cout << "PIN: " << Pin << " TIPO: " << Conector << endl;
}
//***************************************
//**** DIGITAL WRITE				 ****
//***************************************
void digitalWrite(int pin, bool Value) {
	
	Pin[pin]->Set_BackColor(RGB(100, 100, 100));
	


}

//***************************************
//**** ANALOG READ					 ****
//***************************************
int analogRead(int Pin) {
	//return atoi(V_INPUT.c_str());
	return 0;
}
