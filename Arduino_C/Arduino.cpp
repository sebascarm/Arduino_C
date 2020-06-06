#include "Arduino.h"

#include <time.h>

#include "WinApi.h"
#include "c_switch.h"

extern std::vector <Win_Shape*> Pin;
extern Win_MultiLine* Text_SerieIN;
extern Win_MultiLine* Text_SerieOUT;
extern C_Switch CSwitch[3];

unsigned long tiempo = 0;
clock_t reloj_ini;
clock_t reloj_fin;
clock_t reloj_dif;

void iniciar() {
	reloj_ini = clock();
	Text_SerieOUT->Add_Line("SETUP()");
	setup();
	Text_SerieOUT->Add_Line("LOOP()");
	for (int i = 0; i < 1000; i++) {
		loop();
	}
	Text_SerieOUT->Add_Line("END()");
}


//***************************************
void _Serial::begin(int x) {
	Text_SerieOUT->Add_Line("BEGIN (" + to_string(x) + ")");
}
//***************************************
void _Serial::print(string x) {
}
//***************************************
void _Serial::print(int x){
}
//***************************************
void _Serial::println(string x){
	Text_SerieOUT->Add_Line(x);
}
//***************************************
void _Serial::println(int x){
	Text_SerieOUT->Add_Line(to_string(x));
}
//***************************************
void pinMode(int pin, string Value) {
	int PinReal = ObtenerPin(pin);
	if (pin > 99) {
		Text_SerieOUT->Add_Line("PIN (A" + to_string(pin-100) + ") = " + Value);
	} else {
		Text_SerieOUT->Add_Line("PIN (" + to_string(pin) + ") = " + Value);
	}
	if (Value == "INPUT") {
		Pin[PinReal]->Set_BackColor(RGB(100, 150, 100));
	} else {
		Pin[PinReal]->Set_BackColor(RGB(150, 100, 100));
	}
}
//***************************************
void digitalWrite(int pin, bool Value) {
	int PinReal = ObtenerPin(pin);
	if (Value) {
		Pin[PinReal]->Set_BackColor(RGB(250, 0, 0));
	}
	else {
		Pin[PinReal]->Set_BackColor(RGB(100, 100, 100));
	}
}
//***************************************
void analogWrite(int pin, int Value) {
	int PinReal = ObtenerPin(pin);
	if (Value) {
		Pin[PinReal]->Set_BackColor(RGB(Value, 0, 0));
	}
	
}

//***************************************
int digitalRead(int pin) {
	int PinReal = ObtenerPin(pin);
	int Valor = 0;
	// recorrer			Switches
	for (int i = 0; i < 3; i++) {
		if (CSwitch[i].Pin == pin) {
			Valor = CSwitch[i].State;
		}
	}
	return Valor;
}
//***************************************
int analogRead(int pin) {
	return 0;
}
//***************************************
unsigned long millis() {
	reloj_fin = clock();
	reloj_dif = reloj_fin - reloj_ini;
	return (unsigned long)reloj_dif;
}

//***************************************
int ObtenerPin(int Pin) {
	if (Pin == 0) return 16;
	if (Pin == 1) return 18;
	if (Pin == 2) return 20;
	if (Pin == 3) return 22;
	if (Pin == 4) return 24;
	if (Pin == 5) return 26;
	if (Pin == 6) return 28;
	if (Pin == 7) return 30;
	
	if (Pin == 100) return 31;
	if (Pin == 101) return 29;
	if (Pin == 102) return 27;
	if (Pin == 103) return 25;
	if (Pin == 104) return 23;
	if (Pin == 105) return 21;
	if (Pin == 106) return 19;
	if (Pin == 107) return 17;
	
	if (Pin == 8) return 32;
	if (Pin == 9) return 33;
	if (Pin == 10) return 34;
	if (Pin == 11) return 35;
	if (Pin == 12) return 36;
	if (Pin == 13) return 37;
	
	if (Pin == 14) return 14;
	if (Pin == 15) return 12;
	if (Pin == 16) return 10;
	if (Pin == 17) return 8;
	if (Pin == 18) return 6;
	if (Pin == 19) return 4;
	if (Pin == 20) return 2;
	if (Pin == 21) return 0;
	
	if (Pin == 108) return 15;
	if (Pin == 109) return 13;
	if (Pin == 110) return 11;
	if (Pin == 111) return 9;
	if (Pin == 112) return 7;
	if (Pin == 113) return 5;
	if (Pin == 114) return 3;
	if (Pin == 115) return 1;
		
	if (Pin == 22) return 53;
	if (Pin == 23) return 52;
	if (Pin == 24) return 55;
	if (Pin == 25) return 54;
	if (Pin == 26) return 57;
	if (Pin == 27) return 56;
	if (Pin == 28) return 59;
	if (Pin == 29) return 58;
	if (Pin == 30) return 61;
	if (Pin == 31) return 60;
	if (Pin == 32) return 63;
	if (Pin == 33) return 62;
	if (Pin == 34) return 65;
	if (Pin == 35) return 64;
	if (Pin == 36) return 67;
	if (Pin == 37) return 66;
	if (Pin == 38) return 69;
	if (Pin == 39) return 68;
	if (Pin == 40) return 71;
	if (Pin == 41) return 70;
	if (Pin == 42) return 73;
	if (Pin == 43) return 72;
	if (Pin == 44) return 75;
	if (Pin == 45) return 74;
	if (Pin == 46) return 77;
	if (Pin == 47) return 76;
	if (Pin == 48) return 79;
	if (Pin == 49) return 78;
	if (Pin == 50) return 81;
	if (Pin == 51) return 80;
	if (Pin == 52) return 83;
	if (Pin == 53) return 82;

}