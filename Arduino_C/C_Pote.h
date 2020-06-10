#pragma once
#include "WinApi.h"

struct Coord {
	int x;
	int y;
};

class C_Pote{

private:
	Win_Shape*	Circulo = New_Shape();
	Win_Shape*	Linea = New_Shape();
	Win_Label*	Etiqueta = New_Label();
	Win_TextBox* Textbox = New_TextBox();
	Win_Button* Boton_menos = New_Button();
	Win_Button* Boton_mas = New_Button();
	int			CentroX = 0, CentroY = 0;
	Coord		CLinea;
	
	static Coord LineaAngular(float angulo, int longitud);
	
	
	static void	Event_Click_menos(int ID);
	static void	Event_Click_mas(int ID);

public:
	int	BOT_ID_menos = 0;
	int	BOT_ID_mas	 = 0;
	void Create(Win_Frame* pFrame, string text, int x, int y);
	int Pin = 0;
	int Value = 0; // 0 - 1024	
};

