void Func_MCP_LED() {
	ledFD1.CargarComando();
	ledAT.CargarComando();
	ledN1.CargarComando();
	ledSPEED.CargarComando();
	ledVNAV.CargarComando();
	ledLVLCHG.CargarComando();
	ledHDGSEL.CargarComando();
	ledLNAV.CargarComando();
	ledVORLOC.CargarComando();
	ledAPP.CargarComando();
	ledALTHLD.CargarComando();
	ledVS.CargarComando();
	ledCMDA.CargarComando();
	ledCWSA.CargarComando();
	ledCMDB.CargarComando();
	ledCWSB.CargarComando();
	ledFD2.CargarComando();
}
void Func_MCP_DISPLAY() {
	DispCOURSE1.CargarComando();
	DispHEADING.CargarComando();
	DispIASMACH.CargarComando();
	DispALTITUDE.CargarComando();
	DispVS.CargarComando();
	DispCOURSE2.CargarComando();
}

void Func_MCP_FLASH(){
	DispIASMACH.CargarBlinker();
}
void Func_MCP_OFF(){
	DispIASMACH.CargarApagado();
	DispVS.CargarApagado();
}

////
void Func_MCP_Loop(){
	DispIASMACH.Blinkeador();
}
