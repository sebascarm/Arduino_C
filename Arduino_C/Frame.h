#pragma once

#include "WinApi.h"
#include "c_switch.h"
#include "C_Pote.h"
#include "C_ShiftOut.h"
#include "C_ShiftIn.h"

//******************************************************************//
//**** VARIABLES GLOBALES										****//
//******************************************************************//

int		LOOPS		= 100000;	// Cantidad de Loops			
int		DELAY		= 10;		// Delay entre loops			
string	BUFFERSERIE = "";		// BUFFER  Puerto serie entrada	
bool	STOP		= false;
bool	PAUSA		= false;

//******************************************************************//
//**** OBJETOS GLOBALES											****//
//******************************************************************//
Win_Api*	WinApi = New_Api();
Win_Frame*	Frame1 = New_Frame();
Win_Menu*	Menu1 = New_Menu();
// Mensajes Generales
Win_MessageBox* Mensaje = New_MessageBox();

// Objetos			
Win_Button*		Boton_Iniciar	= New_Button();
Win_Button*		Boton_Parar		= New_Button();
Win_Button*		Boton_Pausa		= New_Button();
Win_Button*		Boton_Conectar  = New_Button();
Win_Button*		Boton_Guardar	= New_Button();
Win_Label*		Label_Loop		= New_Label();
Win_TextBox*	Text_Loop		= New_TextBox();
Win_Label*		Label_Delay		= New_Label();
Win_TextBox*	Text_Delay		= New_TextBox();
Win_MultiLine*	Text_SerieIN	= New_MultiLine();
Win_TextBox*	Text_Serial		= New_TextBox();
Win_MultiLine*	Text_SerieOUT	= New_MultiLine();
Win_Shape*		Placa			= New_Shape();
std::vector <Win_Shape*> Pin;
std::vector <Win_Label*> Label;
// Objetos compuestos
C_Switch CSwitch[3];
C_Pote	 CPote[3];
C_ShiftOut CShiftOut[3];
C_ShiftIn  CShiftIn[3];

//******************************************************************//
//**** CREAR OBJETOS											****//
//******************************************************************//
void CrearObjetos(HINSTANCE hInstance) {
	//Principal
	WinApi->Create(hInstance);
	Frame1->Create(WinApi, "Titulo", 50, 50, 1100, 540, true);
	Menu1->Create(Frame1, "Menú", { "Menu 1", "-", "Salir" });
	//Grupo1
	Boton_Iniciar->Create(Frame1, "Iniciar", 260, 30);
	Boton_Parar->Create(Frame1, "Detener", 260, 52);
	Boton_Pausa->Create(Frame1, "Pausa", 260, 74);
	Label_Loop->Create(Frame1, "Loops", 260, 98);
	Text_Loop->Create(Frame1, "100000", 260, 114);
	Label_Delay->Create(Frame1, "Delay", 260, 138);
	Text_Delay->Create(Frame1, "10", 260, 154);
	Boton_Conectar->Create(Frame1, "Conectar", 260, 308);
	Boton_Guardar->Create(Frame1, "Guardar", 260, 330);

	Text_SerieIN->Create(Frame1, "", 330, 30, 200, 298);
	Text_Serial->Create(Frame1, "", 330, 330, 183, 20);
	Text_SerieOUT->Create(Frame1, "", 540, 30, 500, 320);
	//Compuestos
	CSwitch[0].Create(Frame1, "Switch 1", 50, 380);
	CSwitch[1].Create(Frame1, "Switch 2", 50, 420);
	CSwitch[2].Create(Frame1, "Switch 3", 50, 460);
	CPote[0].Create(Frame1, "Pote 1", 120, 380);
	CPote[1].Create(Frame1, "Pote 2", 120, 420);
	CPote[2].Create(Frame1, "Pote 3", 120, 460);
	CShiftOut[0].Create(Frame1, "SH-1", 300, 380);
	CShiftOut[1].Create(Frame1, "SH-2", 420, 380);
	CShiftOut[2].Create(Frame1, "SH-3", 540, 380);
	CShiftIn[0].Create(Frame1, "IN-1", 660, 380);

	int x = 50, y=30;
	Placa->Create(Frame1, S_Style::S_RECTANGLE, x, y, 200, 320);
	Placa->Set_BackColor(RGB(0, 100, 0));
	
	int j = 0;
	int k = 21;
	int l = 15;
	for (int i = 0; i < 8; i++) {
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, x, (y+30)+(i*10) , 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		Label[j]->Create(Frame1,to_string(k), x+12, (y + 30) + (i * 10), 20, 10);
		Label[j]->Set_Text_Size(12);
		Label[j]->Set_BackColor(RGB(0, 100, 0));
		k--;
		j++;
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, x+190, (y + 30) + (i * 10), 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		Label[j]->Create(Frame1, "A" + to_string(l), x+168, (y + 30) + (i * 10), 20, 10,W_Align::A_DER);
		Label[j]->Set_Text_Size(12);
		Label[j]->Set_BackColor(RGB(0, 100, 0));
		l--;
		j++;
	}
	k = 0;
	for (int i = 8; i < 16; i++) {
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, x, (y + 40) + (i * 10), 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		Label[j]->Create(Frame1, to_string(k), x + 12, (y + 40) + (i * 10), 20, 10);
		Label[j]->Set_Text_Size(12);
		Label[j]->Set_BackColor(RGB(0, 100, 0));
		k++;
		j++;
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, x+190, (y + 40) + (i * 10), 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		Label[j]->Create(Frame1, "A" + to_string(l), x + 168, (y + 40) + (i * 10), 20, 10, W_Align::A_DER);
		Label[j]->Set_Text_Size(12);
		Label[j]->Set_BackColor(RGB(0, 100, 0));
		l--;
		j++;
	}
	for (int i = 16; i < 26; i++) {
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, x, (y + 50) + (i * 10), 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		if (k < 14) {
			Label[j]->Create(Frame1, to_string(k), x + 12, (y + 50) + (i * 10), 20, 10);
		}
		if (k == 14) Label[j]->Create(Frame1, "GND", x + 12, (y + 50) + (i * 10), 40, 10);
		if (k == 15) Label[j]->Create(Frame1, "AREF", x + 12, (y + 50) + (i * 10), 40, 10);
		if (k == 16) Label[j]->Create(Frame1, "I2C", x + 12, (y + 50) + (i * 10), 40, 10);
		if (k == 17) Label[j]->Create(Frame1, "I2C", x + 12, (y + 50) + (i * 10), 40, 10);
		Label[j]->Set_Text_Size(12);
		Label[j]->Set_BackColor(RGB(0, 100, 0));
		k++;
		j++;
	}
	for (int i = 16; i < 24; i++) {
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, x+190, (y + 50) + (i * 10), 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		if (i == 16) Label[j]->Create(Frame1, "Vin", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 17) Label[j]->Create(Frame1, "GND", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 18) Label[j]->Create(Frame1, "GND", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 19) Label[j]->Create(Frame1, "5V", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 20) Label[j]->Create(Frame1, "3.3V", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 21) Label[j]->Create(Frame1, "RESET", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 22) Label[j]->Create(Frame1, "IOREF", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		if (i == 23) Label[j]->Create(Frame1, "", x + 148, (y + 50) + (i * 10), 40, 10, W_Align::A_DER);
		Label[j]->Set_Text_Size(12);
		Label[j]->Set_BackColor(RGB(0, 100, 0));
		j++;
	}

	k = j;
	l = 22;
	for (int i = 0; i < 18; i++) {
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, (x+10)+(i * 10), y, 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		// Etiquetas
		Label.push_back(New_Label());
		if (i == 0) Label[k]->Create(Frame1, "5V", (x+10)+(i*10) , y+20, 40, 10);
		if (i == 17) Label[k]->Create(Frame1, "GND", (x + 10) + (i * 10), y + 20, 40, 10);
		if ((i > 0) && (i < 17)) {
			Label[k]->Create(Frame1, to_string(l), (x + 10) + (i * 10), y + 20, 40, 10);
			l = l + 2;
		}
		Label[k]->Set_Text_Size(8);
		Label[k]->Set_BackColor(RGB(0, 100, 0));
		
		j++;
		k++;
		Pin.push_back(New_Shape());
		Pin[j]->Create(Frame1, S_Style::S_RECTANGLE, (x + 10) + (i * 10), y+10, 10, 10);
		Pin[j]->Set_BackColor(RGB(100, 100, 100));
		Pin[j]->Set_Border_Size(2);
		Pin[j]->Set_Color(RGB(50, 50, 50));
		j++;
	}


}

