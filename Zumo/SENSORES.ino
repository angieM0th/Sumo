float medirDistancia() {
  //Me aseguro que el sensor este callado
  digitalWrite(TRIGGER, 0);
  delayMicroseconds(2);
  //Lanzar pulso de ultrasonido
  digitalWrite(TRIGGER, 1);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, 0);
  //Guardo el tiempo que tarda en regresar el sonido
  long duracion = pulseIn(ECHO, HIGH);
  float distancia = duracion / 58.0;
  return distancia;
}

void leerSensores() {
  dist = medirDistancia();
  lineL = !digitalRead(LL);
  lineR = !digitalRead(LR);
  enemigo = (dist < DIST_MAX) ? 1 : 0; // Verifica si el enemigo esta dentro del rango
  estadoActual = lineL * 4 + lineR * 2 + enemigo;
  
}

void imprimirSensores() {
  Serial.print(dist);
  Serial.print(" ");
  Serial.print(lineL);
  Serial.print(" ");
  Serial.print(lineR);
  Serial.print(" ");
  Serial.println(estadoActual);
}
