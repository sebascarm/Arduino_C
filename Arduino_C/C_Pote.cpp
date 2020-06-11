#include "C_Pote.h"
#include "Funciones.h"
#include <math.h>

#define PI 3.141592653589793

std::vector <C_Pote*> p_POTE;				// Puntero Matriz Pote	
C_Pote* Obtener_Pote(int ID_Elemento);		// Funcion Estatica		
C_Pote* pPote;								// Puntero Estatico		

void C_Pote::Create(Win_Frame* pFrame, string text, int x, int y) {
	CentroX = x + 15;
	CentroY = y + 15;
	Circulo->Create(pFrame, S_Style::S_CIRCLE, x, y, 30, 30);
	CLinea = LineaAngular(-20, 15);
	Linea->Create(pFrame, S_Style::S_LINE, CentroX, CentroY, CLinea.x, CLinea.y);
	Etiqueta->Create(pFrame, text, x + 32, y + 20, 60, 20);
	Boton_menos->Create(pFrame, "-", x + 32, y, 20);
	Boton_mas->Create(pFrame, "+", x + 54, y, 20);
	Textbox->Create(pFrame, "", x + 76, y, 20, 20);
	Circulo->Set_BackColor(RGB(140, 140, 140));

	BOT_ID_menos = Boton_menos->Get_ID();
	BOT_ID_mas	 = Boton_mas->Get_ID();
	TEX_ID		 = Textbox->Get_ID();
		
	p_POTE.push_back(this);

	Boton_menos->Assign_Event_Click_ID(Event_Click_menos);
	Boton_mas->Assign_Event_Click_ID(Event_Click_mas);
	Textbox->Assign_Event_Text_Change_ID(Event_Text);
}

// Funciones estaticas				
void C_Pote::Event_Click_menos(int ID) {
	pPote = Obtener_Pote(ID);
	pPote->Value = pPote->Value - 50;
	if (pPote->Value < 0) pPote->Value = 0;
	Redibujado(pPote);
}

void C_Pote::Event_Click_mas(int ID) {
	pPote = Obtener_Pote(ID);
	pPote->Value = pPote->Value + 50;
	if (pPote->Value > 1024) pPote->Value = 1024;
	Redibujado(pPote);
}

void C_Pote::Event_Text(int ID) {
	pPote = Obtener_Pote(ID);
	string text = pPote->Textbox->Get_Text();
	pPote->Pin = Funciones::To_Integer(text);
}

void C_Pote::Redibujado(C_Pote* pPote) {
	float Angulo = Funciones::Mapeo((double)pPote->Value, 0, 1024, -20, -340);
	Coord SLinea = LineaAngular(Angulo, 15);
	pPote->Circulo->Set_Pos(pPote->CentroX - 15, pPote->CentroY - 15, 30, 30);
	pPote->Linea->Set_Pos(pPote->CentroX, pPote->CentroY, SLinea.x, SLinea.y);
}

Coord C_Pote::LineaAngular(float angulo, int longitud) {
	double anguloRad = angulo * PI / 180;
	int x, y;
	x = (int)(sin(anguloRad) * longitud);
	y = (int)(cos(anguloRad) * longitud);
	return { x,y };
}

C_Pote* Obtener_Pote(int ID_Elemento) {
	int cant = p_POTE.size();
	for (int i = 0; i < cant; i++) {
		if ((p_POTE[i]->BOT_ID_menos== ID_Elemento) || 
			(p_POTE[i]->BOT_ID_mas	== ID_Elemento) || 
			(p_POTE[i]->TEX_ID		== ID_Elemento)) {
			return p_POTE[i]; // Retorna el puntero al switch
		}
	}
}