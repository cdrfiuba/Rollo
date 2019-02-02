//#include <MatrixMath.h>
#include <math.h>
#include <Servo.h> 

const int DH[3][3]={{0, 0, 0},{150, 140, 0},{0, 0, 0}};
//mtx_type DH2[3][3]={{0, 150, 0}, {0, 140, 0}, {0, 0, 0}};
float angulos[3];
//const float Identidad[][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};
//mtx_type Identidad[][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float Angulos[3]={30*M_PI/180, 20*M_PI/180, -10*M_PI/180};
float Ri[4][4];
float R03[4][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};

Servo MusloI;
Servo RodillaI;
Servo TobilloI;
Servo MusloD;
Servo RodillaD;
Servo TobilloD;
Servo Cadera;
Servo BrazoI;
Servo BrazoD;
Servo Cabeza;

// PAra usar matrices, los subindices empiezan en 0, es decir, 
// el ultimo valor de una matriz de 3x3 es el M[2][2]

void setup() {
        Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
        //Angulos = Angulos./(180/pi);
  MusloI.attach(A5);
  TobilloI.attach(A3);
  RodillaI.attach(A4);
  MusloD.attach(A2); 
  TobilloD.attach(A0); 
  RodillaD.attach(A1); 
  Cadera.attach(A6); // Digital 4
  BrazoI.attach(A7); // Digital 6
  BrazoD.attach(A8); // Digital 8
  Cabeza.attach(A9); // Digital 9

  // set servo to mid-point
  PiernaI(0,0,0);
  PiernaD(0,0,0);
  Torso(0, 45,45);
  //CaderaM(0);

//  Cadera.write(90);
//  BrazoI.write(90);
//  BrazoD.write(90);
  Cabeza.write(90);
}

void loop(){
  
//MegaSweep(Md, Rd, Td, Mi, Ri, Ti, Kd, Bd, Bi, Kb, Time);
  delay (5000);
  //MegaSweep(30, 90, 30, 00, 00, 00, 45, 45, 00, 00, 1000);
  Walking(1);
  delay(1000);
  MegaSweep(00, 00, 00, 00, 00, 00, 00, 45, 45, 00, 2000);
 // delay(1000);
  //MegaSweep(00, 00, 00, 00, 00, 00, 00, 30, 30, 0, 2000);
  //delay(5000);

}

//Funcion Caminata
void Walking(int pasos){

  int cont = 0;
  int paso_actual;
  const int dt = 5000;
  
  // CONDICION PIES EN EL PISO: SUMA DE LOS ANGULOS DE PIERNA D Y PIERNA I DEBEN SER IGUALES
  // SI ESTO NO SE CUMPLE EL TORSO QUEDA CON 2 CONDICIONES DISTINTAS DE INCLINACION LO CUAL ES INESTABLE Phi=0
  //siempre empieza con pie derecho
  if (pasos>0){
    if (pasos == 1){pasos = 2;};
    // Primer paso empiezo en 1-0

    //movimiento 1-1
    MegaSweep(15, 45, 15, -05, 05, 05, -45, 00, 00, 00, 500);
    delay(1000); //delay de debug
    //movimiento 1-2
    MegaSweep(30, 60, 30, -05, 05, 05, -60, 00, 00, 00, 500);
    delay(1000); //delay de debug
    //movimiento 1-3
    MegaSweep(75, 55, 20, -30, 15, 05, 10, 00, 00, 00, 500);

//HARCODED EXIT -- borrar
    pasos =0;

//    delay (dt);
//    Cadera.write(90);
//    PiernaD( -20, 10, 30);
//    PiernaI(60, 60, 30);    
//    pie_delantero = 1;
//    delay (dt);
    
//    //pasos continuos
//    while (cont < pasos-2){
//      if (pie_delantero == 1){
//        Cadera.write(120);
//        PiernaD(-30, 10, -30);
//        PiernaI(40, 30, 0);
//        delay (dt);
//        Cadera.write(150);
//        PiernaI(20, 00, 0);
//        PiernaD(50, 60, 0);
//        delay (dt);
//        Cadera.write(90);
//        PiernaI( -20, 10, 30);
//        PiernaD(60, 60, 30);    
//        pie_delantero = 2;
//        delay (dt);
//        cont++;
//      }
//      else{
//        Cadera.write(60);
//        PiernaI(-30, 10, -30);
//        PiernaD(40, 30, 0);
//        delay (dt);
//        Cadera.write(30);
//        PiernaD(20, 00, 0);
//        PiernaI(50, 60, 0);
//        delay (dt);
//        Cadera.write(90);
//        PiernaD( -20, 10, 30);
//        PiernaI(60, 60, 30);    
//        pie_delantero = 1;
//        delay (dt);
//        cont++;
//      }
//    }
//      //detencion
//      if (pie_delantero == 1){
//        Cadera.write(120);
//        PiernaD(-30, 10, -30);
//        PiernaI(40, 30, 0);
//        delay (dt);
//        Cadera.write(150);
//        PiernaI(10, 00, 0);
//        PiernaD(20, 50,30);
//        delay (dt);
//        Cadera.write(90);
//        PiernaD( 0, 0, 0);
//        PiernaI(00, 00, 00);    
//        pie_delantero = 2;
//        delay (dt);
//      }
//      else{
//        Cadera.write(30);
//        PiernaI(-30, 10, -30);
//        PiernaD(40, 30, 0);
//        delay (dt);
//        Cadera.write(60);
//        PiernaD(10, 00, 0);
//        PiernaI(20, 50,30);
//        delay (dt);
//        Cadera.write(90);
//        PiernaI( 0, 0, 0);
//        PiernaD(00, 00, 00);    
//        pie_delantero = 2;
//        delay (dt);
//      }
   }
}
  
  



// Funciones Auxiliares cosd y sind
float cosd(float angle){
  double coseno;
  const float pi=3.14159;
  
  angle = angle*pi/180;
  coseno = cos(angle);
  return (float)coseno;
}

float sind(float angle){
  double seno;
  const float pi=3.14159;
  
  angle = angle*pi/180;
  seno = sin(angle);
  return (float)seno;
}

//Funciones de Movimientos de Piernas
// Se definen como PiernaX([angulo del Muslo], [angulo de la Rodilla], [angulo del Tobillo])
// Los angulos van entre -90 y 90 ya que se miden desde el medio del recorrido del servo

void PiernaI (int M, int R, int T){
    // WARNING!!
    // cualquier cambio de seteo, cambiar tambien en PiernaIRead!!
    MusloI.write(90-M);
    RodillaI.write(90-R);
    TobilloI.write(90+T);

}
void PiernaIRead (int PrevioI[3]){
    PrevioI[0] = 90 - MusloI.read(); // porque esta cambiado el signo
    PrevioI[1] = 90 - RodillaI.read();
    PrevioI[2] = TobilloI.read() - 90;
}

void PiernaD (int M, int R, int T){

    MusloD.write(90+M);
    RodillaD.write(90+R);
    TobilloD.write(90-T);

}
void PiernaDRead (int PrevioD[3]){
    PrevioD[0] = MusloD.read()-90; // porque esta cambiado el signo
    PrevioD[1] = RodillaD.read()-90;
    PrevioD[2] = 90 - TobilloD.read();
}

void Torso (int C, int BD, int BI){
  Cadera.write(100-C);
  BrazoD.write(90-BD);
  BrazoI.write(90+BI);
}

void TorsoRead (int PrevioT[3]){
    PrevioT[0] = 90 - Cadera.read(); // porque esta cambiado el signo
    PrevioT[1] = 90 - BrazoD.read();
    PrevioT[2] = BrazoI.read()-90;
}
//Prueba MegaSweep

void MegaSweep (int Md, int Rd, int Td, int Mi, int Ri, int Ti, int Hip, int Armd, int Armi, int Head, int Timelapse){// Barrido de motres: Muslo, Rodilla y Tobillo derecho, izquierdo, Cadera (hip)
  // Brazos (Arms) Derecho e izquierdo y cabeza
  // Angulos entre -90 y 90
  // TimeLapse: Tiempo en el cual se espera se realizen los movimientos en [ms]
  
  int ElTimerloco= micros();
  int Pasos= round(Timelapse/2.0) ;//Defino que cada paso es de 2.0 ms
  int PrevioPD[3];
  int TargetPD[3]={Md, Rd, Td}; 
  int ActualPD[3]={PrevioPD};
  int PrevioPI[3];
  int TargetPI[3]={Mi, Ri, Ti}; 
  int ActualPI[3]={PrevioPI};
  int PrevioTorso[3];
  int TargetTorso[3]={Hip, Armd, Armi}; 
  int ActualTorso[3];

  //Obtengo el valor de la posicion
  PiernaDRead(PrevioPD);
  PiernaIRead(PrevioPI);
  TorsoRead(PrevioTorso);
  
  for (int i=1; i<Pasos; i++){
    
    //Obtengo la nueva posicion acorde al progreso
    Actualizar (ActualPD, PrevioPD, TargetPD, i, Pasos);
    Actualizar (ActualPI, PrevioPI, TargetPI, i, Pasos);
    Actualizar (ActualTorso, PrevioTorso, TargetTorso, i, Pasos);

    //Mando la orden a los sevos
    PiernaD(ActualPD[0], ActualPD[1], ActualPD[2]);
    PiernaI(ActualPI[0], ActualPI[1], ActualPI[2]);
    Torso(ActualTorso[0],ActualTorso[1],ActualTorso[2]);
    delayMicroseconds(2000-(micros()-ElTimerloco)-20); //Delay acorde a Pasos
 //   delay(100);
    ElTimerloco = micros();
  }
}

void SweepPD(int Time, int T1, int T2, int T3){ // barrido de pierna derecha. Entre la posicion actual y la de destino (Target), Actualiza la posicion a la que deberia estar

  int Previo[3]={MusloD.read(), RodillaD.read(), TobilloD.read()};
  int Target[3]={T1, T2, T3}; 
  int Actual[3]={Previo};
  for (int i=0; i<Time/2.0; i++){
    Actualizar (Actual, Previo, Target, i, Time); 
    PiernaD(Actual[0], Actual[1], Actual[2]);
  }
}

void Resta (int arr1[3],int arr2[3],int resultado[3]){ //Resta 2 Arrays componente a componente y lo devuelve en "resultado"
  for (int i=0; i<3; i++){
    resultado[i]=arr1[i]-arr2[i];
//    Serial.print("Arr1: ");
//    Serial.print(arr1[i]);
//    Serial.print("  Arr2: ");
//    Serial.print(arr1[2]);
}
}

void Actualizar (int Actual[3], int Previo[3], int Target[3], int TiempoActual, int TimeTotal){ //Actualiza la variable "Actual" 
  int Diff[3];
  Resta(Target, Previo, Diff);
//    Serial.print("Previo0: ");
//    Serial.print(Previo[0]);
//    Serial.print("// Previo1: ");
//    Serial.print(PrevioCaderaM[1]);
//    Serial.print("// Previo2: ");
//    Serial.print(Previo[2]);
//    Serial.println(" end Diff");
//    Serial.print("Tiempo Actual");
//    Serial.print(TiempoActual);
//    Serial.print("/");
//    Serial.println(TimeTotal);
  for (int j=0; j<3; j++){
    
    Actual[j]= Previo[j] + round(TiempoActual*(float)Diff[j]/TimeTotal);
//    if (j==1){
//      Serial.print("  ActualJ ");
//      Serial.print(Actual[j]);
//      Serial.print(" = PreviolJ ");
//      Serial.print(Previo[j]);
//      Serial.print(" +( Actual ");
//      Serial.print(TiempoActual);
//      Serial.print(" *Diff ");
//      Serial.print(Diff[j]);
//      Serial.print(" / Total");
//      Serial.print(TimeTotal);
//      Serial.println("  )");
//      
//    }
//    Serial.print("  ActualJ");
//    Serial.print(j);
//    Serial.print(": ");
//    Serial.print(Actual[j]);
  }
//  Serial.println(" end Actual");
}

