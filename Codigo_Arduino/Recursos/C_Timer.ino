// 
// 
// 

/***********************************************************************************/
/****       FUNCIONES DE LA CLASE TIMER                                         ****/
/***********************************************************************************/

C_Timer::C_Timer() {
	V_Stop = false;
	V_Tiempo = millis();
}
C_Timer::C_Timer(int Tiempo) {
	V_Stop = false;
	Total = Tiempo;
	V_Tiempo = millis();
}
void C_Timer::operator = (int Tiempo) {
	V_Stop = false;
	Total = Tiempo;
	V_Tiempo = millis();
}
void C_Timer::Reiniciar() {
	V_Stop = false;
	V_Tiempo = millis();
}
int C_Timer::Tiempo() {
	if (!V_Stop) {
		V_TActual = millis();
		V_Duracion = V_TActual - V_Tiempo;
		V_TRestante = Total - V_Duracion;
		if (V_TRestante <= 0) {
			V_TRestante = 0;
		};
	}
	return (V_TRestante);
}
void C_Timer::Check() {
	if (!V_Stop) {
		V_TActual = millis();
		V_Duracion = V_TActual - V_Tiempo;
		V_TRestante = Total - V_Duracion;
		if (V_TRestante <= 0) {
			V_Tiempo = millis();
			(*Accion)();
		};
	};
}
bool C_Timer::SoloCheck() {
	if (!V_Stop) {
		V_TActual = millis();
		V_Duracion = V_TActual - V_Tiempo;
		V_TRestante = Total - V_Duracion;
		if (V_TRestante <= 0) {
			V_Tiempo = millis();
			return true;
		} else {
			return false;
		}
	}
}

void C_Timer::Stop() {
	V_Stop = true;
}

void SinAccion() {
	Serial.println("Sin accion");
}

