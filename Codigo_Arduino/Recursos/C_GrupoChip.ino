C_GrupoChip::C_GrupoChip(byte Cant_Chips) {
	//Declaracion de vector de chips
	V_Cant_Chips = Cant_Chips;
	Chip 			= new byte[V_Cant_Chips];
	V_ChipPrevio 	= new byte[V_Cant_Chips];
	//inicializar los chips en 0
	for (byte i = 0; (i < V_Cant_Chips); i++) {
		Chip[i] 		= 0;
		V_ChipPrevio[i] = 0;
	}

}
void C_GrupoChip::PinesIN(byte PinData, byte PinLatch, byte PinClock) {
	V_PinData = PinData;
	V_PinLatch = PinLatch;
	V_PinClock = PinClock;

	pinMode(V_PinData, OUTPUT);
	pinMode(V_PinLatch, OUTPUT);
	pinMode(V_PinClock, OUTPUT);
}

void C_GrupoChip::PinesOUT(byte PinData, byte PinLatch, byte PinClock) {
	V_PinData = PinData;
	V_PinLatch = PinLatch;
	V_PinClock = PinClock;

	pinMode(V_PinData, INPUT);
	pinMode(V_PinLatch, OUTPUT);
	pinMode(V_PinClock, OUTPUT);
}

void C_GrupoChip::CargarChips() {
	digitalWrite(V_PinLatch, 1);
	delayMicroseconds(5); /*Pasar a 20 si no se reciben bien los datos */
	digitalWrite(V_PinLatch, 0);
	//for (byte i = (V_Cant_Chips); i > 0; i--) {
	for (byte i = (V_Cant_Chips); i > 0; i--) {
		//Lee en forma inversa
		Chip[i-1] = shift_IN(V_PinData, V_PinClock);
	}
}

void C_GrupoChip::EscribirChips() {
	digitalWrite(V_PinLatch, LOW);
	delayMicroseconds(5);
	for (byte i = (V_Cant_Chips); i > 0; i--) {
		//Envia en forma inversa
		shiftOut(V_PinData, V_PinClock, MSBFIRST, Chip[i-1]);
	}
	digitalWrite(V_PinLatch, HIGH);
}

void C_GrupoChip::Apagar() {
	digitalWrite(V_PinLatch, LOW);
	for (byte i = (V_Cant_Chips); i > 0; i--) {
		//Envia en forma inversa
		shiftOut(V_PinData, V_PinClock, MSBFIRST, 0);
	}
	digitalWrite(V_PinLatch, HIGH);
}
void C_GrupoChip::Encender() {
	digitalWrite(V_PinLatch, LOW);
	for (byte i = (V_Cant_Chips); i > 0; i--) {
		//Envia en forma inversa
		shiftOut(V_PinData, V_PinClock, MSBFIRST, 255);
	}
	digitalWrite(V_PinLatch, HIGH);
}
void C_GrupoChip::Test(int Tiempo_ms) {
	digitalWrite(V_PinLatch, LOW);
	Apagar();
	delay(Tiempo_ms);
	Encender();
	delay(Tiempo_ms);
	Apagar();
}

void C_GrupoChip::Test_Individual(int Tiempo_ms) {
	for (byte i = 0; i < V_Cant_Chips; i++) {
		for (byte Pos = 0; Pos < 8; Pos++) {
			Apagar();
			bitWrite(Chip[i], Pos, 1);
			Serial.print("{Chip: ");
			Serial.print(i);
			Serial.print(" Pos: ");
			Serial.print(Pos);
			Serial.println("}");
			EscribirChips();
			delay(Tiempo_ms);
		}
	}
}

bool C_GrupoChip::Modificado() {
	bool V_Distinto = false;
	for (byte i = 0; (i < V_Cant_Chips); i++) {
		if (V_ChipPrevio[i] != Chip[i]){
			V_Distinto = true;
			V_ChipPrevio[i] = Chip[i];
		}
	}
	return V_Distinto;
}

// *******************************************************************************************
// ****        FUNCION: LECTURA DE CHIP IN                                                ****
// *******************************************************************************************
byte C_GrupoChip::shift_IN(int myDataPin, int myClockPin) {
  int i;
  int temp = 0;
  int pinState;
  byte myDataIn = 0;
  //pinMode(myClockPin, OUTPUT);	// ya deben estar establecidos
  //pinMode(myDataPin, INPUT);		// ya deben estar establecidos
  for (i=7; i>=0; i--) {
      digitalWrite(myClockPin, 0);
      delayMicroseconds(2);
      temp = digitalRead(myDataPin);
      if (temp) {
          pinState = 1;
          myDataIn = myDataIn | (1 << i);
      } else {
          pinState = 0;
      }
      digitalWrite(myClockPin, 1);
  }
  return myDataIn;
}