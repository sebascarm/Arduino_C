// C_Timer.h

#ifndef _C_TIMER_h
#define _C_TIMER_h

/***********************************************************************************/
/****       DECLARACION DE CLASES (TIMER)                                       ****/
/***********************************************************************************/
// Timer Tiempo = 5000; //(hasta 33.000)                                        ****/
// void setup() {                                                               ****/
//    Tiempo.Accion = &Funcion;                                                 ****/
// void loop()                                                                  ****/
//    Tiempo.Check();                                                           ****/
//**********************************************************************************/
void SinAccion();
class C_Timer
{
 private:
	unsigned long V_Tiempo;
	unsigned long V_TActual;
	int V_Duracion;
	int V_TRestante;
	bool V_Stop = false;
 public:
	// Parametros
	int Total = 10000;				// TIEMPO INICIAL
	C_Timer();						// SIN PARAMETRO TIEMPO INICIAL = TOTAL
	C_Timer(int Tiempo);            // PARAMETRO TIEMPO INICIAL
	void operator = (int Tiempo);	// PARAMETRO TIEMPO INICIAL (Se puede declarar con "=")
	void(*Accion)() = &SinAccion;	// FUNCION A EJECUTAR EJ = Timer.Accion = &Funcion;
	// ACCIONES
	void Reiniciar();				//RE ARRANCA Y REINICIA CONTADOR
	int  Tiempo();					//DEVUEVE EL TIEMPO RESTANTE ACTUAL
	void Check();					//REVISA EL TIEMPO ACTUAL Y EJECUTA, LUEGO REINICIA EL TIEMPO
	bool SoloCheck();				//REVISA EL TIEMPO ACTUAL Y DEVULEVE VERDADERO SI LLEGO AL TIEMPO, LUEGO REINICIA EL TIEMPO
	void Stop();					//DETIENE EL CONTADOR, REINICIAR PARA INICIAR NUEVAMENTE
	
};

#endif

