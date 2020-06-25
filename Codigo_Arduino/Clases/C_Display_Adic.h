#ifndef _C_DISPLAYADIC_h
#define _C_DISPLAYADIC_h

/// ************************************************
/// ****  CLASE: Clase derivada de DISPLAY		****
/// ************************************************
class C_Display_Adic : public C_Display {

	private:
		bool V_TieneApago		 = false; //si posee apagado 
		String V_ComandoApagador ="";	//Comando que recibe para apagar el display
		String V_ComandoVacio 	 ="";   //Valor a recibir para entregar el display vacio
		//Funciones para blinkear
 		C_Timer V_Tiempo;
 		String 	V_ComandoBlink;
 		bool 	V_EsBlinker 	= false; //Establece si puede parpadear
		bool	V_Blinking 		= false; //Determina si esta parpadeando	
		bool   	V_EstadoBlink 	= false; //Estado del blinker (encendido o apagado)
		String 	V_ValorVacio   	= ""; 	 //Valor para poner espacion cuando esta vacio
		
	public:
		/// ****************************************************************************
		/// **** CONSTRUCTOR DE LA CLASE 									 		****
		/// **** 	Comando: 		Comando que recibe para dibujar en el control	****
		/// **** 	Paquete: 		Referencia al paquete de datos individual 		****
		/// **** 	Cant_Digitos: 	Cantidad de digitos del Display		     		****
		/// **** 	PASA TODOS LOS PARAMETROS AL PADRE								****
		/// ****************************************************************************
		C_Display_Adic(String Comando, String& Paquete, byte Cant_Digitos):C_Display(Comando, Paquete, Cant_Digitos){};

		/// ************************************************************************
		/// **** PARAMETRO OPCIONAL: Especifica que el display puede parpadear  ****
		/// **** 	Comando: Comando que activa o desactiva el parpadeo.   		****			
		/// ****          	 Ej: >1MCP_FDISP=1< // >1MCP_FDISP=0< 				****
		/// ************************************************************************
		void Blinker(String Comando);

		/// ************************************************************************
		/// **** PARAMETRO OPCIONAL: Especifica que el display puede Apagarse   ****
		/// **** 	Comando: Comando que activa o desactiva el Apagado.   		****			
		/// ****          	 Ej: >1MCP_BDISP=1< // >1MCP_BDISP=0< 				****
		/// ************************************************************************
		void Apagador(String Comando);

		/// ***************************************************************************************************
		/// **** PARAMETRO OPCIONAL: Especifica que un valor que puede recibir para poner el display vacio ****
		/// ***************************************************************************************************
		void ValorVacio(String Valor);

		/// ********************************************************************************************
		/// **** ACCION: Carga el comando recibido en la variable del Chip 						   	****
		/// ********************************************************************************************
		void CargarComando();

		/// ********************************************************************************************
		/// **** ACCION: Carga el comando recibido en la variable del Chip 						   	****
		/// ********************************************************************************************
		void CargarBlinker();

		/// ********************************************************************************************
		/// **** ACCION: Carga el comando recibido en la variable del Chip 						   	****
		/// ********************************************************************************************
		void CargarApagado();

		/// ****************************************************************************************************
		/// **** ACCION: Accion que debe realizar en cada loop los displays que son Blinqueadores.		   	****
		/// **** 		 Este metodo se encarga de revisar el estado y parpadear en caso de ser necesario	****
		/// ****************************************************************************************************
		void Blinkeador();


};

#endif

