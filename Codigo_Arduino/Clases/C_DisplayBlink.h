// C_Display.h

#ifndef _C_DISPLAY_h
#define _C_DISPLAY_h


/// ********************************************************************************************
/// **** <summary> CLASE: Definicion de Display								</summary>		****
/// ********************************************************************************************
class C_Display {
 	private:
		String V_Comando;				//Comando de puerto serie
		String *V_Paquete;				//Puntero a Paquete
		String V_Relleno 		= "0";	//Relleno a utlizar 
		String V_ValorDisplay;			//Valor con rellenos a usar   
		String V_ComandoVacio 	 ="";   //Valor a recibir para entregar el display vacio
		String V_ComandoApagador ="";	//Comando que recibe para apagar el display
		bool V_TieneApago		 = false; //si posee apagado 
		// Cantidad de Digitos
		byte V_Digitos;
		// Puntero de Array de Chips (** Es un * por Array y * por Puntero)
		byte **V_DigitoChip = NULL; 
		// Traductor a utilizar
 		TipoIntegrado *V_Traductor = NULL; // Array de Traductor (* Es un Array)
 		
 		//Funciones para blinkear
 		C_Timer V_Tiempo;
 		String 	V_ComandoBlink;
 		bool 	V_EsBlinker 	= false; //Establece si puede parpadear
		bool	V_Blinking 		= false; //Determina si esta parpadeando	
		bool   	V_EstadoBlink 	= false; //Estado del blinker (encendido o apagado)
		String 	V_ValorVacio   	= ""; 	 //Valor para poner espacion cuando esta vacio
		
		//Funciones internas
		String BuscarComandoSTR(String Texto, String Buscar);
		void   CargarChip(String Valor);
		byte FDSP_Integrado1(String FDSP_Valor);
		byte FDSP_Integrado2(String FDSP_Valor);
		byte FDSP_Integrado3(String FDSP_Valor);
		byte FDSP_Integrado4(String FDSP_Valor);
		byte FDSP_Integrado5(String FDSP_Valor);
		byte FDSP_Integrado6(String FDSP_Valor);
		byte FDSP_Integrado7(String FDSP_Valor);
		byte FDSP_Integrado8(String FDSP_Valor);
		byte FDSP_Integrado9(String FDSP_Valor);


	public:
	 	/// ****************************************************************************
		/// **** CONSTRUCTOR DE LA CLASE 									 		****
		/// **** 	Comando: 		Comando que recibe para dibujar en el control	****
		/// **** 	Paquete: 		Referencia al paquete de datos individual 		****
		/// **** 	Cant_Digitos: 	Cantidad de digitos del Display		     		****
		/// ****************************************************************************
		C_Display(String Comando, String& Paquete, byte Cant_Digitos);

		/// ********************************************************************************************************
		/// **** PARAMETRO OBLIGATORIO: Asignacion de Chip y Traductor a utilizar por cada digito del Display 	****
		/// **** 	Digito: 	Numero de Digito del Display Comenzando por 0 de izquierda a derecha			****
		/// **** 	Chip: 		Referencia a un Chip al cual se le asigna el Digito								**** 
		/// **** 	Traductor: 	Traductor a utilizar (Tipo1, Tipo2 .. Tipo9)								   	****
		/// ********************************************************************************************************
		void AsignarDigito(byte Digito, byte& Chip, TipoIntegrado Traductor);
		
		/// ******************************************************************
		/// **** PARAMETRO OPCIONAL: Relleno para los digitos faltantes   ****
		/// **** 	Relleno: Valor de relleno. Ej: 0, " "				  ****			
		/// ******************************************************************
		void Rellenar(String Relleno);

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

