
#include "Arduino_PC.h"


String inputString = "a";         // a String to hold incoming data

//String a("a");
//string c = "a";
//String b = c;
//String d = "as";

boolean stringComplete = false;  // whether the string is complete

void Escribir(int F_Pin, float F_Posicion, int (*F_Mapeo)(float));
void MoverServo(int F_Pin, int F_Angulo, int F_Envios = 10); // Declaracion de parametro opcional
const int PinServo = 8;
float Posicion;


int MapFloat(float x, float in_min, float in_max, int out_min, int out_max);
float StringtoFloat(String SValor);
int MapeoServo1(float F_Valor);

/******************************************************/
/****       INICIALIZACION                         ****/
/******************************************************/
void setup() {
    Serial.begin(19200);
    Serial.println(">RESET<");
    pinMode(PinServo, OUTPUT);
}
/******************************************************/
/****       LOOP                                   ****/
/******************************************************/
void loop()
{
    if (stringComplete) {
        Posicion = StringtoFloat(inputString);
        inputString = "";
        stringComplete = false;
        Serial.print("Posicion leida: ");
        Serial.println(Posicion);
        /* Puntero */
        int (*F_Puntero) (float);
        F_Puntero = MapeoServo1;
        /* Llamar a la funcion con puntero */
        Escribir(PinServo, Posicion, F_Puntero);
        delay(50);
        Serial.println("INGRESE EL ANGULO SERVO");
    }
}

/******************************************************/
/****       FUNCION ESCRIBIR                       ****/
/******************************************************/
void Escribir(int F_Pin, float F_Posicion, int (*F_Mapeo)(float)) {
    int F_AnguloReal;
    /* DETERMINAMOS EL ANGULO       */
    F_AnguloReal = (*F_Mapeo)(F_Posicion);
    /* MOVER SERVO*/
    MoverServo(F_Pin, F_AnguloReal, 3);
}

/******************************************************/
/****       MOVIMIENTO REAL DEL SERVO              ****/
/******************************************************/
void MoverServo(int F_Pin, int F_Angulo, int F_Envios) {
    int vuelta;
    float pausa;
    Serial.println(F_Envios);
    pausa = F_Angulo * 2000.0 / 180.0 + 500;
    for (vuelta = 0; vuelta < F_Envios; vuelta += 1) {
        digitalWrite(F_Pin, HIGH);
        delayMicroseconds(pausa);
        digitalWrite(F_Pin, LOW);
        delayMicroseconds(10000 - pausa);
    }
}
/***********************************************************/
/****        FUNCION QUE DEVUELVE EL VALOR A APLICAR    ****/
/***********************************************************/
int MapeoServo1(float F_Valor) {
    int F_Result;
    if (F_Valor < 0) { F_Result = 19; }
    else if (F_Valor < 1) { F_Result = MapFloat(F_Valor, 0, 1, 19, 28); }
    else if (F_Valor < 2) { F_Result = MapFloat(F_Valor, 1, 2, 29, 41); }
    else if (F_Valor < 5) { F_Result = MapFloat(F_Valor, 2, 5, 42, 54); }
    else if (F_Valor < 10) { F_Result = MapFloat(F_Valor, 5, 10, 55, 64); }
    else if (F_Valor < 15) { F_Result = MapFloat(F_Valor, 10, 15, 65, 70); }
    else if (F_Valor < 25) { F_Result = MapFloat(F_Valor, 15, 25, 71, 77); }
    else if (F_Valor < 30) { F_Result = MapFloat(F_Valor, 25, 30, 78, 85); }
    else if (F_Valor < 40) { F_Result = MapFloat(F_Valor, 30, 40, 86, 93); }
    else { F_Result = 94; }
    return F_Result;
}

// ***********************************************************************************
// ****        FUNCION - MAP FLOAT ENTRADA INT SALIDA                             ****
// ***********************************************************************************
int MapFloat(float x, float in_min, float in_max, int out_min, int out_max) {
    float Resultado;
    Resultado = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    return (int)Resultado;
}

/************************************************************************************/
// ****        FUNCION - STRING A FLOAT                                           ****
/************************************************************************************/
float StringtoFloat(String SValor) {
    float Resultado;
    char CHValorllegar[7];
    SValor.toCharArray(CHValorllegar, 7);
    Resultado = atof(CHValorllegar);
    return Resultado;
}
// ***********************************************************************************
// ****        PROCEDIMIENTO - ARRIBO DE DATOS DEL PUERTO SERIE                   ****
// ***********************************************************************************

void serialEvent() {
    while (Serial.available()) {
        stringComplete = false;
        char inChar = (char)Serial.read();
        //inputString += "a";
        inputString += inChar;
        if (inChar == '\n') {
            stringComplete = true;
        }
    }
}