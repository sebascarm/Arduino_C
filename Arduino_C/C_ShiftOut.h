#pragma once
#include "WinApi.h"

class C_ShiftOut{

private:
	Win_Shape* Cuadro = New_Shape();
	Win_Label* Label = New_Label();
	Win_Shape* Linea[8];
	Win_Shape* Data = New_Shape();
	Win_Shape* Latch = New_Shape();
	Win_Shape* Clock = New_Shape();
	Win_Label* Label_Linea[8];
	Win_TextBox* Text_Linea[8];
	Win_Label* Label_Data = New_Label();
	Win_Label* Label_Latch = New_Label();
	Win_Label* Label_Clock = New_Label();
	Win_TextBox* Text_Data = New_TextBox();
	Win_TextBox* Text_Latch = New_TextBox();
	Win_TextBox* Text_Clock = New_TextBox();

public:
	void Create(Win_Frame* pFrame, string text, int x, int y);
};

