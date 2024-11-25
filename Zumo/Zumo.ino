#include <TimerOne.h>

#define DIRR1 8
#define DIRR2 7
#define VELR A2
#define DIRL1 4
#define DIRL2 5
#define VELL 6
#define TRIGGER 10
#define ECHO 11
#define LL 2
#define LR 3

unsigned long lastMillis = 0; // Tiempo del último cambio
const unsigned long interval = 1000; // Intervalo entre acciones (1 segundo)

int stateSearch = 0; // Estado de busqueda

bool inicio = false;

volatile float dist = 0;
volatile int lineL = 0;
volatile int lineR = 0;
volatile const float DIST_MAX = 30.0;
volatile int enemigo = 0;

int estadoActual = 0;

void setup() {
  //configuracion del GPI0
  configurarI0();
  Serial.begin(115200);
  Timer1.initialize(20000);
  Timer1.attachInterrupt(leerSensores);
  
}

void loop() {
  
  if (inicio == false){
    atacar();
    delay(2000);
    inicio = true;
  }
  
  imprimirSensores();
  
  switch (estadoActual) {
    case 0: buscar(); break;
    case 1: atacar(); break;
    case 2: entrarL(); break;
    case 3: entrarL(); break;
    case 4: entrarR(); break;
    case 5: entrarR(); break;
    case 6: escape(); break;
    case 7: detener(); break;
    default: detener(); break;


  }
}

void configurarI0() {
  pinMode(DIRR1, OUTPUT);
  pinMode(DIRR2, OUTPUT);
  pinMode(VELR, OUTPUT);
  pinMode(DIRL1, OUTPUT);
  pinMode(DIRL2, OUTPUT);
  pinMode(VELL, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LL, INPUT);
  pinMode(LR, INPUT);
  pinMode(13, OUTPUT);
}
