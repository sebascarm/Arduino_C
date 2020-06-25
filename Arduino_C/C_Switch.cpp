#include "C_Switch.h"
#include "Funciones.h"

std::vector <C_Switch*> p_SWITCH;			// Puntero Matriz Switch
C_Switch* Obtener_Switch(int ID_Elemento);	// Funcion Estatica		
C_Switch* pSwitch;							// Puntero Estatico		

void C_Switch::Create(Win_Frame* pFrame, string text, int x, int y){
	Recuadro->Create(pFrame, S_Style::S_RECTANGLE, x, y, 20, 20);
	Circulo->Create(pFrame, S_Style::S_CIRCLE, x+3, y+3, 14, 14);
	Etiqueta->Create(pFrame, text, x, y + 20, 60, 20);
	Boton->Create(pFrame, "X", x + 22, y, 20);
	Textbox->Create(pFrame, "", x + 44, y , 20, 20);
	Textbox->Set_Text_Size(11);
	
	Recuadro->Set_BackColor(RGB(120, 120, 120));
	Circulo->Set_BackColor(RGB(60, 60, 60));
	
	BOT_ID = Boton->Get_ID();
	TEX_ID = Textbox->Get_ID();
	p_SWITCH.push_back(this);

	Boton->Assign_Event_Press_ID(Event_Press);
	Boton->Assign_Event_Click_ID(Event_Click);
	Textbox->Assign_Event_Text_Change_ID(Event_Text);

}

void C_Switch::Set_Pin(string Pin) {
	Textbox->Set_Text(Pin);
	if (Pin == "") this->Pin = -1;
	else this->Pin = Funciones::To_Integer(Pin);
}

// Funciones estaticas				
void C_Switch::Event_Press(int ID) {
	pSwitch = Obtener_Switch(ID);
	pSwitch->State = 1;
	pSwitch->Circulo->Set_BackColor(RGB(60, 160, 60));
}
void C_Switch::Event_Click(int ID) {
	pSwitch = Obtener_Switch(ID);
	pSwitch->State = 0;
	pSwitch->Circulo->Set_BackColor(RGB(60, 60, 60));
}

void C_Switch::Event_Text(int ID){
	pSwitch = Obtener_Switch(ID);
	string text = pSwitch->Textbox->Get_Text();
	if (text == "") {
		pSwitch->Pin = -1;
	} else {
		pSwitch->Pin = Funciones::To_Integer(text);
	}

}

C_Switch* Obtener_Switch(int ID_Elemento) {
	int cant = p_SWITCH.size();
	for (int i = 0; i < cant; i++) {
		if ((p_SWITCH[i]->BOT_ID == ID_Elemento) || 
			(p_SWITCH[i]->TEX_ID == ID_Elemento)) {
			//string tmp = "ID" + to_string(ID_Boton);
			//OutputDebugString(tmp.c_str());
			return p_SWITCH[i]; // Retorna el puntero al switch
		}
	}
}

