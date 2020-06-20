#include "C_ShiftIn.h"

#include "C_Switch.h"

#include "Funciones.h"
#include <bitset>

extern std::vector <C_Switch*> p_SWITCH;		// Puntero Matriz Switch externo

std::vector <C_ShiftIn*> p_SHIFT_IN;			// Puntero Matriz Pote	
C_ShiftIn* Obtener_Shift(int ID_Elemento);		// Funcion Estatica		
C_ShiftIn* pShiftIn;							// Puntero Estatico		

int C_ShiftIn::sID = 0;
int C_ShiftIn::sPinIn = 300;

void C_ShiftIn::Create(Win_Frame* pFrame, string text, int x, int y) {
	ID = sID;
	PinIn = sPinIn;
	PinDataIn = sPinIn + 9;
	++sID;
	sPinIn = sPinIn + 10;

	int ancho = 30;
	Cuadro->Create(pFrame, S_Style::S_RECTANGLE, x, y, ancho, 90);
	Cuadro->Set_BackColor(RGB(100, 100, 100));
	Label->Create(pFrame, "4021", x, y + 30, ancho, 20, W_Align::A_CENT);
	Label->Set_BackColor(RGB(100, 100, 100));
	Titulo->Create(pFrame, text, x + 1, y + 42, ancho - 2, 20, W_Align::A_CENT);
	Titulo->Set_BackColor(RGB(100, 100, 100));

	for (int i = 0; i < 8; i++) {
		Linea[i] = New_Shape();
		Linea[i]->Create(pFrame, S_Style::S_LINE, x + ancho, (y + 5) + (i * 11), 10, 0);
		Label_Linea[i] = New_Label();
		Label_Linea[i]->Create(pFrame, to_string(i + 1), (x + ancho + 2), (y + 6) + (i * 11), 10, 10);
		Label_Linea[i]->Set_Text_Size(11);
		Circulo_Linea[i] = New_Shape();
		Circulo_Linea[i]->Create(pFrame, S_Style::S_CIRCLE, (x + ancho + 10), (y + 1 + (i * 11)), 10, 10);
		Circulo_Linea[i]->Set_BackColor(RGB(50, 50, 50));
	}
	Data->Create(pFrame, S_Style::S_LINE, x - 25, (y + 5), 24, 0);
	Data->Set_Color(RGB(0, 0, 200));
	Data->Set_Border_Size(3);
	Latch->Create(pFrame, S_Style::S_LINE, x - 25, (y + 5) + 20, 24, 0);
	Latch->Set_Color(RGB(200, 100, 0));
	Latch->Set_Border_Size(3);
	Clock->Create(pFrame, S_Style::S_LINE, x - 25, (y + 5) + 40, 24, 0);
	Clock->Set_Color(RGB(200, 200, 0));
	Clock->Set_Border_Size(3);
	Label_Data->Create(pFrame, "Data", (x - 26), (y + 8), 24, 9, W_Align::A_DER);
	Label_Data->Set_Text_Size(12);
	Label_Latch->Create(pFrame, "Latch", (x - 26), (y + 8) + 20, 24, 9, W_Align::A_DER);
	Label_Latch->Set_Text_Size(12);
	Label_Clock->Create(pFrame, "Clock", (x - 26), (y + 8) + 40, 24, 9, W_Align::A_DER);
	Label_Clock->Set_Text_Size(12);
	Text_Data->Create(pFrame, "", (x - 48), y + 5, 20, 14);
	Text_Data->Set_Text_Size(9);
	Text_Latch->Create(pFrame, "", (x - 48), y + 25, 20, 14);
	Text_Latch->Set_Text_Size(9);
	Text_Clock->Create(pFrame, "", (x - 48), y + 45, 20, 14);
	Text_Clock->Set_Text_Size(9);

	TEX_ID_LATCH = Text_Latch->Get_ID();
	TEX_ID_DATA = Text_Data->Get_ID();
	TEX_ID_CLOCK = Text_Clock->Get_ID();

	DataOut->Create(pFrame, S_Style::S_LINE, x - 13, (y + 5) + 78, 13, 0);
	Circulo_PinOut->Create(pFrame, S_Style::S_CIRCLE, x - 23, (y + 5) + 73, 10, 10);
	Circulo_PinOut->Set_BackColor(RGB(50, 50, 50));
	Label_PinOut->Create(pFrame, to_string(PinDataIn), x - 14, (y + 6) + 78, 20, 10);
	Label_PinOut->Set_Text_Size(11);
	//Label_PinOut_Detalle->Create(pFrame, "D. Out", (x-26), (y+5)+73, 24, 9, W_Align::A_DER);
	Label_PinOut_Detalle->Create(pFrame, "IN", (x - 45), (y + 5) + 72, 20, 9);
	Label_PinOut_Detalle->Set_Text_Size(12);

	p_SHIFT_IN.push_back(this);

	Text_Latch->Assign_Event_Text_Change_ID(Event_Text);
	Text_Data->Assign_Event_Text_Change_ID(Event_Text);
	Text_Clock->Assign_Event_Text_Change_ID(Event_Text);


}

void C_ShiftIn::Input_Latch(bool Value) {
	Latch_Val = Value;
	if (Latch_Val) {			//Get data
		Capturar_Datos();
		//Pin_Val = Pin_Buffer;
	} 
	//Latch 0 para Send Data
}
void C_ShiftIn::Input_Clock(bool Value){
	// revisamos que estemos en modo de transmision
	if (!Latch_Val) {
		Clock_Val = Value;
		if (!Clock_Val) {
			// Pasamos el valor al Data
			Data_Val = Funciones::Get_Bit(Pin_Buffer, 7);
		} else {
			// Movemos el registro
			Pin_Buffer = Pin_Buffer << 1;
		}
	}
}
bool C_ShiftIn::Get_Data() {
	return Data_Val;
}

void C_ShiftIn::Capturar_Datos() {
	// Recorrer los switchs
	int Cant_Switch = p_SWITCH.size();
	for (int i = 0; i < Cant_Switch; i++) {
		if (p_SWITCH[i]->Pin > 299) {			// Revisamos q este en un shift out
			for (int j = 0; j < 8; j++) {
				int PinLocal = PinIn + j;											// Recorremos todos los pines
				if (p_SWITCH[i]->Pin == PinLocal) {									// Revisamos que la entrada de otro sea igual a la salida
					Funciones::Bit_Write(Pin_Buffer, j, p_SWITCH[i]->State);	// Guardamos
				}
			}
		}
	}
}



void C_ShiftIn::PrenderPin(int pin) {
	Circulo_Linea[pin]->Set_BackColor(RGB(250, 0, 0));
}
void C_ShiftIn::ApagarPin(int pin) {
	Circulo_Linea[pin]->Set_BackColor(RGB(50, 50, 50));
}
void C_ShiftIn::PrenderOut() {
	Circulo_PinOut->Set_BackColor(RGB(250, 0, 0));
}
void C_ShiftIn::ApagarOut() {
	Circulo_PinOut->Set_BackColor(RGB(50, 50, 50));
}



// Funciones estaticas				
void C_ShiftIn::Event_Text(int ID) {
	pShiftIn = Obtener_Shift(ID);
	string text;
	if (pShiftIn->TEX_ID_LATCH == ID) {
		text = pShiftIn->Text_Latch->Get_Text();
		if (text == "")	pShiftIn->PinLatch = -1;
		else pShiftIn->PinLatch = Funciones::To_Integer(text);
	}
	else if (pShiftIn->TEX_ID_DATA == ID) {
		text = pShiftIn->Text_Data->Get_Text();
		if (text == "")	pShiftIn->PinData = -1;
		else pShiftIn->PinData = Funciones::To_Integer(text);
	}
	else if (pShiftIn->TEX_ID_CLOCK == ID) {
		text = pShiftIn->Text_Clock->Get_Text();
		if (text == "")	pShiftIn->PinClock = -1;
		else pShiftIn->PinClock = Funciones::To_Integer(text);
	}
}

C_ShiftIn* Obtener_Shift(int ID_Elemento) {
	int cant = p_SHIFT_IN.size();
	for (int i = 0; i < cant; i++) {
		if ((p_SHIFT_IN[i]->TEX_ID_LATCH == ID_Elemento) ||
			(p_SHIFT_IN[i]->TEX_ID_DATA == ID_Elemento) ||
			(p_SHIFT_IN[i]->TEX_ID_CLOCK == ID_Elemento)) {
			return p_SHIFT_IN[i]; // Retorna el puntero al switch
		}
	}
}