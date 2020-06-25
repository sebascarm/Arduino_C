// C_GrupoChip.h

#ifndef _C_GRUPOCHIP_h
#define _C_GRUPOCHIP_h

/// ********************************************************************************************
/// **** <summary> CLASE: Definicion Grupo de Chips  						</summary>		****
/// ********************************************************************************************
class C_GrupoChip {
private:
	byte V_Cant_Chips;
	byte V_PinData;
	byte V_PinLatch;
	byte V_PinClock;

	byte shift_IN(int myDataPin, int myClockPin);

	byte *V_ChipPrevio = NULL; //Declaracion de puntero para array dinamico

public:
	/// ********************************************************************************************************************
	/// **** <summary> CONSTRUCTOR DE LA CLASE </summary>		     		    										****
	/// **** <param name = "Cant_Chips"> Cantidad de integrados del Grupo / Crea un elemento Chip por cada uno </param> ****
	/// ********************************************************************************************************************
	C_GrupoChip(byte Cant_Chips);
	/// ***************************************************************************************
	/// **** <summary> PARAMETRO OBLIGATORIO: Pines asignados al Grupo de Chips (LEDS Y DISPLAY) </summary> ****
	/// ***************************************************************************************
	void PinesIN(byte PinData, byte PinLatch, byte PinClock);
	/// ***************************************************************************************
	/// **** <summary> PARAMETRO OBLIGATORIO: Pines asignados al Grupo de Chips (SWITCH) </summary> ****
	/// ***************************************************************************************
	void PinesOUT(byte PinData, byte PinLatch, byte PinClock);

	/// ********************************************************************************************************
	/// **** <summary> VALOR: Vector de Chips individual para Leectura o Asignacion. Ej: Chip[0] </summary> ****
	/// ********************************************************************************************************
	byte *Chip = NULL; //Declaracion de puntero para array dinamico

	/// ********************************************************************************************
	/// **** <summary> ACCION: Lee los Integrados y los carga en las variables Chips </summary>	****
	/// ********************************************************************************************
	void CargarChips();
	/// ************************************************************************************
	/// **** <summary> ACCION: Carga las Variables Chips en los integrados </summary>	****
	/// ************************************************************************************
	void EscribirChips();
	/// ************************************************************************************
	/// **** <summary> ACCION: Apaga todos los integrados </summary>					****
	/// ************************************************************************************
	void Apagar();
	/// ************************************************************************************
	/// **** <summary> ACCION: Enciende al maximo todos los integrados 		</summary>	****
	/// ************************************************************************************
	void Encender();
	/// ************************************************************************************
	/// **** <summary> ACCION: Apaga, Enciende y Apaga Nuevamente 		     </summary>	****
	/// ************************************************************************************
	void Test(int Tiempo_ms = 500);
	
	/// ************************************************************************************
	/// **** <summary> ACCION: TEST INDIVIDUAL DE CHIPS 		     		</summary>	****
	/// ************************************************************************************
	void Test_Individual(int Tiempo_ms = 500);

	/// ************************************************************************************
	/// **** <summary> CONTROL: DEVUELVE SI FUE MODIFICADO 		     </summary>	****
	/// ************************************************************************************
	bool Modificado();
};

#endif