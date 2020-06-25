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
	V_Traductor [Digito] = Traductor;
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display::Rellenar(String Relleno){
	V_Relleno = Relleno;
}

// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_Display::CargarComando() {
	String V_ValorSTR;
	//Cargamos el valor si encontramos el comando
	V_ValorSTR = BuscarComandoSTR(V_Comando);
	if (V_ValorSTR != "-1") {
		//Rellenar los digitos vacios
		for (int I = V_ValorSTR.length(); I < V_Digitos; I++) {V_ValorSTR = V_Relleno + V_ValorSTR;}
		V_ValorDisplay = V_ValorSTR;
		// IMPRIMIR 
		CargarChip(V_ValorDisplay);
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
	for (byte I = 0; I < V_Digitos; I++) {
		//Obtener el valor individual (un solo caracter)
		V_Individual = Valor.charAt(I);
		// Aplicar funcion segun el tipo de traductor
		switch (V_Traductor[I]){
			case Tipo1:	V_ChipTemp = FDSP_Integrado1(); break;
			case Tipo2: V_ChipTemp = FDSP_Integrado2(); break;
			case Tipo3: V_ChipTemp = FDSP_Integrado3(); break;
			case Tipo4: V_ChipTemp = FDSP_Integrado4(); break;
			case Tipo5: V_ChipTemp = FDSP_Integrado5(); break;
			case Tipo6: V_ChipTemp = FDSP_Integrado6(); break;
			case Tipo7: V_ChipTemp = FDSP_Integrado7(); break;
			case Tipo8: V_ChipTemp = FDSP_Integrado8(); break;
			case Tipo9: V_ChipTemp = FDSP_Integrado9(); break;
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

String C_Display::BuscarComandoSTR(String V_Com_Buscado) { //SOLO UN COMANDO A LA VEZ ESTA RECIBIENDO
	int PosicionIni;
	int PosicionFin;
	String SIDEntrada;
	String SF_Resultado = "-1";
	PosicionIni = V_Paquete->indexOf(V_Com_Buscado);
	if (PosicionIni >= 0) {
		PosicionFin = V_Paquete->indexOf("<", PosicionIni);
		if (PosicionFin >= 0) {
			// Comando encontrado - carga de valor [01]>
			SF_Resultado = V_Paquete->substring(PosicionIni + 12, PosicionFin);
			//
			//SIDEntrada = Texto.substring(PosicionIni - 4, PosicionIni - 1);
			//ControlID(SIDEntrada, Texto, V_Com_Buscado);
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

byte C_Display::FDSP_Integrado1() {		// TAMBIEN EX E
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 130;  //10000010
	if (V_Individual == '2') FDSP_Resultado = 118;  //01110110
	if (V_Individual == '3') FDSP_Resultado = 214;  //11010110
	if (V_Individual == '4') FDSP_Resultado = 154;  //10011010
	if (V_Individual == '5') FDSP_Resultado = 220;  //11011100
	if (V_Individual == '6') FDSP_Resultado = 252;  //11111100
	if (V_Individual == '7') FDSP_Resultado = 134;  //10000110
	if (V_Individual == '8') FDSP_Resultado = 254;  //11111110
	if (V_Individual == '9') FDSP_Resultado = 158;  //10011110
	if (V_Individual == '0') FDSP_Resultado = 238;  //11101110
	if (V_Individual == ' ') FDSP_Resultado = 0;	//00000000
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado2() {
	int FDSP_Resultado = 0;						// TAMBIEN EX D
	if (V_Individual == '1') FDSP_Resultado = 144;  
	if (V_Individual == '2') FDSP_Resultado = 122;  
	if (V_Individual == '3') FDSP_Resultado = 218;  
	if (V_Individual == '4') FDSP_Resultado = 150;
	if (V_Individual == '5') FDSP_Resultado = 206;
	if (V_Individual == '6') FDSP_Resultado = 238;
	if (V_Individual == '7') FDSP_Resultado = 152;  
	if (V_Individual == '8') FDSP_Resultado = 254;
	if (V_Individual == '9') FDSP_Resultado = 158;
	if (V_Individual == '0') FDSP_Resultado = 252;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado3() {
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 136;  
	if (V_Individual == '2') FDSP_Resultado = 230;  
	if (V_Individual == '3') FDSP_Resultado = 236;  
	if (V_Individual == '4') FDSP_Resultado = 184;
	if (V_Individual == '5') FDSP_Resultado = 124;
	if (V_Individual == '6') FDSP_Resultado = 126;
	if (V_Individual == '7') FDSP_Resultado = 200;  
	if (V_Individual == '8') FDSP_Resultado = 254;
	if (V_Individual == '9') FDSP_Resultado = 248;
	if (V_Individual == '0') FDSP_Resultado = 222;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado4() {		//EX 21
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 132;
	if (V_Individual == '2') FDSP_Resultado = 110;
	if (V_Individual == '3') FDSP_Resultado = 236;
	if (V_Individual == '4') FDSP_Resultado = 180;
	if (V_Individual == '5') FDSP_Resultado = 248;
	if (V_Individual == '6') FDSP_Resultado = 250;
	if (V_Individual == '7') FDSP_Resultado = 140;
	if (V_Individual == '8') FDSP_Resultado = 254;
	if (V_Individual == '9') FDSP_Resultado = 188;
	if (V_Individual == '0') FDSP_Resultado = 222;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado5() {		//EX 22
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 160;
	if (V_Individual == '2') FDSP_Resultado = 118;
	if (V_Individual == '3') FDSP_Resultado = 182;
	if (V_Individual == '4') FDSP_Resultado = 172;
	if (V_Individual == '5') FDSP_Resultado = 158;
	if (V_Individual == '6') FDSP_Resultado = 222;
	if (V_Individual == '7') FDSP_Resultado = 176;
	if (V_Individual == '8') FDSP_Resultado = 254;
	if (V_Individual == '9') FDSP_Resultado = 188;
	if (V_Individual == '0') FDSP_Resultado = 250;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado6() {		//EX 23
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 96;
	if (V_Individual == '2') FDSP_Resultado = 55;
	if (V_Individual == '3') FDSP_Resultado = 118;
	if (V_Individual == '4') FDSP_Resultado = 108;
	if (V_Individual == '5') FDSP_Resultado = 94;
	if (V_Individual == '6') FDSP_Resultado = 95;
	if (V_Individual == '7') FDSP_Resultado = 112;
	if (V_Individual == '8') FDSP_Resultado = 127;
	if (V_Individual == '9') FDSP_Resultado = 124;
	if (V_Individual == '0') FDSP_Resultado = 123;
	if (V_Individual == '.') FDSP_Resultado = 128;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado7() {		//EX24
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 40;
	if (V_Individual == '2') FDSP_Resultado = 103;
	if (V_Individual == '3') FDSP_Resultado = 109;
	if (V_Individual == '4') FDSP_Resultado = 169;
	if (V_Individual == '5') FDSP_Resultado = 205;
	if (V_Individual == '6') FDSP_Resultado = 207;
	if (V_Individual == '7') FDSP_Resultado = 104;
	if (V_Individual == '8') FDSP_Resultado = 239;
	if (V_Individual == '9') FDSP_Resultado = 233;
	if (V_Individual == '0') FDSP_Resultado = 238;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado8() {		//EX A
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 24;
	if (V_Individual == '2') FDSP_Resultado = 182;
	if (V_Individual == '3') FDSP_Resultado = 188;
	if (V_Individual == '4') FDSP_Resultado = 216;
	if (V_Individual == '5') FDSP_Resultado = 236;
	if (V_Individual == '6') FDSP_Resultado = 238;
	if (V_Individual == '7') FDSP_Resultado = 56;
	if (V_Individual == '8') FDSP_Resultado = 254;
	if (V_Individual == '9') FDSP_Resultado = 248;
	if (V_Individual == '0') FDSP_Resultado = 126;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	if (V_Individual == '-') FDSP_Resultado = 128;
	return FDSP_Resultado;
}
byte C_Display::FDSP_Integrado9() {		//EX BC
	int FDSP_Resultado = 0;
	if (V_Individual == '1') FDSP_Resultado = 136;
	if (V_Individual == '2') FDSP_Resultado = 214;
	if (V_Individual == '3') FDSP_Resultado = 220;
	if (V_Individual == '4') FDSP_Resultado = 184;
	if (V_Individual == '5') FDSP_Resultado = 124;
	if (V_Individual == '6') FDSP_Resultado = 63;
	if (V_Individual == '7') FDSP_Resultado = 200;
	if (V_Individual == '8') FDSP_Resultado = 254;
	if (V_Individual == '9') FDSP_Resultado = 248;
	if (V_Individual == '0') FDSP_Resultado = 238;
	if (V_Individual == ' ') FDSP_Resultado = 0;
	if (V_Individual == '-') FDSP_Resultado = 16;
	return FDSP_Resultado;
}

