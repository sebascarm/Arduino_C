// C_MultiLed.h

#ifndef _C_MULTILED_h
#define _C_MULTILED_h

class C_MultiLed {
 private:
	 byte BuscarComandoINT(String Texto, String Buscar);
	 String V_Comando;
	 String	*V_Paquete; //Puntero a Paquete
	 byte 	*V_Chip; 	//Puntero a Chip
	 byte 	V_Posicion;
	 
	 byte 	V_Valor 	= 9; // Usamos el 9 para identificar cuando no se encuentra el valor
	 
 public:
	 /// ***********************************************************************************************
	 /// **** CONSTRUCTOR DE LA CLASE 									  							****
	 /// **** 	Comando:	Comando que recibe encender LED				 							****
	 /// **** 	Paquete:	Referencia al paquete de datos individual para que realice la busqueda	****
	 /// **** 	Chip:		Referencia a un Chip donde se va a escribir	     						****
	 /// **** 	Posicion:	Posicion del Chip donde escribir el LED	     							****
	 /// ***********************************************************************************************
	 C_MultiLed(String Comando, String& Paquete, byte& Chip, byte Posicion);
	 
	 /// ***********************************************************************************
	 /// **** ACCION: Busca en el Paquete el Comando especificado y lo carga en el Chip ****
	 /// ***********************************************************************************
	  void CargarComando();
};


#endif

