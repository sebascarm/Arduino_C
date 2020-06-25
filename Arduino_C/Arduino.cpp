#include "Arduino.h"
#include "Funciones.h"
#include <time.h>

#include "WinApi.h"
#include "c_switch.h"
#include "C_Pote.h"
#include "C_ShiftOut.h"
#include "C_ShiftIn.h"

//#include <map>


extern std::vector <Win_Shape*> Pin;
extern Win_MultiLine* Text_SerieIN;
extern Win_MultiLine* Text_SerieOUT;
extern C_Switch CSwitch[3];
extern C_Pote CPote[3];
extern C_ShiftOut CShiftOut[3];
extern C_ShiftIn CShiftIn[3];

//extern Win_TextBox* TextSerial;

extern int		LOOPS;
extern int		DELAY;
extern string	BUFFERSERIE;
extern bool		STOP;

unsigned long tiempo = 0;
clock_t reloj_ini;
clock_t reloj_fin;
clock_t reloj_dif;


void iniciar() {
	//bitest();
	
	Conexiones();

	reloj_ini = clock();
	Text_SerieOUT->Add_Line("SETUP()");
	setup();
	Text_SerieOUT->Add_Line("LOOP()");
	for (int i = 0; i < LOOPS; i++) {
		if (STOP) break;
		loop();
		serialEvent();	// omitir si no esta
		Sleep(DELAY);
	}
	Text_SerieOUT->Add_Line("END()");

}

//*************************************
//*** CLASE SERIAL					***
//*************************************
void _Serial::begin(int x) {
	Text_SerieOUT->Add_Line("BEGIN (" + to_string(x) + ")");
}
//***************************************
void _Serial::print(const char* x) {
	Text_SerieOUT->Add_Text(x);
}
//***************************************
void _Serial::print(String Text){
	Text_SerieOUT->Add_Text(Text.Text);
}
//***************************************
void _Serial::print(int x){
	Text_SerieOUT->Add_Text(to_string(x));
}
//***************************************
void _Serial::println(const char* x){
	Text_SerieOUT->Add_Line(x);
}
//***************************************
void _Serial::println(String Text){
	Text_SerieOUT->Add_Line(Text.Text);
}
//***************************************
void _Serial::println(int x){
	Text_SerieOUT->Add_Line(to_string(x));
}
//***************************************
int _Serial::available(){
	int longitud = BUFFERSERIE.length();
	return longitud;
}
//***************************************
int _Serial::read() {
	int longitud = BUFFERSERIE.length();
	if (longitud) {
		char tmp;
		tmp = BUFFERSERIE.back();
		BUFFERSERIE.resize(BUFFERSERIE.length() - 1);
		return tmp;
	} else {
		return -1;
	}
}

String::String(){
	this->Text = "";
}
String::String(const char* Text) {
	this->Text = Text;
}
String::String(int Text) {
	this->Text = to_string(Text);
}
String::String(const String& Text){
	this->Text = Text.Text;
}

// SOBRECARGA DE OPERADORES
String String::operator=(const String& Text){
	this->Text = Text.Text;
	return *this;
}
String String::operator+(const String& Text){
	String tmp;
	tmp.Text = this->Text + Text.Text;
	return tmp;
}
String& String::operator+=(char Char){
	string tmp = this->Text + Char;
	this->Text = tmp;
	return *this;
}
bool String::operator==(const String& Text){
	if (this->Text == Text.Text) return true;
	else return false;
}

bool String::operator!=(const String& Text){
	if (this->Text != Text.Text) return true;
	else return false;
}
// FUNCIONES
void String::toCharArray(const char* Buffer, int Leng) {
	//falta truncar
	Buffer = Text.c_str();
}
void String::replace(const char* Busqueda, const char* Remplazo){
	Funciones::RemplazarSTR(this->Text, Busqueda, Remplazo);
}
int String::length(){
	return this->Text.length();
}
char String::charAt(int Position){
	return this->Text[Position];
}
int String::indexOf(const String& Buscado, int Pos_ini){
	int pos = this->Text.find(Buscado.Text, Pos_ini);
	if (pos == string::npos) return -1;
	else return pos;
}
String String::substring(int PosIni, int Longitud){
	String tmp;
	tmp.Text = this->Text.substr(PosIni, Longitud);
	return tmp;
}

// funciones con String&
String operator+(const String& Text1, const String& Text2){
	String tmp;
	tmp.Text = Text1.Text + Text2.Text;
	return tmp;
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
	// aveces no se dibuja todo
	//Sleep(1);
}
//***************************************
void digitalWrite(int pin, bool Value) {
	int PinReal = ObtenerPin(pin);
	if (Value) Pin[PinReal]->Set_BackColor(RGB(250, 0, 0));
	else Pin[PinReal]->Set_BackColor(RGB(100, 100, 100));
	// revisamos los shiftout y shiftin
	for (int i = 0; i < 3; i++) {
		if (CShiftOut[i].PinLatch == pin) CShiftOut[i].Input_Latch(Value);
		if (CShiftIn[i].PinLatch == pin) CShiftIn[i].Input_Latch(Value);
		if (CShiftIn[i].PinClock == pin) CShiftIn[i].Input_Clock(Value);
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
	// recorrer Switches y shift in
	for (int i = 0; i < 3; i++) {
		if (CSwitch[i].Pin == pin) Valor = CSwitch[i].State;
		if (CShiftIn[i].PinData == pin) Valor = CShiftIn[i].Get_Data();
	}
	// pintar el pin de entrada
	if (Valor) Pin[PinReal]->Set_BackColor(RGB(0, 250, 0));
	else Pin[PinReal]->Set_BackColor(RGB(100, 100, 100));
	return Valor;
}
//***************************************
int analogRead(int pin) {
	int PinReal = ObtenerPin(pin);
	int Valor = 0;
	int ValColor;
	// recorrer			Potes	
	for (int i = 0; i < 3; i++) {
		if (CPote[i].Pin == pin) {
			Valor = CPote[i].Value;
			ValColor = Funciones::Mapeo(Valor, 0, 1024, 0, 255);
			Pin[PinReal]->Set_BackColor(RGB(0, ValColor, 0));
			
		}
	}
	return Valor;
}

//***************************************
void shiftOut(int dataPin, int clockPin, bool bitOrder, int value){
	int PinRealData  = ObtenerPin(dataPin);
	int PinRealClock = ObtenerPin(clockPin);
	char Char_val	 = value;
	bool Bit_val	 = false;
	bool Clock		 = true;
	// mostramos el pin
	// recorremos 
	for (int i = 0; i < 3; i++) {
		if ((CShiftOut[i].PinData == dataPin) &
			(CShiftOut[i].PinClock == clockPin)) {
			for (int j = 0; j < 8; j++) {
				if (bitOrder) {
					// mostrar el pin de arduino
					if (Bit_val) Pin[PinRealData]->Set_BackColor(RGB(250, 0, 0));
					else Pin[PinRealData]->Set_BackColor(RGB(100, 100, 100));
					// mostrar clock
					if (Clock) {
						Pin[PinRealClock]->Set_BackColor(RGB(250, 0, 0)); Clock = false;
					} else { 
						Pin[PinRealClock]->Set_BackColor(RGB(100, 100, 100)); Clock = true;
					}
					// Asignar valor en 595
					Bit_val = Funciones::Get_Bit(Char_val, j);
					CShiftOut[i].Input_Data(Bit_val);
				}
			}
			Pin[PinRealData]->Set_BackColor(RGB(100, 100, 100));
		}
	}
}


//***************************************
void delayMicroseconds(int Value){
	double Micro = Value / 1000;
	Sleep(Micro);
}
//***************************************
unsigned long millis() {
	reloj_fin = clock();
	reloj_dif = reloj_fin - reloj_ini;
	return (unsigned long)reloj_dif;
}

//***************************************
int map(int Value, int fromLow, int fromHigh, int toLow, int toHigh){
	return Funciones::Mapeo(Value, fromLow, fromHigh, toLow, toHigh);
}

//***************************************
void bitWrite(int &Value, int Bit_Number, bool Bit_Value){
	char Valor = Value;
	Funciones::Bit_Write(Valor, Bit_Number, Bit_Value);
	Value = Valor;
}
void bitWrite(char& Value, char Bit_Number, bool Bit_Value) {
	char Valor = Value;
	Funciones::Bit_Write(Valor, Bit_Number, Bit_Value);
	Value = Valor;
}
//***************************************
bool bitRead(char Value, int Position) {
	return Funciones::Get_Bit(Value, Position);
}

//***************************************
void Conexiones() {
	// recorrer	Switches		
	int pin;
	int PinReal;
	// Primero tenemos q limpiar los pines
	for (int i = 0; i < 3; i++) {
		pin = CSwitch[i].Pin;
		PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(0, 130, 0));
		//Pote
		pin = CPote[i].Pin;
		PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(130, 130, 0));
		// shift out
		pin = CShiftOut[i].PinData;	PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(0, 250, 0));
		pin = CShiftOut[i].PinLatch; PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(250, 150, 0));
		pin = CShiftOut[i].PinClock; PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(250, 250, 0));
		// Shift in
		pin = CShiftIn[i].PinData;	PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(20, 20, 250));
		pin = CShiftIn[i].PinLatch; PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(250, 150, 0));
		pin = CShiftIn[i].PinClock; PinReal = ObtenerPin(pin);
		if (pin > -1) Pin[PinReal]->Set_Color(RGB(250, 250, 0));
	}
	
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

	return 0;
}