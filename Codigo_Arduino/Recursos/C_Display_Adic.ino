// *************************************************************
// **** CLASE DISPLAY ADIC. HEREDADA DE DISPLAY				****
// **** V1.0												****
// *************************************************************
// ***********************************************
// **** CONSTRUCTOR						      ****
// ***********************************************
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display_Adic::Blinker(String Comando){
	V_EsBlinker    = true;
	V_ComandoBlink = Comando;
	V_Tiempo = 500;
	//Guardar valor vacio con espacios 
	for (int I = 0; I < V_Digitos; I++) {V_ValorVacio = V_ValorVacio + " ";}
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display_Adic::Apagador(String Comando){
	V_TieneApago = true;
	V_ComandoApagador = Comando;
	//Guardar valor vacio con espacios 
	for (int I = 0; I < V_Digitos; I++) {V_ValorVacio = V_ValorVacio + " ";}
}
// ***********************************************
// **** PARAMETRO OPCIONAL				      ****
// ***********************************************
void C_Display_Adic::ValorVacio(String Valor){
	V_ComandoVacio = Valor;
	//Guardar valor vacio con espacios 
	for (int I = 0; I < V_Digitos; I++) {V_ValorVacio = V_ValorVacio + " ";}
}

// ***********************************************
// **** ACCION							      ****
// ***********************************************
void C_Display_Adic::CargarComando() {
	String V_ValorSTR;
	//Cargamos el valor si encontramos el comando
	V_ValorSTR = BuscarComandoSTR(V_Comando);
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
void C_Display_Adic::CargarBlinker() {
	String V_ValorSTR;
	// Revisamos si es Blinker // el Blinkeador se encarga de dibujar
	if (V_EsBlinker){
		V_ValorSTR = BuscarComandoSTR(V_ComandoBlink);
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
void C_Display_Adic::CargarApagado() {
	String V_ValorSTR;
	// Revisamos tiene apagador
	if (V_TieneApago){
		V_ValorSTR = BuscarComandoSTR(V_ComandoApagador);
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
void C_Display_Adic::Blinkeador (){
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

