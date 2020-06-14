#pragma once

#include "Arduino.h" 
#include "Funciones.h"


void Inicio() {
	STOP = false;
	iniciar();
}
void Stop() {
	STOP = true;
}
void Pausar() {

}

void Coneccion() {
	Conexiones();
}

void Loop(int ID) {
	string Loops = Text_Loop->Get_Text();
	LOOPS = Funciones::To_Integer(Loops);
}
void Delay(int ID) {
	string Retardo = Text_Delay->Get_Text();
	DELAY = Funciones::To_Integer(Retardo);
}
void TextSerial(int ID) {
	string Texto;
	char TextoCh;
	Texto = Text_Serial->Get_Text();
	if (Texto.length() > 0) {
		TextoCh = Text_Serial->Get_Text().back();
		BUFFERSERIE = BUFFERSERIE + TextoCh;
		if (TextoCh == '\n') {
			Text_SerieIN->Add_Line(Texto);
			Text_Serial->Set_Text("");
		}
	}
}


//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Boton_Iniciar->Assign_Event_Click(Inicio);
	Boton_Parar->Assign_Event_Click(Stop);
	Boton_Pausa->Assign_Event_Click(Pausar);
	Boton_Conectar->Assign_Event_Click(Coneccion);
	Text_Loop->Assign_Event_Text_Change_ID(Loop);
	Text_Delay->Assign_Event_Text_Change_ID(Delay);
	Text_Serial->Assign_Event_Text_Change_ID(TextSerial);
	
}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	
}
