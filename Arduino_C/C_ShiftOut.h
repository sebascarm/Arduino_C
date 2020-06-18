#pragma once
#include "WinApi.h"

class C_ShiftOut {

private:
	Win_Shape* Cuadro = New_Shape();
	Win_Label* Label = New_Label();
	Win_Shape* Linea[8];
	Win_Shape* Data = New_Shape();
	Win_Shape* Latch = New_Shape();
	Win_Shape* Clock = New_Shape();
	Win_Label* Label_Linea[8];
	Win_Shape* Circulo_Linea[8];
	Win_Label* Label_Data = New_Label();
	Win_Label* Label_Latch = New_Label();
	Win_Label* Label_Clock = New_Label();
	Win_TextBox* Text_Data = New_TextBox();
	Win_TextBox* Text_Latch = New_TextBox();
	Win_TextBox* Text_Clock = New_TextBox();

	bool Latch_Val = false;
	bool Data_Val = false;
	bool Clock_Val = false;
	char Pin_Val = 0;
	char Pin_Buffer = 0;

	void PrenderPin(int pin);
	void ApagarPin(int pin);

	static void	Event_Text(int ID);

public:
	int TEX_ID_LATCH = 0;
	int TEX_ID_DATA  = 0;
	int TEX_ID_CLOCK = 0;
	void Create(Win_Frame* pFrame, string text, int x, int y);
	int PinData  = -1;
	int PinLatch = -1;
	int PinClock = -1;
	void Input_Data(bool Value);
	void Input_Latch(bool Value);
	//void Input_Clock(bool Value);
};

