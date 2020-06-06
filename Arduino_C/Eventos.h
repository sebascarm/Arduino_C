#pragma once

#include "Arduino.h" 

void Inicio() {
	iniciar();
}

//******************************************************************//
//**** ASIGNACION DE EVENTOS									****//
//******************************************************************//

void  Eventos() {
	Boton_Iniciar->Assign_Event_Click(Inicio);
	
}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	
}

