#pragma once

#include "Arduino.h" 



void Iniciar() {
	Pin[0]->Set_BackColor(RGB(250, 0, 0));
}


//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Boton_Iniciar->Assign_Event_Click(Iniciar);
	
}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	
}

