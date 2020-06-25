//#include "C_Comunicacion.h"

//Parametros
void C_Comunicacion::SecuenciaEnvio(int Secuencia) {
	V_SecuenciaEnvio = Secuencia;
}
//Acciones

void C_Comunicacion::EventoSerie() {
	// Almacenamos todo lo mas rapido posible
	V_DatosNuevos = false;
	// Debemos realizar la lectura lo mas rapido posible para no perder datos
	while (Serial.available()) {
		V_DatosNuevos = true;
		inChar = (char)Serial.read();
		V_Datos += inChar;
	}
	
	if (V_DatosNuevos){
		//Eliminamos ENTER
		BorrarEnter();
		if (inChar == '>') {    // Revisamos el ultimo caracter
			Pendiente = true;
			AnalizarPaquete();
		} else {
			Pendiente = false;  // Va a tener que recibir mas datos para marcar el final
		}
	}

	
}

void C_Comunicacion::BorrarEnter(){
	V_Datos.replace("\n", "");
	V_Datos.replace("\r", "");	
}

void C_Comunicacion::AnalizarPaquete(){ //hay uno o mas quetes enteros
	//[S01]>1MCP_LVNAV=0000<
	Error = false;
	String Detalle ="";
	//ControlSobrecarga(V_Datos);
	if (V_Datos.length() < 19 )			{Detalle = "Paquete < 19"; Error = true;}
	else if ('[' != V_Datos.charAt(0))	{Detalle = "Falta ["; Error = true;}
	else if (']' != V_Datos.charAt(4))	{Detalle = "Falta ]"; Error = true;}
	else if ('<' != V_Datos.charAt(5))	{Detalle = "Falta <"; Error = true;}
	else if ('_' != V_Datos.charAt(10))	{Detalle = "Falta _"; Error = true;}
	else if ('=' != V_Datos.charAt(16))	{Detalle = "Falta ="; Error = true;}
	
	if (Error == true){
		Detalle = "{Paq Error: |" + V_Datos + "| " + Detalle + "}";	
		Serial.println(Detalle);
		V_Datos ="";
		Pendiente = false;
	}
}

String C_Comunicacion::LeerComando() {
	// RECEPCION DEL SERVIDOR PUERTO SERIE
	V_Comando = "";
	if (Pendiente) {
		V_Comando = F_PrimerComando(V_Datos);
		if (V_Comando != "") {
			TipoComando(V_Comando);  // Carga el Modulo y el Tipo 
			V_Resto   =	F_RestoComando(V_Comando, V_Datos);
			if (V_Resto == "") { 
				Pendiente = false; 
			} else {
				//si hay resto tiene final
				Pendiente = true; 
			}
		}
		else {
			V_Resto   = "";
			Pendiente = false;
			V_Modulo = MOD_VACIO;
			V_TipoModulo = TIPO_VACIO;
		}
		V_Datos = V_Resto;
		V_Resto = "";             
		return V_Comando;
	
	} else {
		//si se llamo a la funcion cuando no estaba pendiente
		V_Modulo = MOD_VACIO;
		V_TipoModulo = TIPO_VACIO;
		return "";
	}
}

Modulos C_Comunicacion::Modulo() {
	return V_Modulo;
}

Tipos C_Comunicacion::TipoModulo() {
	return V_TipoModulo;
}


void C_Comunicacion::Enviar(String Comando, int Valor) {
	Serial.print(ID_Envio()); /* 1 Servidor /* 2 Placa --- */
	Serial.print(Comando);
	if (Valor != -1) {
		Serial.print(Valor);
	}
	Serial.print(">");
}
void C_Comunicacion::EnviarComentario(String Comando, int Valor) {
	String Mensaje;
	if (Valor != -1) {
		Mensaje = "{" + Comando + String(Valor) + "}";
	}
	else {
		Mensaje = "{" + Comando + "}";
	}
	Serial.print(Mensaje);
}




// Funciones internas
String C_Comunicacion::ID_Envio() {
	String ID_String;
	V_SecuenciaEnvio = V_SecuenciaEnvio + 1;
	if (V_SecuenciaEnvio == 100) {
		V_SecuenciaEnvio = 0;
	}
	if (V_SecuenciaEnvio < 10) {
		ID_String = "0" + String(V_SecuenciaEnvio);
	}
	else {
		ID_String = String(V_SecuenciaEnvio);
	}
	return "[" + Origen + ID_String + "]";
}



// ***********************************************************************************
// ****        FUNCION - CONTROL DE SOBRECARGA DEL BUFFER                         ****
// ***********************************************************************************
void C_Comunicacion::ControlSobrecarga(String Paquete) {
	if (Paquete.length() > 60) {  /* buffer casi lleno max 64, es probale q se pierdan partes de los paquets */
		Serial.print("{BUFFER_AL_LIMITE!=");
		Serial.print(Paquete.length());
		Serial.println("!-MAX_64}");
	}
}
// ***********************************************************************************
// ****        FUNCION - OBTENER EL PRIMER COMANDO                                ****
// ***********************************************************************************
String C_Comunicacion::F_PrimerComando(String Texto) {
	int PosicionIni;
	int PosicionFin;
	String Resultado = "";
	PosicionIni = Texto.indexOf("[");
	if (PosicionIni >= 0) {
		PosicionFin = Texto.indexOf(">", PosicionIni);
		if (PosicionFin >= 0) {
			// Comando encontrado - carga de valor
			Resultado = Texto.substring(PosicionIni, PosicionFin + 1);
		}
	}
	return Resultado;
}
// ***********************************************************************************
// ****        FUNCION - OBTENER EL RESTO DE LOS COMANDOS                         ****
// ***********************************************************************************
String  C_Comunicacion::F_RestoComando(String PrimerComando, String Texto) {
	int PosicionIni;
	int PosicionFin;
	int Longitud;
	String Resultado = "";
	// revisamos si hay mas de un comando
	if (Texto.length() > PrimerComando.length()) {
		PosicionIni = Texto.indexOf(PrimerComando); // siempre lo encuentra debido a que el primer comando esta en el texto
		Longitud = PrimerComando.length();
		Resultado = Texto.substring(PosicionIni + Longitud);
	}
	return Resultado;
}

// ***********************************************************************************
// ****        FUNCION - BUSCAR TIPO DE COMANDO                                   ****
// ***********************************************************************************
void  C_Comunicacion::TipoComando(String Texto) {
	int PosicionIni;
	int PosicionFin;
	String Modulo = "-1";
	String Tipo = "-1";
	String Resultado = "-1";

	PosicionIni = Texto.indexOf("<");
	if (PosicionIni >= 0) {
		PosicionFin = Texto.indexOf(">", PosicionIni);
		if (PosicionFin >= 0) {
			// Comando encontrado - carga de valor del modulo
			Modulo = Texto.substring(PosicionIni + 2, PosicionIni + 5);
			if (Modulo == "ENC") { V_Modulo = ENC; }
			else if (Modulo == "INT") { V_Modulo = INTERNO; }
			else if (Modulo == "MCP") { V_Modulo = MCP; }
			else if (Modulo == "THR") { V_Modulo = THR; }
			else if (Modulo == "MIP") { V_Modulo = MIP; }
			else if (Modulo == "FIR") { V_Modulo = FIR; }
			else if (Modulo == "YOK") { V_Modulo = YOK; }
			else { V_Modulo = MOD_VACIO; }

			// Comando encontrado - carga de tipo de modulo
			Tipo = Texto.substring(PosicionIni + 6, PosicionIni + 7);
			if (Tipo == "L") { V_TipoModulo = LED; }
			else if (Tipo == "T") { V_TipoModulo = TEST; }
			else if (Tipo == "D") { V_TipoModulo = DISP; }
			else if (Tipo == "B") { V_TipoModulo = DISP_OFF; }	// Display APAGADOS  (BIAS)
			else if (Tipo == "F") { V_TipoModulo = DISP_FLASH; }

			else if (Tipo == "S") { V_TipoModulo = SERVO; }
			else if (Tipo == "M") { V_TipoModulo = MOTOR; }
			else { V_TipoModulo = TIPO_VACIO; }
		}
	}
}