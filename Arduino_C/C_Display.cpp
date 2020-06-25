#include "C_Display.h"

void C_Display::Create(Win_Frame* pFrame, string text, int x, int y){
	int ancho = 40;
	int alto = 55;
	Cuadro->Create(pFrame, S_Style::S_RECTANGLE, x, y, ancho, alto);
	Cuadro->Set_BackColor(RGB(100, 100, 100));
	D_a->Create(pFrame, S_Style::S_FREE, x, y);
	D_b->Create(pFrame, S_Style::S_FREE, x, y);
	D_c->Create(pFrame, S_Style::S_FREE, x, y);
	D_d->Create(pFrame, S_Style::S_FREE, x, y);
	D_e->Create(pFrame, S_Style::S_FREE, x, y);
	D_f->Create(pFrame, S_Style::S_FREE, x, y);
	D_g->Create(pFrame, S_Style::S_FREE, x, y);
	D_p->Create(pFrame, S_Style::S_FREE, x, y);

	D_a->Set_FreePoints(10,10,  30,10,  25,15,  15,15,  10,10);
	D_b->Set_FreePoints(31,11,  31,25,  26,20,  26,16,  31,11);
	D_c->Set_FreePoints(31,27,  31,41,  26,36,  26,32,  31,27);
	D_d->Set_FreePoints(10,42,  30,42,  25,37,  15,37,  10,42);
	D_e->Set_FreePoints(9,27,   9,41,   14,36,  14,32,  9,27);
	D_f->Set_FreePoints(9,11,   9,25,   14,20,  14,16,  9,11);
	D_g->Set_FreePoints(12,28,  12,24,  28,24,  28,28,  12,28);
	D_p->Set_FreePoints(32-2,45,  35-2,42,  38-2,45,  35-2,48,  32-2,45);

	L_T1->Create(pFrame, S_Style::S_LINE, x+20, y, 0,-10);
	L_T2->Create(pFrame, S_Style::S_LINE, x+20, y+alto, 0, 10);
	
	L_a->Create(pFrame, S_Style::S_LINE, x+29, y, 0, -10);
	L_b->Create(pFrame, S_Style::S_LINE, x+39, y, 0, -10);
	L_p->Create(pFrame, S_Style::S_LINE, x+39, y+alto, 0, 10);
	L_c->Create(pFrame, S_Style::S_LINE, x+29, y + alto, 0, 10);
	L_d->Create(pFrame, S_Style::S_LINE, x+11, y + alto, 0, 10);
	L_e->Create(pFrame, S_Style::S_LINE, x, y + alto, 0, 10);
	L_g->Create(pFrame, S_Style::S_LINE, x, y, 0, -10);
	L_f->Create(pFrame, S_Style::S_LINE, x+11, y, 0, -10);

	for (int i = 0; i < 8; i++) {
		Text_Data[i] = New_TextBox();
		switch (i) {
		case 0:	Text_Data[i]->Create(pFrame, "a", x+21, y - 24, 20, 14); break;
		case 1:	Text_Data[i]->Create(pFrame, "b", x+42, y - 24, 20, 14); break;
		case 2:	Text_Data[i]->Create(pFrame, "c", x+21, y+alto+11, 20, 14); break;
		case 3:	Text_Data[i]->Create(pFrame, "d", x, y + alto+11, 20, 14); break;
		case 4:	Text_Data[i]->Create(pFrame, "e", x-21, y + alto + 11, 20, 14); break;
		case 5:	Text_Data[i]->Create(pFrame, "f", x, y-24, 20, 14); break;
		case 6:	Text_Data[i]->Create(pFrame, "g", x-21, y-24, 20, 14); break;
		case 7:	Text_Data[i]->Create(pFrame, "p", x+42, y+alto+11, 20, 14); break;

		}
		Text_Data[i]->Set_Text_Size(9);
	}
}