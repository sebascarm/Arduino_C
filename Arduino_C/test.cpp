#include "Arduino_PC.h"

//**************************************************************//
//  Notes   : Code for using a 74HC595 Shift Register           //
//  FEUDRINO : COM 4
//****************************************************************
int PINDataLED = 22;
int PINLatchLED = 24;
int PINClockLED = 26;

int CHIP_LEDS1 = 0;

void EnviaraPlaca();

void setup() {
    //set pins to output so you can control the shift register
    pinMode(PINDataLED, OUTPUT);
    pinMode(PINLatchLED, OUTPUT);
    pinMode(PINClockLED, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < 8; i++) {
        bitWrite(CHIP_LEDS1, i, 1);
        EnviaraPlaca();
        delay(1000);
    }
    for (int i = 0; i < 8; i++) {
        bitWrite(CHIP_LEDS1, i, 0);
        EnviaraPlaca();
        delay(1000);
    }
}

void EnviaraPlaca() {
    digitalWrite(PINLatchLED, LOW);
    shiftOut(PINDataLED, PINClockLED, MSBFIRST, CHIP_LEDS1);
    //shiftOut(PINDataLED, PINClockLED, MSBFIRST, CHIP_LEDS2);
    //shiftOut(PINDataLED, PINClockLED, MSBFIRST, CHIP_LEDS3);
    digitalWrite(PINLatchLED, HIGH);
}
