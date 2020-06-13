#include "Arduino_PC.h"
// la funcion void serialEvent() debe existir o omitir en Arduino.cpp


const int analogInPin1 = A6;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A7;  // Analog input pin that the potentiometer is attached to

int sensorValue1 = 0;        // value read from the pot
int sensorValue2 = 0;        // value read from the pot

void setup() {
	// initialize serial communications at 9600 bps:
	Serial.begin(9600);
}

void loop() {
	// read the analog in value:
	sensorValue1 = analogRead(analogInPin1);
	sensorValue2 = analogRead(analogInPin2);
	// map it to the range of the analog out:

	// print the results to the serial monitor:
	Serial.print("sensor1 = ");
	Serial.print(sensorValue1);
	Serial.print(" sensor2 = ");
	Serial.println(sensorValue2);

	delay(100);
}


