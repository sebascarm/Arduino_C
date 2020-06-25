

void Func_MCP_OUT(C_Comunicacion Comunicador) {
	// ***********************************************************************************
	// ****        GRUPOS DE INTEGRADOS LEDS Y ENTRADA DE DATOS                       ****
	// ***********************************************************************************
	GrupoChipOUT_MCP.CargarChips();
	// ***********************************************************************************
	// ****        DECLARACION DE VARIABLES - VARIABLES DE SWITCH (VALORES)           ****
	// ***********************************************************************************
	SwitchAT.EnviarComando(Comunicador);
	SwitchFD1.EnviarComando(Comunicador);
	SwitchDIS.EnviarComando(Comunicador);
	SwitchFD2.EnviarComando(Comunicador);
	// **********************************************************************************
	// ****        DECLARACION DE VARIABLES - VARIABLES DE BOTONES (VALORES)         ****
	// **********************************************************************************
	BotonN1.EnviarComando(Comunicador);
	BotonSpeed.EnviarComando(Comunicador);
	BotonVNAV.EnviarComando(Comunicador);
	BotonLVLCHG.EnviarComando(Comunicador);
	BotonHDGSEL.EnviarComando(Comunicador);
	BotonLNAV.EnviarComando(Comunicador);
	BotonVORLOC.EnviarComando(Comunicador);
	BotonAPP.EnviarComando(Comunicador);
	BotonALTHLD.EnviarComando(Comunicador);
	BotonVS.EnviarComando(Comunicador);
	BotonCMDA.EnviarComando(Comunicador);
	BotonCWSA.EnviarComando(Comunicador);
	BotonCMDB.EnviarComando(Comunicador);
	BotonCWSB.EnviarComando(Comunicador);
	// **********************************************************************************
	// ****        DECLARACION DE VARIABLES - VARIABLES DE PULSADORES (VALORES)      ****
	// **********************************************************************************
	PulsadorCO.EnviarComando(Comunicador);
	PulsadorSP.EnviarComando(Comunicador);
	PulsadorAL.EnviarComando(Comunicador);
	// ***********************************************************************************
	// ****        DECLARACION DE VARIABLES - VARIABLES DE POTENCIOMETROS (VALORES)   ****
	// ***********************************************************************************
	PoteCourse1.EnviarDigital(Comunicador);
	PoteIASMach.EnviarDigital(Comunicador);
	PoteHeading.EnviarDigital(Comunicador);
	PoteAltitud.EnviarDigital(Comunicador);
	PoteVS.EnviarDigital(Comunicador);
	PoteCourse2.EnviarDigital(Comunicador);
}