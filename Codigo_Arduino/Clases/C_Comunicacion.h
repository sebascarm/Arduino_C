// C_Comunicacion.h

#ifndef _C_COMUNICACION_h
#define _C_COMUNICACION_h


class C_Comunicacion {
private:
	bool V_DatosNuevos;
	//char 	inChar ="";					//LECTURA CRUDA DEL PUERTO
	char 	inChar = 0;					//LECTURA CRUDA DEL PUERTO
	String  V_Datos = "";				//DATOS DE ENTRADA SERIE
	boolean V_Cadena_Completa = false;  //FIN DE DATOS SERIE
	
	int V_SecuenciaEnvio = 0;
	String ID_Envio();
	String Origen = "A"; // A: Arduino - F: Feudrino
	
	
	String V_Comando = "";
	String V_Resto = "";
	// MODULOS
	Modulos V_Modulo;
	Tipos V_TipoModulo;

	bool Error; //Variable para el analisis de paquete
	void BorrarEnter();
	void AnalizarPaquete();
	void ControlSobrecarga(String Paquete);
	void TipoComando(String Texto);

	String F_PrimerComando(String Texto);
	String F_RestoComando(String PrimerComando, String Texto);



public:
	//Estado si tiene algo en cola
	bool Pendiente = false;
	//Parametros-s
	void SecuenciaEnvio(int Secuencia);
	// Acciones
	void EventoSerie();
	String LeerComando();
	Modulos Modulo();
	Tipos TipoModulo();
	void Enviar(String Comando, int Valor = -1);
	void EnviarComentario(String COMANDO, int VALOR = -1);
	

};


#endif

