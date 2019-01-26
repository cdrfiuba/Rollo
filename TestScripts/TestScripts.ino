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
//  angulos=Angular(Angulos);
//for (i=1; i=3; i++){
//    A=A*{{cosd(angulos(i)), 
//  Serial.println(Matriz[3][0], DEC);
//  Serial.println(DH[1][0], DEC);
//  Serial.println(Matriz[3][2], DEC);
//  R03 = Identidad;

  
//MegaSweep(Md, Rd, Td, Mi, Ri, Ti, Kd, Bd, Bi, Kb, Time);
  delay (5000);
  MegaSweep(30, 90, 30, 00, 00, 00, 45, 45, 00, 00, 1000);
  delay(1000);
  MegaSweep(00, 00, 00, 30, 60, 30, -45, 00, 45, 30, 500);
 // delay(1000);
  //MegaSweep(00, 00, 00, 00, 00, 00, 00, 30, 30, 0, 2000);
  //delay(5000);
  //MegaSweep(90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 50);
  //Serial.println(Matriz, DEC);
  //Matrix.Print((mtx_type*)DH2, 3, 3, "DH");
  //int R[4][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  //for (int i= 0: i=2; i++){
    //mtx_type R0i={{cos(Angulos[i]), -sin(Angulos[i]), 0, DH[i][2]*cos(Angulos[i])}, {sin(Angulos[i]), cos(Angulos[i]), 0, DH[i][2]*sin(Angulos[i])}, {0, 0, 1,0}, {0, 0, 0, 1}};
    //Matrix.Multiply((mtx_type*)R, (mtx_type*), N, N, N, (mtx_type*)C);}
}
//float  Angular(int Grados[3]){
//  float Radianes[3];
//  for (int i=0; i=2; i++){
//    Radianes[i]=Grados[i]*M_PI/180;
//  }
//  return Radianes;
//}
  
  
//  R(i-1,i)={{cos(Angulos[i]), -sin(Angulos[i]), 0, DH[i][2]*cos(Angulos[i])}, {sin(Angulos[i]), cos(Angulos[i]), 0, DH[i][2]*sin(Angulos[i])}, {0, 0, 1,0}, {0, 0, 0, 1}};
//R03 = Identidad,
//for (int i=0; i=2, i++){
  //Ri={{cos(Angulos[i]), -sin(Angulos[i]), 0, DH[i][2]*cos(Angulos[i])}, {sin(Angulos[i]), cos(Angulos[i]), 0, DH[i][2]*sin(Angulos[i])}, {0, 0, 1,0}, {0, 0, 0, 1}};
  //R03= {{R03[1][1]*Ri[1][1]+R03[1][2]*Ri[2][1], R03[1][1]*Ri[1][2]+R03[1][2]*Ri[2][2], 0,R03[1][1]*Ri[1][4]+R03[1][2]*Ri[2][4]+R03[1][4]}, {{R03[2][1]*Ri[1][1]+R03[2][2]*Ri[2][1], R03[2][1]*Ri[1][2]+R03[2][2]*Ri[2][2], 0,R03[2][1]*Ri[1][4]+R03[2][2]*Ri[2][4]+R03[2][4]}, {0, 0, 1,0}, {0, 0, 0, 1}};
  
  
  
  
//float Directo(int Angulos[3], float R03[][4]){
//   //Modifica la matriz de rotacion y devuelve la POSE
//  int R[4][4]; // matriz intermedia para los calculos
//  //float R03[4][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}; // Matriz de rotacion acumulada
//  float Ri[4][4]; // matriz de rotacion del angulo i
//  float POSE[4];
//  for (int j=0; j=3; j++){
//      for (int k=0; k=3; k++){
//        if (j==k)R03[j][k]=1;
//          else R03[j][k]=0;
//      }
//  }
//      
//  for (int i=0; i=2; i++){
//    Ri[0][0]=cos(Angulos[i]);
//    Ri[0][1]=-sin(Angulos[i]);
//    Ri[0][3]=DH[i][2]*cos(Angulos[i]);
//    Ri[1][0]=sin(Angulos[i]);
//    Ri[1][1]=cos(Angulos[i]);
//    Ri[1][3]=DH[i][2]*sin(Angulos[i]);
//        
//    R[0][0]= R03[0][0]*Ri[0][0]+R03[0][1]*Ri[1][0];
//    R[0][1]= R03[0][0]*Ri[0][1]+R03[0][1]*Ri[1][1];
//    R[0][3]= R03[0][0]*Ri[0][3]+R03[0][1]*Ri[1][3]+R03[0][3];
//    R[1][0]= R03[1][0]*Ri[0][0]+R03[1][1]*Ri[1][0];
//    R[1][1]= R03[1][0]*Ri[0][1]+R03[1][1]*Ri[1][1];
//    R[1][3]= R03[1][0]*Ri[0][3]+R03[1][1]*Ri[1][3]+R03[1][3];
//    
//    for (int j=0; j=3; j++){
//      for (int k=0; k=3; k++){
//        R03[j][k]=R[j][k];
//      };
//    };
//  };
//  POSE[1]= R03[1][4]; 
//  POSE[2]= R03[2][4];
//  POSE[3]= Angulos[1]+Angulos[2]+Angulos[3];
//  if (Angulos[2] <0) POSE[4]= -1;
//    else POSE[4]= 1;
//    
//// return R03;
// } 

void multipmatrix(){
    for (int i=0; i=2; i++){
    Ri[0][0]=cos(Angulos[i]);
    Ri[0][1]=-sin(Angulos[i]);
    Ri[0][3]=DH[i][2]*cos(Angulos[i]);
    Ri[1][0]=sin(Angulos[i]);
    Ri[1][1]=cos(Angulos[i]);
    Ri[1][3]=DH[i][2]*sin(Angulos[i]);
        
    R03[0][0]= R03[0][0]*Ri[0][0]+R03[0][1]*Ri[1][0];
    R03[0][1]= R03[0][0]*Ri[0][1]+R03[0][1]*Ri[1][1];
    R03[0][3]= R03[0][0]*Ri[0][3]+R03[0][1]*Ri[1][3]+R03[0][3];
    R03[1][0]= R03[1][0]*Ri[0][0]+R03[1][1]*Ri[1][0];
    R03[1][1]= R03[1][0]*Ri[0][1]+R03[1][1]*Ri[1][1];
    R03[1][3]= R03[1][0]*Ri[0][3]+R03[1][1]*Ri[1][3]+R03[1][3];
    
  };
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

