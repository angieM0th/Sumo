void buscar() {
  Serial.println("Buscando");
  digitalWrite(13, 0);
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= interval) {
    lastMillis = currentMillis; // Reinicia el tiempo del último cambio

    // Realiza la acción correspondiente al estado actual
    switch (stateSearch) {
      case 0:
        girarL(51,60);
        //Serial.println("0");
        stateSearch = 1; 
        break;

      case 1:
        detener();
        //Serial.println("1");
        stateSearch = 2;
        break;

      case 2:
        girarL(51,60);
        //Serial.println("2");
        stateSearch = 0; // Reinicia al primer estado
        break;
    }
  }
}

void atacar() {
  Serial.println("Atacar");
  avanzar(51);
}

void entrarL() {
  Serial.println("entrar L");
  detener();
  delay(100);
  retroceder(100);
  delay(300);
}

void entrarR() {
  Serial.println("entrar R");
  detener();
  delay(100);
  retroceder(100);
  delay(300);
}

void escape() {
  Serial.println("Retirar");
  detener();
  delay(100);
  retroceder(100);
  delay(300);
}

void morir() {
  Serial.println("Death");
  // retroceder(50);
}
