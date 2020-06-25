#ifndef _C_TRANSCURRIDO_h
#define _C_TRANSCURRIDO_h

/***********************************************************************************/
/****       DECLARACION DE CLASES (TIEMPO TRANSCURRIDO)                         ****/
/***********************************************************************************/
// C_Transcurrido Tiempo            //(hasta 33.000)                            ****/
// void loop()                                                                  ****/
//    Transc = Tiempo.Tiempo();                                                 ****/
//**********************************************************************************/
class C_Transcurrido {
	private:
		unsigned long V_Tiempo;
		unsigned long V_TActual;
		int V_Duracion;
		bool V_Stop = false;
	public:
		C_Transcurrido();	// SIN PARAMETRO TIEMPO INICIAL = TOTAL
		// ACCIONES
		void Reiniciar();	//RE ARRANCA Y REINICIA CONTADOR
		int  Tiempo();		//DEVUEVE EL TIEMPO ACTUAL TRNASCURRIDO
		void Stop();        //DETIENE EL CONTADOR - LUEGO USAR REINICIAR O CONTINUAR
		void Continuar();   //CONTINUA EL CONTADOR DESPUES DE UN STOP
};

#endif