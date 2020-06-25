/***********************************************************************************/
/****       FUNCIONES DE LA CLASE TIEMPO TRANSCURRIDO                           ****/
/***********************************************************************************/
C_Transcurrido::C_Transcurrido() {
	V_Stop = false;
	V_Tiempo = millis();
}
void C_Transcurrido::Reiniciar() {
	V_Stop = false;
	V_Tiempo = millis();
}
int C_Transcurrido::Tiempo() {
	if (!V_Stop) {
		V_TActual = millis();
		V_Duracion = V_TActual - V_Tiempo;
	}
	return (V_Duracion);
}
void C_Transcurrido::Stop() {
	V_Stop = true;
}
void C_Transcurrido::Continuar() {
	V_Stop = false;
}
