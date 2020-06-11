#pragma once

#include "Arduino.h" 
#include "Funciones.h"


void Inicio() {
	iniciar();
}
void Stop() {

}
void Loop(int ID) {
	string Loops = Text_Loop->Get_Text();
	LOOPS = Funciones::To_Integer(Loops);
}
void Delay(int ID) {
	string Retardo = Text_Delay->Get_Text();
	DELAY = Funciones::To_Integer(Retardo);
}

//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Boton_Iniciar->Assign_Event_Click(Inicio);
	Boton_Parar->Assign_Event_Click(Stop);
	Text_Loop->Assign_Event_Text_Change_ID(Loop);
	Text_Delay->Assign_Event_Text_Change_ID(Delay);
}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	
}

