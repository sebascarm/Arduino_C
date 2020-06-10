#pragma once

#include "Arduino.h" 

void Inicio() {
	iniciar();
}

void Loop(int ID) {
	OutputDebugString("ADENTRO");
}

//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Boton_Iniciar->Assign_Event_Click(Inicio);
	Text_Loop->Assign_Event_Text_Change_ID(Loop);
	
}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	
}

