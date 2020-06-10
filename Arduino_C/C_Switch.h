#pragma once
#include "WinApi.h"

class C_Switch{

private:
	Win_Shape*	Recuadro = New_Shape();
	Win_Shape*	Circulo = New_Shape();
	Win_Label*	Etiqueta = New_Label();
	Win_TextBox* Textbox = New_TextBox();
	Win_Button* Boton = New_Button();
	
	static int	Elementos;
	
	static void			Event_Press(int ID);
	static void			Event_Click(int ID);
	static void			Event_Text(int ID);
	
public:
	int	BOT_ID = 0;
	int	TEX_ID = 0;
	void Create(Win_Frame* pFrame, string text, int x, int y);
	int Pin = 0;
	int State = 0; // 0 o 1	
};

