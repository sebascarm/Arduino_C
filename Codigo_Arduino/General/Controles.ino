
void ControlVuelta(){
	int Vuelta; 
	Vuelta = Transcurrido.Tiempo();
	if (Vuelta > 25){
		Serial.print("{Vuelta");
		Serial.print(": ");
		Serial.print(Vuelta);
		Serial.println("}");
	}
	Transcurrido.Reiniciar();
}

void Func_INTERNA(){
	Serial.println("{TEST LED}");
	GrupoChipLED_MCP.Test_Individual(500);
}
