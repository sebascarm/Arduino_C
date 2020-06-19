#include "C_ShiftOut.h"

#include "Funciones.h"
#include <bitset>

std::vector <C_ShiftOut*> p_SHIFT;				// Puntero Matriz Pote	
C_ShiftOut* Obtener_Shift(int ID_Elemento);		// Funcion Estatica		
C_ShiftOut* pShift;								// Puntero Estatico		


void C_ShiftOut::Create(Win_Frame* pFrame, string text, int x, int y){
	int ancho = 30;
	Cuadro->Create(pFrame, S_Style::S_RECTANGLE, x, y, ancho, 90);
	Cuadro->Set_BackColor(RGB(100, 100, 100));
	for (int i = 0; i < 8; i++)	{
		Linea[i] = New_Shape();
		Linea[i]->Create(pFrame, S_Style::S_LINE, x + ancho, (y+5)+(i * 11), 10, 0);
		Label_Linea[i] = New_Label();
		Label_Linea[i]->Create(pFrame, to_string(i+1), (x + ancho + 2), (y + 6) + (i * 11), 10, 10);
		Label_Linea[i]->Set_Text_Size(11);
		Circulo_Linea[i] = New_Shape();
		Circulo_Linea[i]->Create(pFrame, S_Style::S_CIRCLE, (x + ancho + 10), (y+1 + (i * 11)), 10, 10);
		Circulo_Linea[i]->Set_BackColor(RGB(50, 50, 50));
	}
	Data->Create(pFrame, S_Style::S_LINE, x -25, (y + 5), 24, 0);
	Data->Set_Color(RGB(0, 200, 0));
	Data->Set_Border_Size(3);
	Latch->Create(pFrame, S_Style::S_LINE, x - 25, (y + 5)+ 20, 24, 0);
	Latch->Set_Color(RGB(200, 100, 0));
	Latch->Set_Border_Size(3);
	Clock->Create(pFrame, S_Style::S_LINE, x - 25, (y + 5)+ 40, 24, 0);
	Clock->Set_Color(RGB(200, 200, 0));
	Clock->Set_Border_Size(3);
	Label_Data->Create(pFrame, "Data", (x -26), (y + 8) , 24, 9,W_Align::A_DER);
	Label_Data->Set_Text_Size(12);
	Label_Latch->Create(pFrame, "Latch", (x - 26), (y + 8)+20, 24, 9, W_Align::A_DER);
	Label_Latch->Set_Text_Size(12);
	Label_Clock->Create(pFrame, "Clock", (x - 26), (y + 8)+40, 24, 9, W_Align::A_DER);
	Label_Clock->Set_Text_Size(12);
	Text_Data->Create(pFrame, "", (x - 48), y+5 , 20, 14);
	Text_Data->Set_Text_Size(9);
	Text_Latch->Create(pFrame, "", (x - 48), y+25, 20, 14);
	Text_Latch->Set_Text_Size(9);
	Text_Clock->Create(pFrame, "", (x - 48), y+45, 20, 14);
	Text_Clock->Set_Text_Size(9);

	TEX_ID_LATCH = Text_Latch->Get_ID();
	TEX_ID_DATA = Text_Data->Get_ID();
	TEX_ID_CLOCK = Text_Clock->Get_ID();

	p_SHIFT.push_back(this);

	Text_Latch->Assign_Event_Text_Change_ID(Event_Text);
	Text_Data->Assign_Event_Text_Change_ID(Event_Text);
	Text_Clock->Assign_Event_Text_Change_ID(Event_Text);
}

void C_ShiftOut::Input_Latch(bool Value){
	Latch_Val = Value;
	
	if (Latch_Val) {
		Pin_Val = Pin_Buffer;
		Pin_Buffer = 0;
		//string tmp = "PIN VAL: " + std::bitset<8>(Pin_Val).to_string() + '\n';
		//OutputDebugString(tmp.c_str());
		for (int i = 0; i < 8; i++) {
			bool Valor_bit;
			Valor_bit = Funciones::Get_Bit(Pin_Val, i);
			//Sleep(1);
			if (Valor_bit) {
				//OutputDebugString("ON ");
				PrenderPin(i);
			} else {
				//OutputDebugString("FF "); 
				ApagarPin(i);
			}
		}
		//OutputDebugString("\n");
		//Sleep(1);

	}
	// Imprimir
	/*
	if (Latch_Val) {
		Pin_Val = Pin_Buffer;
		Pin_Buffer = 0;
		if ((Pin_Val & 0x1) == 0) ApagarPin(0);
		else PrenderPin(0);
		if ((Pin_Val & 0x2) == 0) ApagarPin(1);
		else PrenderPin(1);
		if ((Pin_Val & 0x4) == 0) ApagarPin(2);
		else PrenderPin(2);
		if ((Pin_Val & 0x8) == 0) ApagarPin(3);
		else PrenderPin(3);
		if ((Pin_Val & 0x16) == 0) ApagarPin(4);
		else PrenderPin(4);
		if ((Pin_Val & 0x32) == 0) ApagarPin(5);
		else PrenderPin(5);
		if ((Pin_Val & 0x64) == 0) ApagarPin(6);
		else PrenderPin(6);
		if ((Pin_Val & 0x128) == 0) ApagarPin(7);
		else PrenderPin(7);
	}
	*/
}

void C_ShiftOut::PrenderPin(int pin) {
	Circulo_Linea[pin]->Set_BackColor(RGB(250, 0, 0));
}
void C_ShiftOut::ApagarPin(int pin) {
	Circulo_Linea[pin]->Set_BackColor(RGB(50, 50, 50));
}

void C_ShiftOut::Input_Data(bool Value) {
	Funciones::Add_Bit(Pin_Buffer, Value);
	//string tmp = std::bitset<8>(Pin_Buffer).to_string() + '\n';
	//OutputDebugString(tmp.c_str());
	//if (!Latch_Val){
	//	Pin_Buffer = Pin_Buffer << 1;
	//	Pin_Buffer = Pin_Buffer | Value;

	//	string tmp = std::bitset<8>(Pin_Buffer).to_string() + '\n';
	//	OutputDebugString(tmp.c_str());
	//}
}

// Funciones estaticas				
void C_ShiftOut::Event_Text(int ID) {
	pShift = Obtener_Shift(ID);
	string text;
	if (pShift->TEX_ID_LATCH == ID) {
		text = pShift->Text_Latch->Get_Text();
		if (text == "")	pShift->PinLatch = -1;
		else pShift->PinLatch = Funciones::To_Integer(text);
	}
	else if (pShift->TEX_ID_DATA == ID) {
		text = pShift->Text_Data->Get_Text();
		if (text == "")	pShift->PinData = -1;
		else pShift->PinData = Funciones::To_Integer(text);
	}
	else if (pShift->TEX_ID_CLOCK == ID) {
		text = pShift->Text_Clock->Get_Text();
		if (text == "")	pShift->PinClock = -1;
		else pShift->PinClock = Funciones::To_Integer(text);
	}
}

C_ShiftOut* Obtener_Shift(int ID_Elemento) {
	int cant = p_SHIFT.size();
	for (int i = 0; i < cant; i++) {
		if ((p_SHIFT[i]->TEX_ID_LATCH == ID_Elemento) ||
			(p_SHIFT[i]->TEX_ID_DATA == ID_Elemento) ||
			(p_SHIFT[i]->TEX_ID_CLOCK == ID_Elemento)) {
			return p_SHIFT[i]; // Retorna el puntero al switch
		}
	}
}