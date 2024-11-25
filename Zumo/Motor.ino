void avanzarR(int vel) {
  //para mover la llanta tenemos que poner DIRR1 y DIRR2 en 1 y 0
  digitalWrite(DIRR1, 1);
  digitalWrite(DIRR2, 0);
  vel = constrain(vel, 51, 100); // define valores minimos y maximos
  int velReal = map(vel, 0, 100, 0, 255);
  analogWrite(VELR, velReal);
}

void retrocederR(int vel) {
  //para mover la llanta tenemos que poner DIRR1 y DIRR2 en 1 y 0
  digitalWrite(DIRR1, 0);
  digitalWrite(DIRR2, 1);  
  vel = constrain(vel, 51, 100); // define valores minimos y maximos
  int velReal = map(vel, 0, 100, 0, 255);
  analogWrite(VELR, velReal);
}

void detenerR() {
  digitalWrite(DIRR1, 0);
  digitalWrite(DIRR2, 0);
  analogWrite(VELR, 0);
}

void avanzarL(int vel) {
  //para mover la llanta tenemos que poner DIRR1 y DIRR2 en 1 y 0
  digitalWrite(DIRL1, 1);
  digitalWrite(DIRL2, 0);  
  vel = constrain(vel, 51, 100); // define valores minimos y maximos
  int velReal = map(vel, 0, 100, 0, 255);
  analogWrite(VELL, velReal);
}

void retrocederL(int vel) {
  //para mover la llanta tenemos que poner DIRR1 y DIRR2 en 1 y 0
  digitalWrite(DIRL1, 0);
  digitalWrite(DIRL2, 1);  
  vel = constrain(vel, 51, 100); // define valores minimos y maximos
  int velReal = map(vel, 0, 100, 0, 255);
  analogWrite(VELL, velReal);
}

void detenerL() {
  digitalWrite(DIRL1, 0);
  digitalWrite(DIRL2, 0);
  analogWrite(VELL, 0);
}


void avanzar(int vel) {
  avanzarL(vel);
  avanzarR(0.9 * vel);
}

void retroceder(int vel) {
  retrocederL(vel);
  retrocederR(vel * 0.9);
  digitalWrite(13, 1);
}

void detener() {
  detenerL();
  detenerR();
}

void girarL(int velR, int velL) {
  avanzarL(velL);
  retrocederR(velR);
}

void girarR(int velR, int velL) {
  avanzarR(velR);
  retrocederL(velL);
}
