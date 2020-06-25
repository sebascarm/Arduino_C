// C_Control.h

#ifndef _C_CONTROL_h
#define _C_CONTROL_h

#include "C_Comunicacion.h"


/// ********************************************************************************************
/// **** <summary> CLASE: Definicion de controles (Switch, Pulsador, Llave) </summary>		****
/// ********************************************************************************************
class C_Control {
private:
	TipoControl V_Tipo;
	int V_Valor = -1;
	int V_ValorAnt = -1;
	byte *V_Chip; //Puntero a Chip
	byte V_Posicion;
	String V_Comando;
	
public:
	/// ************************************************************************************
	/// **** <summary> CONSTRUCTOR DE LA CLASE </summary>								****
	/// **** <param name = "Tipo"> Tipo de Control (Switch, Pulsador, Llave) </param>   ****
	/// **** <param name = "Comando"> Asignacion de Comando a enviar		 </param>   ****
	/// **** <param name = "Chip"> Asignacion de Chip individual			 </param>   ****
	/// **** <param name = "Posicion"> Posicion del Chip a leer				 </param>   ****
	/// ************************************************************************************
	C_Control(TipoControl Tipo, String Comando, byte& Chip, byte Posicion);
	/// ********************************************************************************************
	/// **** <summary> ACCION: Envia el comando por el puerto serie si es necesario </summary>	****
	/// **** <param name = "Comunicacion"> Clase Comunicacion via puerto serie		 </param>   ****
	/// ********************************************************************************************
	void EnviarComando(C_Comunicacion Comunicacion);
	
};


#endif

