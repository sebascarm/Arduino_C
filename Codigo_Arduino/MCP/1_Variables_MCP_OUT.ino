// ***********************************************************************************
// ****        GRUPOS DE INTEGRADOS LEDS Y ENTRADA DE DATOS                       ****
// ***********************************************************************************
C_GrupoChip GrupoChipOUT_MCP(3);

// ***********************************************************************************
// ****        DECLARACION DE VARIABLES - VARIABLES DE SWITCH (VALORES)           ****
// ***********************************************************************************
C_Control SwitchAT (Switch, "<SMCP_SATAR=", GrupoChipOUT_MCP.Chip[1], 5);
C_Control SwitchFD1(Switch, "<SMCP_SFD1_=", GrupoChipOUT_MCP.Chip[1], 4);
C_Control SwitchDIS(Switch, "<SMCP_SDISE=", GrupoChipOUT_MCP.Chip[0], 0);
C_Control SwitchFD2(Switch, "<SMCP_SFD2_=", GrupoChipOUT_MCP.Chip[0], 6);
// **********************************************************************************
// ****        DECLARACION DE VARIABLES - VARIABLES DE BOTONES (VALORES)         ****
// **********************************************************************************
C_Control BotonN1		(Pulsador, "<SMCP_BN1__=", GrupoChipOUT_MCP.Chip[1], 6);
C_Control BotonSpeed	(Pulsador, "<SMCP_BSPEE=", GrupoChipOUT_MCP.Chip[2], 5);
C_Control BotonVNAV		(Pulsador, "<SMCP_BVNAV=", GrupoChipOUT_MCP.Chip[2], 7);
C_Control BotonLVLCHG	(Pulsador, "<SMCP_BLVLC=", GrupoChipOUT_MCP.Chip[2], 3);
C_Control BotonHDGSEL	(Pulsador, "<SMCP_BHDGS=", GrupoChipOUT_MCP.Chip[1], 7);
C_Control BotonLNAV		(Pulsador, "<SMCP_BLNAV=", GrupoChipOUT_MCP.Chip[1], 3);
C_Control BotonVORLOC	(Pulsador, "<SMCP_BVORL=", GrupoChipOUT_MCP.Chip[1], 2);
C_Control BotonAPP		(Pulsador, "<SMCP_BAPP_=", GrupoChipOUT_MCP.Chip[1], 1);
C_Control BotonALTHLD	(Pulsador, "<SMCP_BALTH=", GrupoChipOUT_MCP.Chip[1], 0);
C_Control BotonVS		(Pulsador, "<SMCP_BVS__=", GrupoChipOUT_MCP.Chip[0], 7);
C_Control BotonCMDA		(Pulsador, "<SMCP_BCMDA=", GrupoChipOUT_MCP.Chip[0], 2);
C_Control BotonCWSA		(Pulsador, "<SMCP_BCWSA=", GrupoChipOUT_MCP.Chip[0], 1);
C_Control BotonCMDB		(Pulsador, "<SMCP_BCMDB=", GrupoChipOUT_MCP.Chip[0], 4);
C_Control BotonCWSB		(Pulsador, "<SMCP_BCWSB=", GrupoChipOUT_MCP.Chip[0], 5);
// **********************************************************************************
// ****        DECLARACION DE VARIABLES - VARIABLES DE PULSADORES (VALORES)      ****
// **********************************************************************************
C_Control PulsadorCO(Pulsador, "<SMCP_PCO__=", GrupoChipOUT_MCP.Chip[2], 4);
C_Control PulsadorSP(Pulsador, "<SMCP_PSPEE=", GrupoChipOUT_MCP.Chip[2], 6);
C_Control PulsadorAL(Pulsador, "<SMCP_PALTI=", GrupoChipOUT_MCP.Chip[0], 3);
// ***********************************************************************************
// ****        DECLARACION DE VARIABLES - VARIABLES DE POTENCIOMETROS (VALORES)   ****
// ***********************************************************************************
C_Pote PoteCourse1("<SMCP_PCOU1=", 0);
C_Pote PoteIASMach("<SMCP_PIASM=", 1);
C_Pote PoteHeading("<SMCP_PHEAD=", 2);
C_Pote PoteAltitud("<SMCP_PALTI=", 3);
C_Pote PoteVS	  ("<SMCP_PVERS=", 4);
C_Pote PoteCourse2("<SMCP_PCOU2=", 5);

