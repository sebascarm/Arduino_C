// C_Pote.h

#ifndef _C_POTE_h
#define _C_POTE_h


#include "C_Comunicacion.h"



/// ****************************************************************************
/// **** <summary> CLASE: Potenciometro						</summary>		****
/// ****************************************************************************
class C_Pote {
private:
	int F_PotePromedio(byte F_PinNumber, int Cant_Lecturas, int MapeoPote);
	int F_PoteSube(int F_Valor, int F_ValorAnt, int F_Sube, int Ruido);
	int F_PoteValor(int F_Valor, int F_ValorAnt, int F_Sube);
	int F_PoteDigital(int Valor, int Anterior, int Velocidad, int& VelocidadActual);


	int V_PinPote;
	int V_PoteSube;
		
	int V_ValorPromedio; //Valor promedio de lecturas reales
		
	int V_ValAnt;		 //revisar valor inicial
	int V_Valor;		 //Valor filtrado
	int V_ValorDigital;	 //Valor 0 o 1
	
	String V_Comando;

	// Parametros Generales
	int V_CantLecturas  =5;	  // cantidad de lecturas para el promedio
	int V_Mapeo			=100; // en cuanto dividimos el 1024 para promediar
	int V_Ruido			=2;	  // Margen de ruido tolerable despues del promedio

	//Cantidad de lecturas antes de enviar un valor
	int V_Velocidad = 2;
	int V_VelActual = 2;

public:
	/// ***********************************************************************************************************
	/// **** <summary> CONSTRUCTOR DE LA CLASE </summary>													   ****
	/// **** <param name = "Comando"> Definicion de Comando que envia el potenciometro	</param>			   ****
	/// **** <param name = "PinPote"> Numero de Pin de la placa donde esta conectado el Potenciometro </param> ****
	/// ***********************************************************************************************************
	C_Pote(String Comando, byte PinPote);
	/// ********************************************************************************************************************************
	/// **** <summary> PARAMETROS OPCIONALES: Configuracion de como se debe leer el potenciometro </summary>						****
	/// **** <param name = "CantLecturas"> Cantidad de Lecturas para obtener el promedio. Default: 5    		   </param>			****
	/// **** <param name = "Mapeo"> Mapeo del resultado (0 .. 1024) de cada lectura, Valor Maximo devuelto. Default: 100 </param>   ****
	/// **** <param name = "Ruido"> Ruido por interferencia tolerable posterior al mapeo y promedio. Default: 2 		   </param> ****
	/// ********************************************************************************************************************************
	void ParamGenerales(int CantLecturas, int Mapeo, int Ruido);
	/// *********************************************************************************************************************************************************
	/// **** <summary> PARAMETROS OPCIONAL: Velocidad del Potenciometro (Aplica solo a Envio Digital) </summary>	                                         ****
	/// **** <param name = "Velocidad"> Valor de Velocidad de 0 en Adelante (0 Es el mas rapido). Default: 2 (2 Lecturas antes de enviar un cambio) </param> ****
	/// *********************************************************************************************************************************************************
	void Velocidad(int Velocidad);

	/// ************************************************************************************************************
	/// **** <summary> ACCION: Envia el comando por el puerto si se mueve el potenciometro (0 o 1) </summary>	****
	/// **** <param name = "Comunicacion"> Clase Comunicacion via puerto serie		 </param>				    ****
	/// ************************************************************************************************************
	void EnviarDigital(C_Comunicacion Comunicacion);	//Devuelve el valor del pote en 0 y 1
	
	/// **************************************************************************************************************************************************
	/// **** <summary> ACCION: Envia el comando por el puerto si se mueve el potenciometro (0 hasta el Valor Maximo Establecido por Mapeo) </summary> ****
	/// **** <param name = "Comunicacion"> Clase Comunicacion via puerto serie		 </param>														  ****
	/// **************************************************************************************************************************************************
	void EnviarAnalogo(C_Comunicacion Comunicacion);  //Devuelve el valor del pote
};



#endif

