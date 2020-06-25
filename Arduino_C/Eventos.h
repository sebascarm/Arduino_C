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
void Guardar() {
	for (int i = 0; i < 3; i++) {
		ARCHIVO->Change_Parameter("SW" + to_string(i), to_string(CSwitch[i].Pin));
		ARCHIVO->Change_Parameter("PO" + to_string(i), to_string(CPote[i].Pin));
		ARCHIVO->Change_Parameter("595_DATA_" + to_string(i), to_string(CShiftOut[i].PinData));
		ARCHIVO->Change_Parameter("595_LATCH_" + to_string(i), to_string(CShiftOut[i].PinLatch));
		ARCHIVO->Change_Parameter("595_CLOCK_" + to_string(i), to_string(CShiftOut[i].PinClock));
	}
	for (int i = 0; i < 18; i++) {
		ARCHIVO->Change_Parameter("595_MDATA_" + to_string(i), to_string(MShiftOut[i].PinData));
		ARCHIVO->Change_Parameter("595_MLATCH_" + to_string(i), to_string(MShiftOut[i].PinLatch));
		ARCHIVO->Change_Parameter("595_MCLOCK_" + to_string(i), to_string(MShiftOut[i].PinClock));
	}
	ARCHIVO->Save("Config.cfg");
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
	Boton_Guardar->Assign_Event_Click(Guardar);
	Text_Loop->Assign_Event_Text_Change_ID(Loop);
	Text_Delay->Assign_Event_Text_Change_ID(Delay);
	Text_Serial->Assign_Event_Text_Change_ID(TextSerial);

}


//******************************************************************//
//**** Configuracion de objetos									****//
//******************************************************************//

void Configurar_objetos() {
	ARCHIVO->Load("Config.cfg");
	string Parametro;
	string Valor;
	for (int i = 0; i < 3; i++) {
		//Switch
		Parametro = "SW" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		CSwitch[i].Set_Pin(Valor);
		//Pote
		Parametro = "PO" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		CPote[i].Set_Pin(Valor);
		//595
		Parametro = "595_DATA_" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		CShiftOut[i].Set_Pin_Data(Valor);
		Parametro = "595_LATCH_" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		CShiftOut[i].Set_Pin_Latch(Valor);
		Parametro = "595_CLOCK_" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		CShiftOut[i].Set_Pin_Clock(Valor);
		// 4021
		
	};
	for (int i = 0; i < 18; i++) {
		//595
		Parametro = "595M_DATA_" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		MShiftOut[i].Set_Pin_Data(Valor);
		Parametro = "595M_LATCH_" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		MShiftOut[i].Set_Pin_Latch(Valor);
		Parametro = "595M_CLOCK_" + to_string(i);
		Valor = ARCHIVO->Read_Parameter(Parametro);
		MShiftOut[i].Set_Pin_Clock(Valor);


	};
	
	
	
}
