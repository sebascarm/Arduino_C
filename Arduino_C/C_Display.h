#pragma once
#include "WinApi.h"

class C_Display{

private:
	Win_Shape* Cuadro = New_Shape();
	Win_Shape* D_a = New_Shape();
	Win_Shape* D_b = New_Shape();
	Win_Shape* D_c = New_Shape();
	Win_Shape* D_d = New_Shape();
	Win_Shape* D_e = New_Shape();
	Win_Shape* D_f = New_Shape();
	Win_Shape* D_g = New_Shape();
	Win_Shape* D_p = New_Shape();
	Win_Shape* L_T1 = New_Shape();
	Win_Shape* L_T2 = New_Shape();
	Win_Shape* L_a = New_Shape();
	Win_Shape* L_b = New_Shape();
	Win_Shape* L_c = New_Shape();
	Win_Shape* L_d = New_Shape();
	Win_Shape* L_e = New_Shape();
	Win_Shape* L_f = New_Shape();
	Win_Shape* L_g = New_Shape();
	Win_Shape* L_p = New_Shape();

	Win_TextBox* Text_Data[8];

public:
	void Create(Win_Frame* pFrame, string text, int x, int y);
};

