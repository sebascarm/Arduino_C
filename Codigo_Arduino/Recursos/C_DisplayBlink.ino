// *************************************************************
// **** CLASE DISPLAY    									****
// **** V1.0												****
// *************************************************************
// ***********************************************
// **** CONSTRUCTOR						      ****
// ***********************************************
C_Display::C_Display(String Comando, String& Paquete, byte Cant_Digitos) {
	V_Comando 		= Comando;
	V_Paquete		= &Paquete;		//Asignacion de posicion de memoria al puntero V_Paquete
	V_Digitos 		= Cant_Digitos;
	V_DigitoChip	= new byte*[Cant_Digitos];			// Crea los PUNTEROS de array de Chips para los digitos
	V_Traductor 	= new TipoIntegrado[Cant_Digitos];  // Crea los array de Traductores asociados a cada digito
}
// ***********************************************
// **** PARAMETRO OBLIGATORIO			      ****
// ***********************************************
void C_Display::AsignarDigito(byte Digito, byte& Chip, TipoIntegrado Traductor) {
	V_DigitoChip[Digito] = &Chip;
	V_Traductor[Digito]  = Traductor;
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display::Rellenar(String Relleno){
	V_Relleno = Relleno;
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display::Blinker(String Comando){
	V_ComandoBlink = Comando;
	V_EsBlinker    = true;
	V_Tiempo = 500;
	//Guardar valor vacio con espacios 
	for (int I = 0; I < V_Digitos; I++) {V_ValorVacio = V_ValorVacio + " ";}
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display::Apagador(String Comando){
	V_ComandoApagador = Comando;
	V_TieneApago = true;
	//Guardar valor vacio con espacios 
	for (int I = 0; I < V_Digitos; I++) {V_ValorVacio = V_ValorVacio + " ";}
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display::ValorVacio(String Valor){
	V_ComandoVacio = Valor;
	//Guardar valor vacio con espacios 
	for (int I = 0; I < V_Digitos; I++) {V_ValorVacio = V_ValorVacio + " ";}
}


// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_Display::CargarComando() {
	String V_ValorSTR;
	//Cargamos el valor si encontramos el comando
	V_ValorSTR = BuscarComandoSTR(*V_Paquete, V_Comando);
	if (V_ValorSTR != "-1") {
		//revisamos si no devemos devolver vacio
		if (V_ValorSTR == V_ComandoVacio){
			V_ValorDisplay = V_ValorVacio;
		} else {
			//Rellenar los digitos vacios
			for (int I = V_ValorSTR.length(); I < V_Digitos; I++) {V_ValorSTR = V_Relleno + V_ValorSTR;}
			V_ValorDisplay = V_ValorSTR;
		}
		// IMPRIMIR - Revisamos si no esta parpadeando asignamos directamente
		if (!V_Blinking){
			CargarChip(V_ValorDisplay);
		}
	}
}
// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_Display::CargarBlinker() {
	String V_ValorSTR;
	// Revisamos si es Blinker // el Blinkeador se encarga de dibujar
	if (V_EsBlinker){
		V_ValorSTR = BuscarComandoSTR(*V_Paquete, V_ComandoBlink);
		if (V_ValorSTR != "-1") {
			//Establecer el estado del parpadeo
			if (V_ValorSTR == "1"){
				V_Tiempo.Reiniciar();
				V_Blinking = true;
			} else {
				V_Tiempo.Stop();
				V_Blinking = false;
				//Volvemos al estado original
				CargarChip(V_ValorDisplay);
			}
		}
	}		
}
// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_Display::CargarApagado() {
	String V_ValorSTR;
	// Revisamos tiene apagador
	if (V_TieneApago){
		V_ValorSTR = BuscarComandoSTR(*V_Paquete, V_ComandoApagador);
		if (V_ValorSTR != "-1") {
			//Establecer el estado del parpadeo
			if (V_ValorSTR == "1"){
				CargarChip(V_ValorVacio);
			} else {
				CargarChip(V_ValorDisplay);
			}
		}
	}		
}


// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_Display::Blinkeador (){
	//revisamos si esta parpadeando
	if (V_Blinking){
		if (V_Tiempo.SoloCheck()) {
			//Caundo llega el tiempo Invertimos el estado
			V_EstadoBlink = !V_EstadoBlink;
			//Cambio de estado. Dibujamos
			if (V_EstadoBlink){
				CargarChip(V_ValorVacio);
			} else {
				CargarChip(V_ValorDisplay);
			}
		}
	} 
}


// ***********************************************
// **** FUNCIONES INTERNAS				      ****
// ***********************************************

// ***********************************************
// **** CARGAR EN CHIP LOS VALORES A DIBUJAR  ****
// **** V1.0								  ****
// ***********************************************
void C_Display::CargarChip(String Valor){
	String V_Individual;
	byte V_ChipTemp;
	for (byte I = 0; I < V_Digitos; I++) {
		//Obtener el valor individual (un solo caracter)
		V_Individual = Valor.substring(I, I + 1);
		// Aplicar funcion segun el tipo de traductor
		switch (V_Traductor[I]){
			case Tipo1:	V_ChipTemp = FDSP_Integrado1(V_Individual); break;
			case Tipo2: V_ChipTemp = FDSP_Integrado2(V_Individual); break;
			case Tipo3: V_ChipTemp = FDSP_Integrado3(V_Individual); break;
			case Tipo4: V_ChipTemp = FDSP_Integrado4(V_Individual); break;
			case Tipo5: V_ChipTemp = FDSP_Integrado5(V_Individual); break;
			case Tipo6: V_ChipTemp = FDSP_Integrado6(V_Individual); break;
			case Tipo7: V_ChipTemp = FDSP_Integrado7(V_Individual); break;
			case Tipo8: V_ChipTemp = FDSP_Integrado8(V_Individual); break;
			case Tipo9: V_ChipTemp = FDSP_Integrado9(V_Individual); break;
			default:
				//si es un tipo erroneo
				V_ChipTemp = 0;
		}
		// Guardamos en el CHIP
		*V_DigitoChip[I] = V_ChipTemp;
	}
}

// ***********************************************
// **** BUSCAR EL VALOR DE UN COMANDO STRING  ****
// **** V1.0								  ****
// ***********************************************

String C_Display::BuscarComandoSTR(String Texto, String Buscar) { //SOLO UN COMANDO A LA VEZ ESTA RECIBIENDO
	int PosicionIni;
	int PosicionFin;
	String SIDEntrada;
	String SF_Resultado = "-1";
	PosicionIni = Texto.indexOf(Buscar);
	if (PosicionIni >= 0) {
		PosicionFin = Texto.indexOf("<", PosicionIni);
		if (PosicionFin >= 0) {
			// Comando encontrado - carga de valor [01]>
			SF_Resultado = Texto.substring(PosicionIni + 12, PosicionFin);
			//
			//SIDEntrada = Texto.substring(PosicionIni - 4, PosicionIni - 1);
			//ControlID(SIDEntrada, Texto, Buscar);
		}
	}
	if (SF_Resultado == "") {
		SF_Resultado = "-1";
	}
	return SF_Resultado;
}

// ***********************************************
// **** FUNCIONES DE TRADUCCION DE INTEGRADO  ****
// **** V1.0								  ****
// ***********************************************

byte C_Display::FDSP_Integrado1(String FDSP_Valor) {		// TAMBIEN EX E
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 130;  //10000010
	if (FDSP_Valor == "2") FDSP_Resultado = 118;  //01110110
	if (FDSP_Valor == "3") FDSP_Resultado = 214;  //11010110
	if (FDSP_Valor == "4") FDSP_Resultado = 154;  //10011010
	if (FDSP_Valor == "5") FDSP_Resultado = 220;  //11011100
	if (FDSP_Valor == "6") FDSP_Resultado = 252;  //11111100
	if (FDSP_Valor == "7") FDSP_Resultado = 134;  //10000110
	if (FDSP_Valor == "8") FDSP_Resultado = 254;  //11111110
	if (FDSP_Valor == "9") FDSP_Resultado = 158;  //10011110
	if (FDSP_Valor == "0") FDSP_Resultado = 238;  //11101110
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado2(String FDSP_Valor) {
	int FDSP_Resultado = 0;						// TAMBIEN EX D
	if (FDSP_Valor == "1") FDSP_Resultado = 144;  
	if (FDSP_Valor == "2") FDSP_Resultado = 122;  
	if (FDSP_Valor == "3") FDSP_Resultado = 218;  
	if (FDSP_Valor == "4") FDSP_Resultado = 150;
	if (FDSP_Valor == "5") FDSP_Resultado = 206;
	if (FDSP_Valor == "6") FDSP_Resultado = 238;
	if (FDSP_Valor == "7") FDSP_Resultado = 152;  
	if (FDSP_Valor == "8") FDSP_Resultado = 254;
	if (FDSP_Valor == "9") FDSP_Resultado = 158;
	if (FDSP_Valor == "0") FDSP_Resultado = 252;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado3(String FDSP_Valor) {
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 136;  
	if (FDSP_Valor == "2") FDSP_Resultado = 230;  
	if (FDSP_Valor == "3") FDSP_Resultado = 236;  
	if (FDSP_Valor == "4") FDSP_Resultado = 184;
	if (FDSP_Valor == "5") FDSP_Resultado = 124;
	if (FDSP_Valor == "6") FDSP_Resultado = 126;
	if (FDSP_Valor == "7") FDSP_Resultado = 200;  
	if (FDSP_Valor == "8") FDSP_Resultado = 254;
	if (FDSP_Valor == "9") FDSP_Resultado = 248;
	if (FDSP_Valor == "0") FDSP_Resultado = 222;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado4(String FDSP_Valor) {		//EX 21
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 132;
	if (FDSP_Valor == "2") FDSP_Resultado = 110;
	if (FDSP_Valor == "3") FDSP_Resultado = 236;
	if (FDSP_Valor == "4") FDSP_Resultado = 180;
	if (FDSP_Valor == "5") FDSP_Resultado = 248;
	if (FDSP_Valor == "6") FDSP_Resultado = 250;
	if (FDSP_Valor == "7") FDSP_Resultado = 140;
	if (FDSP_Valor == "8") FDSP_Resultado = 254;
	if (FDSP_Valor == "9") FDSP_Resultado = 188;
	if (FDSP_Valor == "0") FDSP_Resultado = 222;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado5(String FDSP_Valor) {		//EX 22
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 160;
	if (FDSP_Valor == "2") FDSP_Resultado = 118;
	if (FDSP_Valor == "3") FDSP_Resultado = 182;
	if (FDSP_Valor == "4") FDSP_Resultado = 172;
	if (FDSP_Valor == "5") FDSP_Resultado = 158;
	if (FDSP_Valor == "6") FDSP_Resultado = 222;
	if (FDSP_Valor == "7") FDSP_Resultado = 176;
	if (FDSP_Valor == "8") FDSP_Resultado = 254;
	if (FDSP_Valor == "9") FDSP_Resultado = 188;
	if (FDSP_Valor == "0") FDSP_Resultado = 250;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado6(String FDSP_Valor) {		//EX 23
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 96;
	if (FDSP_Valor == "2") FDSP_Resultado = 55;
	if (FDSP_Valor == "3") FDSP_Resultado = 118;
	if (FDSP_Valor == "4") FDSP_Resultado = 108;
	if (FDSP_Valor == "5") FDSP_Resultado = 94;
	if (FDSP_Valor == "6") FDSP_Resultado = 95;
	if (FDSP_Valor == "7") FDSP_Resultado = 112;
	if (FDSP_Valor == "8") FDSP_Resultado = 127;
	if (FDSP_Valor == "9") FDSP_Resultado = 124;
	if (FDSP_Valor == "0") FDSP_Resultado = 123;
	if (FDSP_Valor == ".") FDSP_Resultado = 128;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado7(String FDSP_Valor) {		//EX24
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 40;
	if (FDSP_Valor == "2") FDSP_Resultado = 103;
	if (FDSP_Valor == "3") FDSP_Resultado = 109;
	if (FDSP_Valor == "4") FDSP_Resultado = 169;
	if (FDSP_Valor == "5") FDSP_Resultado = 205;
	if (FDSP_Valor == "6") FDSP_Resultado = 207;
	if (FDSP_Valor == "7") FDSP_Resultado = 104;
	if (FDSP_Valor == "8") FDSP_Resultado = 239;
	if (FDSP_Valor == "9") FDSP_Resultado = 233;
	if (FDSP_Valor == "0") FDSP_Resultado = 238;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado8(String FDSP_Valor) {		//EX A
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 24;
	if (FDSP_Valor == "2") FDSP_Resultado = 182;
	if (FDSP_Valor == "3") FDSP_Resultado = 188;
	if (FDSP_Valor == "4") FDSP_Resultado = 216;
	if (FDSP_Valor == "5") FDSP_Resultado = 236;
	if (FDSP_Valor == "6") FDSP_Resultado = 238;
	if (FDSP_Valor == "7") FDSP_Resultado = 56;
	if (FDSP_Valor == "8") FDSP_Resultado = 254;
	if (FDSP_Valor == "9") FDSP_Resultado = 248;
	if (FDSP_Valor == "0") FDSP_Resultado = 126;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	if (FDSP_Valor == "-") FDSP_Resultado = 128;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado9(String FDSP_Valor) {		//EX BC
	int FDSP_Resultado = 0;
	if (FDSP_Valor == "1") FDSP_Resultado = 136;
	if (FDSP_Valor == "2") FDSP_Resultado = 214;
	if (FDSP_Valor == "3") FDSP_Resultado = 220;
	if (FDSP_Valor == "4") FDSP_Resultado = 184;
	if (FDSP_Valor == "5") FDSP_Resultado = 124;
	if (FDSP_Valor == "6") FDSP_Resultado = 63;
	if (FDSP_Valor == "7") FDSP_Resultado = 200;
	if (FDSP_Valor == "8") FDSP_Resultado = 254;
	if (FDSP_Valor == "9") FDSP_Resultado = 248;
	if (FDSP_Valor == "0") FDSP_Resultado = 238;
	if (FDSP_Valor == " ") FDSP_Resultado = 0;
	if (FDSP_Valor == "-") FDSP_Resultado = 16;
	return FDSP_Resultado;
}

