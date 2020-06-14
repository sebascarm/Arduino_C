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

void iniciar();

void setup();
void loop();
void serialEvent();


int ObtenerPin(int Pin);
void Conexiones();


class _Serial {
public:
	void begin(int x);
	void print(string x);
	void print(int x);
	void println(string x);
	void println(int x);

	int	 available();
	int read();
};




class String {
private:
	string Text;
public:
	String();
	String(string Text);
	String(const char* Text);
	String& operator = (const char* Text);
	String& operator += (char Char);
	void toCharArray(const char* Buffer, int Leng);
};



//DIGITAL I/O					
int		digitalRead(int Pin);
void	digitalWrite(int Pin, bool Value);
void	pinMode(int Pin, string Conector);
//ANALOG I/O					
int analogRead(int Pin);
void analogWrite(int pin, int Value);

//Advanced I / O				
//	noTone()		
//	pulseIn()		
//	pulseInLong()	
//	shiftIn()		
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
//	bitRead()
//	bitSet()
void bitWrite(int &Value, int Bit_Number, bool Bit_Value);
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






