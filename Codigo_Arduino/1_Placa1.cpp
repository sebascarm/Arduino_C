#include "Arduino_PC.h"

enum Modulos 		{ INTERNO, ENC, MCP, THR, MIP, FIR, YOK, MOD_VACIO };
enum Tipos 			{ TEST, LED, DISP, DISP_OFF, DISP_FLASH, SERVO, MOTOR, TIPO_VACIO }; //REVISAR SI SE USA MOTOR
enum TipoIntegrado 	{ Tipo1, Tipo2, Tipo3, Tipo4, Tipo5, Tipo6, Tipo7, Tipo8, Tipo9  };
enum TipoControl 	{ Switch, Pulsador, Llave};

//Incluir todas las clases
#include "Clases\C_Timer.h"
#include "Clases\C_Comunicacion.h"
#include "Clases\C_GrupoChip.h"
#include "Clases\C_MultiLed.h"
#include "Clases\C_Display.h"
#include "Clases\C_Display_Adic.h"
#include "Clases\C_Control.h"
#include "Clases\C_Pote.h"
#include "Clases\C_Transcurrido.h"

//Funciones de loop
String 			PAQUETE; 		//Variable Global donde esta el paquete individual 
C_Comunicacion 	ComSerie;
Modulos 		Modulo;
Tipos 			TipoModulo;

//incluir los modulos
#include "MCP\1_Variables_MCP_LED.ino"
#include "MCP\1_Variables_MCP_OUT.ino"
#include "MCP\2_Inicializacion_MCP_LED.ino"
#include "MCP\2_Inicializacion_MCP_OUT.ino"
#include "MCP\3_Funciones_MCP_LED.ino"
#include "MCP\3_Funciones_MCP_OUT.ino"

C_Transcurrido Transcurrido;

#include "General\Controles.ino"

void setup() {
	Serial.begin(19200);
	//Serial.print("[A00]<MENC_RESET=1>");
	Serial.println("[A00]<MENC_RESET=1>");
	// MODULO MCP
	Inicializacion_MCP_LED();
	Inicializacion_MCP_OUT();
}

void loop() {
	//Control de arribo de datos	
	while (ComSerie.Pendiente == true) {
		PAQUETE		= ComSerie.LeerComando();	
		Modulo		= ComSerie.Modulo();
		TipoModulo	= ComSerie.TipoModulo();

		if (Modulo == INTERNO) { // paquete >1INT_TEST_=1<
			if (Modulo == TEST) {
				Func_INTERNA();
			}
		}

		if (Modulo == MCP) {
			if (TipoModulo == LED)  	  { Func_MCP_LED(); 	}
			if (TipoModulo == DISP) 	  { Func_MCP_DISPLAY(); }
			if (TipoModulo == DISP_FLASH) { Func_MCP_FLASH(); 	}
			if (TipoModulo == DISP_OFF)   { Func_MCP_OFF(); 	}
		}
	}
	Func_MCP_Loop();
	if (GrupoChipLED_MCP.Modificado()){
		GrupoChipLED_MCP.EscribirChips();
	}
	
	//LEctura de datos del simulador y envio
	Func_MCP_OUT(ComSerie);
	// Funciones de loop
	ControlVuelta();
}

//Arribo del puerto serie
void serialEvent() {
	//
	
	ComSerie.EventoSerie();
}

//Incluir las funciones de las Clases
#include "Recursos\C_Timer.ino"
#include "Recursos\C_Comunicacion.ino"
#include "Recursos\C_GrupoChip.ino"
#include "Recursos\C_MultiLed.ino"
#include "Recursos\C_Display.ino"
#include "Recursos\C_Display_Adic.ino"
#include "Recursos\C_Control.ino"
#include "Recursos\C_Pote.ino"
#include "Recursos\C_Transcurrido.ino"