C_Pote::C_Pote(String Comando, byte PinPote){
	V_Comando = Comando;
	V_PinPote = PinPote;
}

void C_Pote::ParamGenerales(int CantLecturas, int Mapeo, int Ruido) {
	V_CantLecturas = CantLecturas;
	V_Mapeo = Mapeo;
	V_Ruido = Ruido;
}

void C_Pote::Velocidad(int Velocidad) {
	V_Velocidad = Velocidad;
	V_VelActual = Velocidad;
}

void C_Pote::EnviarDigital(C_Comunicacion Comunicacion) {
	V_ValAnt		= V_Valor;														// Asignamos el valor anterior
	V_ValorPromedio = F_PotePromedio(V_PinPote, V_CantLecturas, V_Mapeo);			// Obtenemos el promedio y Mapeo General
	V_PoteSube		= F_PoteSube (V_ValorPromedio, V_ValAnt, V_PoteSube, V_Ruido);  //Determinamos si sube o baja (1 o -1)
	V_Valor			= F_PoteValor(V_ValorPromedio, V_ValAnt, V_PoteSube);			// Devuelve el Valor Filtrado
	V_ValorDigital	= F_PoteDigital(V_Valor, V_ValAnt, V_Velocidad, V_VelActual);	// Digitaliza el pote (0 o 1)
	// ENVIAR MOVIMIENTO
	if (V_ValorDigital != -1) {
		Comunicacion.Enviar(V_Comando, V_ValorDigital);
	}
}

void C_Pote::EnviarAnalogo(C_Comunicacion Comunicacion) {
	V_ValAnt = V_Valor;														// Asignamos el valor anterior
	V_ValorPromedio = F_PotePromedio(V_PinPote, V_CantLecturas, V_Mapeo);	// Obtenemos el promedio y Mapeo General
	V_Valor = F_PoteValor(V_ValorPromedio, V_ValAnt, V_PoteSube);			// Devuelve el Valor Filtrado
	// ENVIAR MOVIMIENTO
	if (V_Valor != -V_ValAnt) {
		Comunicacion.Enviar(V_Comando, V_Valor);
	}
}





// ***********************************************************************************
// ****  FUNCION PROMEDIO DE LECTURAS Y MAPEO GENERAL							  ****
// ***********************************************************************************
int C_Pote::F_PotePromedio(byte F_PinNumber, int Cant_Lecturas, int MapeoPote) {
	int F_Sensor;
	int F_Suma = 0;
	int F_Result;
	for (int i = 1; i <= Cant_Lecturas; i++) {
		F_Sensor = map(analogRead(F_PinNumber), 0, 1024, 0, MapeoPote);
		F_Suma = F_Suma + F_Sensor;
	}
	F_Result = F_Suma / Cant_Lecturas;
	return F_Result;
}
// ********************************************************************************
// ****        FUNCION - SUBE O BAJA										   ****
// ********************************************************************************
int C_Pote::F_PoteSube(int F_Valor, int F_ValorAnt, int F_Sube, int Ruido) {
	int F_Resultado = F_Sube;
	if ((F_Valor + Ruido) < F_ValorAnt) {
		F_Resultado = -1;
	}
	else if ((F_Valor - Ruido) > F_ValorAnt) {
		F_Resultado = 1;
	}
	return F_Resultado;
}

// ***********************************************************************************
// ****        FUNCION - VALOR FINAL 											  ****
// ***********************************************************************************
int C_Pote::F_PoteValor(int F_Valor, int F_ValorAnt, int F_Sube) {
	int F_Resultado = F_ValorAnt;
	if (F_Sube == 1) {
		if (F_Valor > F_ValorAnt) {
			F_Resultado = F_Valor;
		}
	}
	if (F_Sube == -1) {
		if (F_Valor < F_ValorAnt) {
			F_Resultado = F_Valor;
		}
	}
	return F_Resultado;
}
// ***********************************************************************************
// ****        FUNCION - MOVIMIENTO DE POTENCIOMETRO (para remplazar MoverPote)   ****
// ***********************************************************************************
int C_Pote::F_PoteDigital(int Valor, int Anterior, int Velocidad, int& VelocidadActual) {
	int F_Resultado = -1;
	if (Anterior < Valor) { F_Resultado = 0; }
	if (Anterior > Valor) { F_Resultado = 1; }
	if ((Valor < 10) && (Anterior > 90)) { F_Resultado = 0; }
	if ((Valor > 90) && (Anterior < 10)) { F_Resultado = 1; }
	if (F_Resultado != -1) {
		if (VelocidadActual == 0) {  //llego
			VelocidadActual = Velocidad;
		}
		else {                              // no llego
			VelocidadActual = VelocidadActual - 1;
			F_Resultado = -1;
		}
	}
	return F_Resultado;
}