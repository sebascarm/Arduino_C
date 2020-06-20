#include "Arduino_PC.h"

//**************************************************************//
//  Notes   : Code for using a 74HC595 Shift Register           //
//  FEUDRINO : COM 4
//****************************************************************

const int PINDataIN_XX = 23;   //Pin connected to ST_CP of D  // Variables de PIN comenzar con PINxxx
const int PINLatchIN_XX = 25;
const int PINClockIN_XX = 27;


byte SwitchVar1_XX = 72;  //01001000 
//byte SwitchVar2_XX = 159; //10011111


int Switch_XX;

byte shiftIn(int myDataPin, int myClockPin); 
void P_XXX_CararChipaVariable();

void setup() {
    // ************************************************************************************
    // ****        INICIALIZACION - SWITCH Y BOTONES  (OUTPUT)                         ****
    // ************************************************************************************
    pinMode(PINLatchIN_XX, OUTPUT);   // 
    pinMode(PINClockIN_XX, OUTPUT);
    pinMode(PINDataIN_XX, INPUT);
    

    Serial.begin(9600);
}

void loop() {
    P_XXX_CararChipaVariable();
  //  for (int i = 0; i < 8; i++) {
  //     Switch_XX = bitRead(SwitchVar2_XX, i);
  //     Serial.print(" VAR ");
  //      Serial.print(i);
  //      Serial.print(": ");
  //      Serial.print(Switch_XX);
  //  }
 //   Serial.println("CHIP2");
    for (int i = 0; i < 8; i++) {
        //Switch_XX = bitRead(SwitchVar1_XX, i);
        Serial.print(" VAR ");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(Switch_XX);
    }
    Serial.println(" CHIP1");
    delay(1);
}

void P_XXX_CararChipaVariable() {
    digitalWrite(PINLatchIN_XX, 1);
    delayMicroseconds(10); //Pasar a 20 si no se reciben bien los datos
    digitalWrite(PINLatchIN_XX, 0);
    //SwitchVar2_XX = shiftIn(PINDataIN_XX, PINClockIN_XX);
    SwitchVar1_XX = shiftIn(PINDataIN_XX, PINClockIN_XX);

}

// *******************************************************************************************
// ****        FUNCION: LECTURA DE CHIP IN                                                ****
// *******************************************************************************************
byte shiftIn(int myDataPin, int myClockPin) {
    int i;
    int temp = 0;
    int pinState;
    byte myDataIn = 0;

    for (i = 7; i >= 0; i--) {
        digitalWrite(myClockPin, 0);
        delayMicroseconds(2);
        temp = digitalRead(myDataPin);
        if (temp) {
            pinState = 1;
            myDataIn = myDataIn | (1 << i);
        }
        else {
            pinState = 0;
        }
        digitalWrite(myClockPin, 1);
    }
    return myDataIn;
}