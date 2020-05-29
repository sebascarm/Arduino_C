#pragma once

#include "WinApi.h"

//******************************************************************//
//**** OBJETOS GLOBALES											****//
//******************************************************************//
Win_Api*	WinApi = New_Api();
Win_Frame*	Frame1 = New_Frame();
Win_Menu*	Menu1 = New_Menu();
// Mensajes Generales
Win_MessageBox* Mensaje = New_MessageBox();

// Objetos			
Win_Button* Boton_Iniciar = New_Button();
Win_Shape*  Placa		  = New_Shape();
std::vector <Win_Shape*> Pin;
std::vector <Win_Label*> Label;

//******************************************************************//
//**** CREAR OBJETOS											****//
//******************************************************************//
void CrearObjetos(HINSTANCE hInstance) {
	//Principal
	WinApi->Create(hInstance);
	Frame1->Create(WinApi, "Titulo", 50, 50, 600, 400, true);
	Menu1->Create(Frame1, "Menú", { "Menu 1", "-", "Salir" });

	//Grupo1
	Boton_Iniciar->Create(Frame1, "Iniciar", 260, 30);
	
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
		j++;
	}


	//Shape1->Create(Frame1, S_Style::S_CIRCLE, 50, 50, 50, 50);
	//Shape2->Create(Frame1, S_Style::S_RECTANGLE, 250, 250, 100, 100);
	//Shape1->Create(Frame1, S_Style::S_CIRCLE, 50, 50, 70, 70);
	//Shape1->Create(Frame1, S_Style::S_LINE, 50, 50, 70, 70);
	//Shape1->Set_FreePoints(0, 0, 10, 10, 10, 60, 0, 70, 0,0);
}

