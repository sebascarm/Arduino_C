
//Constructor de la clase
C_Control::C_Control(TipoControl Tipo, String Comando, byte& Chip, byte Posicion) {
	V_Tipo = Tipo;
	V_Comando = Comando;
	V_Chip = &Chip;
	V_Posicion = Posicion;
}

// Acciones              
void C_Control::EnviarComando(C_Comunicacion Comunicacion) {
	// Cargar Valor desde el chip
	V_ValorAnt = V_Valor;
	V_Valor = bitRead(*V_Chip, V_Posicion);
	switch (V_Tipo) {
		// Enviar SWITCH - Solo cuando los valores son distintos
		case Switch:
			if (V_Valor != V_ValorAnt) {
				Comunicacion.Enviar(V_Comando, V_Valor);
			}
			break;
		// Enviar PULSADOR - Solo cuando los valores son distintos y es 1
		case Pulsador:
			if ((V_Valor == 1) && (V_Valor != V_ValorAnt)) {
				Comunicacion.Enviar(V_Comando, V_Valor);
			}
			break;

		default:
			break;
		}
}

