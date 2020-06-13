#include "C_ShiftOut.h"

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

		Text_Linea[i] = New_TextBox();
		Text_Linea[i]->Create(pFrame, "", (x + ancho + 14), y + (i * 11), 20, 14);
		Text_Linea[i]->Set_Text_Size(9);
		
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
}
