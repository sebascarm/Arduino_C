#pragma once

#include <Windows.h>  // Para sleep
#include <string>

using namespace std;


#define INPUT "INPUT"
#define OUTPUT "OUTPUT"
#define INPUT_PULLUP "INPUT_PULLUP"
#define LED_BUILTIN 13
#define HIGH 1
#define LOW  0
#define A0 100
#define A1 101
#define A2 102
#define A3 103
#define A4 104
#define A5 105
#define A6 106
#define A7 107
#define A8 108
#define A9 109
#define A10 110
#define A11 111
#define A12 112
#define A13 113
#define A14 114
#define A15 115

#define delay	Sleep

#define MSBFIRST true
#define LSBFIRST false

#define byte char


void iniciar();

void setup();
void loop();
void serialEvent();

int ObtenerPin(int Pin);
void Conexiones();

class String;

class _Serial {
public:
	void begin(int x);
	void print(const char* x);
	void print(String Text);
	void print(int x);
	void println(const char* x);
	void println(String Text);
	void println(int x);

	int	 available();
	int read();
};



class String {
public:
	
	String();
	String(const char*);
	String(int Text);
	String(const String&);

	String	operator = (const String&);
	String	operator + (const String&);
	
	String&	operator += (char Char);
	//bool	operator == (const char*);			// Para comparar igualdad
	bool	operator == (const String& Text);	// Para comparar igualdad
	bool	operator != (const String& Text);	// Para comparar diferencia
	//bool	operator != (const char*);			// Para comparar diferencia
		
	void	toCharArray(const char* Buffer, int Leng);
	void	replace(const char* Busqueda, const char* Remplazo);
	int		length();
	char	charAt(int Position);
	int		indexOf(const String& Buscado, int Pos_ini=0);
	String substring(int PosIni, int Longitud = 1);
	
	string Text;

	//String operator+=(const String&);
};
String operator +(const String& Text1, const String& Text2);  // Para la suma en una asignacion con comillas


//DIGITAL I/O					
int		digitalRead(int Pin);
void	digitalWrite(int Pin, bool Value);
void	pinMode(int Pin, string Conector);
//ANALOG I/O					
int		analogRead(int Pin);
void	analogWrite(int pin, int Value);

//Advanced I / O				
//	noTone()		
//	pulseIn()		
//	pulseInLong()	
//	shiftIn()		
void shiftOut(int dataPin, int clockPin, bool bitOrder,int value);
//	shiftOut()		
//	tone()			

//Time							
//	delay()				
void delayMicroseconds(int Value);
//	micros()			
unsigned long millis();

//Math							
//	abs()		
//	constrain()	
int	map(int Value, int fromLow, int fromHigh, int toLow, int toHigh);
//	max()		
//	min()		
//	pow()		
//	sq()		
//	sqrt()		

//Trigonometry					
//	cos()
//	sin()
//	tan()

//Characters					
//	isAlpha()
//	isAlphaNumeric()
//	isAscii()
//	isControl()
//	isDigit()
//	isGraph()
//	isHexadecimalDigit()
//	isLowerCase()
//	isPrintable()
//	isPunct()
//	isSpace()
//	isUpperCase()
//	isWhitespace()

//Random Numbers				
//	random()
//	randomSeed()

//Bitsand Bytes
//	bit()
//	bitClear()
bool bitRead(char Value, int Position);
//	bitSet()
//	void bitWrite(int &Value, int Bit_Number, bool Bit_Value);
void bitWrite(char& Value, char Bit_Number, bool Bit_Value);
//	highByte()
//	lowByte()

//External Interrupts			
//	attachInterrupt()
//	detachInterrupt()
//	Interrupts
//	interrupts()
//	noInterrupts()

//Communication					
//	Serial
//	Stream
//	USB
//	Keyboard
//	Mouse






