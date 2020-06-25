// *************************************************************
// **** CLASE MULTILED    									****
// **** V1.0												****
// *************************************************************
// ***********************************************
// **** CONSTRUCTOR						      ****
// ***********************************************
C_MultiLed::C_MultiLed(String Comando, String& Paquete, byte& Chip, byte Posicion) {
	V_Comando	= Comando;
	V_Paquete 	= &Paquete;	//Asignacion de posicion de memoria al puntero V_Paquete
	V_Chip 		= &Chip; 	//Asignacion de posicion de memoria al puntero V_Chip
	V_Posicion 	= Posicion;
}
// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_MultiLed::CargarComando() {
	//Cargamos el valor si encontramos el comando, en la referencia de Paquete 
	V_Valor = BuscarComandoINT(*V_Paquete, V_Comando);
	// Cargar en el Chip si es distinto a 9 (no encontrado)
	if (V_Valor != 9) {
		//Asignamos al valor de V_Chip el cual modifica la referencia "Chip"
		bitWrite(*V_Chip, V_Posicion, V_Valor); 
	} 
}


// ***********************************************
// **** FUNCION INTERNA					      ****
// ***********************************************
byte C_MultiLed::BuscarComandoINT(String Texto, String Buscar) {
	int PosicionIni;
	int PosicionFin;
	String SIDEntrada;
	String SF_Resultado = "9";  //9 para no encontrado
	int Resultado = -1;
	PosicionIni = Texto.indexOf(Buscar);
	if (PosicionIni >= 0) {
		PosicionFin = Texto.indexOf("<", PosicionIni);
		if (PosicionFin >= 0) {
			/* Comando encontrado - carga de valor [01]> */
			SF_Resultado = Texto.substring(PosicionIni + 12, PosicionFin);
			// Analizamos el ID
			//SIDEntrada = Texto.substring(PosicionIni - 4, PosicionIni - 1);
			//ControlID(SIDEntrada, Texto, Buscar);
		}
	}
	if (SF_Resultado == "1"){
		return 1;
	} else if (SF_Resultado == "0"){
		return 0;
	} else {
		return 9;
	}
}

