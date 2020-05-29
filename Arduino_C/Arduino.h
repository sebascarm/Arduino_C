#pragma once

#define INPUT "INPUT"
#define OUTPUT "OUTPUT"
#define INPUT_PULLUP "INPUT_PULLUP"
#define LED_BUILTIN 13
#define HIGH 1
#define LOW  0
#define A0 0
#define delay Sleep

void setup();
void loop();

//***************************************
//**** CLASE SERIAL 				 ****
//***************************************
class _Serial {
public:
	void begin(int x);
	//void print(string x);
	//void print(int x);
	//void println(string x);
	//void println(int x);
};

void _Serial::begin(int x) {
	int a = 10;
}

_Serial Serial;


//***************************************
//**** PINMODE 						 ****
//***************************************
void pinMode(int Pin, string Conector) {
	//cout << "PIN: " << Pin << " TIPO: " << Conector << endl;
}
//***************************************
//**** DIGITAL WRITE				 ****
//***************************************
void digitalWrite(int Pin, bool Value) {
	//cout << "> PIN: " << Pin << " " << Value << endl;
}

//***************************************
//**** ANALOG READ					 ****
//***************************************
int analogRead(int Pin) {
	//return atoi(V_INPUT.c_str());
}