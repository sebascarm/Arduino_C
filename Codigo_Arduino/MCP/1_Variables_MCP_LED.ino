// ***********************************************************************************
// ****        DECLARACION DE VARIABLES - GRUPO DE CHIPS     		              ****
// ***********************************************************************************
C_GrupoChip GrupoChipLED_MCP(26);
// ***********************************************************************************
// ****        DECLARACION DE VARIABLES - LEDS	INDIVIDUALES		              ****
// ***********************************************************************************
C_MultiLed ledAT	("<1MCP_LATAR=", PAQUETE, GrupoChipLED_MCP.Chip[0], 2);
C_MultiLed ledFD1	("<1MCP_LFD1_=", PAQUETE, GrupoChipLED_MCP.Chip[0], 1);
C_MultiLed ledFD2	("<1MCP_LFD2_=", PAQUETE, GrupoChipLED_MCP.Chip[2], 2);
// ***********************************************************************************
// ****        DECLARACION DE VARIABLES - VARIABLES DE LEDS DE BOTONES (VALORES)  ****
// ***********************************************************************************
C_MultiLed ledN1		("<1MCP_LN1__=", PAQUETE, GrupoChipLED_MCP.Chip[0], 3);
C_MultiLed ledSPEED		("<1MCP_LSPEE=", PAQUETE, GrupoChipLED_MCP.Chip[0], 4);
C_MultiLed ledVNAV		("<1MCP_LVNAV=", PAQUETE, GrupoChipLED_MCP.Chip[0], 5);
C_MultiLed ledLVLCHG	("<1MCP_LLVLC=", PAQUETE, GrupoChipLED_MCP.Chip[0], 6);
C_MultiLed ledHDGSEL	("<1MCP_LHDGS=", PAQUETE, GrupoChipLED_MCP.Chip[0], 7);
C_MultiLed ledLNAV		("<1MCP_LLNAV=", PAQUETE, GrupoChipLED_MCP.Chip[1], 1);
C_MultiLed ledVORLOC	("<1MCP_LVORL=", PAQUETE, GrupoChipLED_MCP.Chip[1], 2);
C_MultiLed ledAPP		("<1MCP_LAPP_=", PAQUETE, GrupoChipLED_MCP.Chip[1], 3);
C_MultiLed ledALTHLD	("<1MCP_LALTH=", PAQUETE, GrupoChipLED_MCP.Chip[1], 4);
C_MultiLed ledVS		("<1MCP_LVS__=", PAQUETE, GrupoChipLED_MCP.Chip[1], 5);
C_MultiLed ledCMDA		("<1MCP_LCMDA=", PAQUETE, GrupoChipLED_MCP.Chip[1], 6);
C_MultiLed ledCWSA		("<1MCP_LCWSA=", PAQUETE, GrupoChipLED_MCP.Chip[1], 7);
C_MultiLed ledCMDB		("<1MCP_LCMDB=", PAQUETE, GrupoChipLED_MCP.Chip[2], 1);
C_MultiLed ledCWSB		("<1MCP_LCWSB=", PAQUETE, GrupoChipLED_MCP.Chip[2], 3);
// ***********************************************************************************
// ****        DECLARACION DE VARIABLES - VARIABLES DE DISPLAYS (VALORES)         ****
// ***********************************************************************************
C_Display 		DispCOURSE1	("<1MCP_DCOU1=", PAQUETE, 3);
C_Display_Adic 	DispIASMACH	("<1MCP_DIASM=", PAQUETE, 4);
C_Display 		DispHEADING	("<1MCP_DHEAD=", PAQUETE, 3);
C_Display 		DispALTITUDE("<1MCP_DALTI=", PAQUETE, 5);
C_Display_Adic	DispVS		("<1MCP_DVS__=", PAQUETE, 5);
C_Display 		DispCOURSE2	("<1MCP_DCOU2=", PAQUETE, 3);


