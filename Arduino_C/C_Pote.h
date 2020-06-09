#pragma once
#include "WinApi.h"


class C_Pote{

private:
	Win_Shape* Circulo = New_Shape();
	Win_Shape* Linea = New_Shape();
	Win_Label* Etiqueta = New_Label();
	Win_TextBox* Textbox = New_TextBox();
	Win_Button* Boton_menos = New_Button();
	Win_Button* Boton_mas = New_Button();

	int CentroX = 0, CentroY = 0;

public:
	void Create(Win_Frame* pFrame, string text, int x, int y);

};

