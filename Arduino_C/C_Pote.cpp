#include "C_Pote.h"

void C_Pote::Create(Win_Frame* pFrame, string text, int x, int y) {
	CentroX = x + 15;
	CentroY = y + 15;
	Circulo->Create(pFrame, S_Style::S_CIRCLE, x, y, 30, 30);
	Linea->Create(pFrame, S_Style::S_LINE, CentroX, CentroY, 15, 10);
	Etiqueta->Create(pFrame, text, x + 32, y + 20, 60, 20);
	Boton_menos->Create(pFrame, "-", x + 32, y, 20);
	Boton_mas->Create(pFrame, "+", x + 54, y, 20);
	Textbox->Create(pFrame, "", x + 76, y, 20, 20);
		
	Circulo->Set_BackColor(RGB(140, 140, 140));


}