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
#define A0 0
#define delay Sleep



void setup();
void loop();

class _Serial {
public:
	void begin(int x);
	//void print(string x);
	//void print(int x);
	//void println(string x);
	//void println(int x);
};

void pinMode(int Pin, string Conector);
void pinMode(int Pin, string Conector);
void digitalWrite(int Pin, bool Value);
int analogRead(int Pin);
