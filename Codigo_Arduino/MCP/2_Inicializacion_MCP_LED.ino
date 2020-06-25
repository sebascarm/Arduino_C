void Inicializacion_MCP_LED() {
// **********************************************************************
// ****        ASIGNACION DE CHIP Y TRADUCTOR A LOS DISPLAYS         ****
// **********************************************************************
	GrupoChipLED_MCP.PinesIN(22, 24, 26);
	
// **********************************************************************
// ****        ASIGNACION DE CHIP Y TRADUCTOR A LOS DISPLAYS         ****
// **********************************************************************
	DispCOURSE1.AsignarDigito(0, GrupoChipLED_MCP.Chip[3], Tipo3);
	DispCOURSE1.AsignarDigito(1, GrupoChipLED_MCP.Chip[4], Tipo2);
	DispCOURSE1.AsignarDigito(2, GrupoChipLED_MCP.Chip[5], Tipo1);
	DispCOURSE1.Rellenar("0");

	DispHEADING.AsignarDigito(0, GrupoChipLED_MCP.Chip[6], Tipo3);
	DispHEADING.AsignarDigito(1, GrupoChipLED_MCP.Chip[7], Tipo2);
	DispHEADING.AsignarDigito(2, GrupoChipLED_MCP.Chip[8], Tipo1);
	DispHEADING.Rellenar("0");

	DispIASMACH.AsignarDigito(0, GrupoChipLED_MCP.Chip[9], Tipo7); // Revisar es variable en funcion del 2
	DispIASMACH.AsignarDigito(1, GrupoChipLED_MCP.Chip[10], Tipo6);
	DispIASMACH.AsignarDigito(2, GrupoChipLED_MCP.Chip[11], Tipo5);
	DispIASMACH.AsignarDigito(3, GrupoChipLED_MCP.Chip[12], Tipo4);
	DispIASMACH.Rellenar(" ");
	DispIASMACH.Blinker ("<1MCP_FIASM=");
	DispIASMACH.Apagador("<1MCP_BIASM="); //B por Blanco


	DispCOURSE2.AsignarDigito(0, GrupoChipLED_MCP.Chip[13], Tipo3);
	DispCOURSE2.AsignarDigito(1, GrupoChipLED_MCP.Chip[14], Tipo2);
	DispCOURSE2.AsignarDigito(2, GrupoChipLED_MCP.Chip[15], Tipo1);
	DispCOURSE2.Rellenar("0");

	DispVS.AsignarDigito(0, GrupoChipLED_MCP.Chip[16], Tipo8);
	DispVS.AsignarDigito(1, GrupoChipLED_MCP.Chip[17], Tipo9);
	DispVS.AsignarDigito(2, GrupoChipLED_MCP.Chip[18], Tipo9);
	DispVS.AsignarDigito(3, GrupoChipLED_MCP.Chip[19], Tipo2);
	DispVS.AsignarDigito(4, GrupoChipLED_MCP.Chip[20], Tipo1);
	DispVS.Rellenar	 (" ");
	DispVS.ValorVacio("-16960");
	DispVS.Apagador	 ("<1MCP_BVS__=");

	DispALTITUDE.AsignarDigito(0, GrupoChipLED_MCP.Chip[21], Tipo8);
	DispALTITUDE.AsignarDigito(1, GrupoChipLED_MCP.Chip[22], Tipo9);
	DispALTITUDE.AsignarDigito(2, GrupoChipLED_MCP.Chip[23], Tipo9);
	DispALTITUDE.AsignarDigito(3, GrupoChipLED_MCP.Chip[24], Tipo2);
	DispALTITUDE.AsignarDigito(4, GrupoChipLED_MCP.Chip[25], Tipo1);
	DispALTITUDE.Rellenar(" ");

// ***********************************************************************************
// ****        TEST         ****
// ***********************************************************************************
	GrupoChipLED_MCP.Test();

}