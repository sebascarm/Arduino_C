// C_Display.h

#ifndef _C_DISPLAY_h
#define _C_DISPLAY_h


/// ********************************************************************************************
/// **** <summary> CLASE: Definicion de Display								</summary>		****
/// ********************************************************************************************
class C_Display {
 	protected:
		String V_Comando;				//Comando de puerto serie
		String *V_Paquete;				//Puntero a Paquete
		String V_Relleno 		="0";	//Relleno a utlizar 
		String V_ValorDisplay;			//Valor con rellenos a usar   
		byte V_Digitos;					// Cantidad de Digitos
		byte **V_DigitoChip = NULL; 	// Puntero de Array de Chips (** Es un * por Array y * por Puntero)
		TipoIntegrado *V_Traductor = NULL; // Array de Traductor (* Es un Array)
 		
 		//Variables para la carga de chip
 		char V_Individual;
		byte V_ChipTemp;

		//Funciones internas
		String BuscarComandoSTR(String V_Com_Buscado);
		void   CargarChip(String Valor);
		
		byte FDSP_Integrado1();
		byte FDSP_Integrado2();
		byte FDSP_Integrado3();
		byte FDSP_Integrado4();
		byte FDSP_Integrado5();
		byte FDSP_Integrado6();
		byte FDSP_Integrado7();
		byte FDSP_Integrado8();
		byte FDSP_Integrado9();

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

		/// ********************************************************************************************
		/// **** ACCION: Carga el comando recibido en la variable del Chip 						   	****
		/// ********************************************************************************************
		void CargarComando();


};

#endif

