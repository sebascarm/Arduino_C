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

#define delay Sleep

void iniciar();

void setup();
void loop();

class _Serial {
public:
	void begin(int x);
	void print(string x);
	void print(int x);
	void println(string x);
	void println(int x);
};

void pinMode(int Pin, string Conector);
void pinMode(int Pin, string Conector);
void digitalWrite(int Pin, bool Value);
void analogWrite(int pin, int Value);
int digitalRead(int Pin);
int analogRead(int Pin);

unsigned long millis();

int ObtenerPin(int Pin);