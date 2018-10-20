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
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        //Angulos = Angulos./(180/pi);
          MusloI.attach(A5);
  TobilloI.attach(A3);
  RodillaI.attach(A4);
  MusloD.attach(A2); 
  TobilloD.attach(A0); 
  RodillaD.attach(A1); 
  Cadera.attach(A6); // Digital 4
  BrazoI.attach(A7); // Digital 6
  BrazoD.attach(A9); // Digital 8
  Cabeza.attach(A8); // Digital 9

  // set servo to mid-point
  PiernaI(0,0,0);
  PiernaD(0,0,0);
  CaderaM(0);

  Cadera.write(90);
  BrazoI.write(90);
  BrazoD.write(90);
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

  Serial.println(Angulos[1], DEC);

  delay (1500);
  MegaSweep(30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 1000);
  MegaSweep(120, 80, 90, 100, 120, 90, 130, 30, 30, 30, 500);
  MegaSweep(30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 2000);
  MegaSweep(90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 50);
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
    
//  while (int i=0 <90){ 
    MusloI.write(90-round(M/*i*M/90*/));
    RodillaI.write(90+round(R/*i*R/90*/));
    TobilloI.write(90+round(T/*i*T/90*/));
 //   delay(5);
   // i++;
 // }
}

void PiernaD (int M, int R, int T){
//  while (int i=0 <90){ 
    MusloD.write(90-round(M/*i*M/90*/));
    RodillaD.write(90-round(R/*i*R/90*/));
    TobilloD.write(90-round(T/*i*T/90*/));
//    delay(5);
//    i++;
//  }
}

void CaderaM (int C){
  Cadera.write(90-round(C/*i*M/90*/));
}

//Prueba MegaSweep

void MegaSweep (int Md, int Rd, int Td, int Mi, int Ri, int Ti, int Hip, int Armd, int Armi, int Head, int Timelapse){// Barrido de motres: Muslo, Rodilla y Tobillo derecho, izquierdo, Cadera (hip)
  // Brazos (Arms) Derecho e izquierdo y cabeza
  // TimeLapse: Tiempo en el cual se espera se realizen los movimientos en [ms]
  //int TimeStart = millis();
  int Pasos= round(Timelapse/2.0) ;//Defino que cada paso es de 2.0 ms
  int PrevioPD[3]={MusloD.read(), RodillaD.read(), TobilloD.read()};
  int TargetPD[3]={Md, Rd, Td}; 
  int ActualPD[3]={PrevioPD};
  int PrevioPI[3]={MusloI.read(), RodillaI.read(), TobilloI.read()};
  int TargetPI[3]={Mi, Ri, Ti}; 
  int ActualPI[3]={PrevioPI};
  int PrevioTorso[3]={Cadera.read(), BrazoD.read(), BrazoI.read()};
  int TargetTorso[3]={Hip, Armd, Armi}; 
  int ActualTorso[3]={PrevioTorso};
  for (int i=0; i<Pasos; i++){
    //Obtengo la nueva posicion acorde al progreso
    Actualizar (ActualPD, PrevioPD, TargetPD, i, Pasos);
    Actualizar (ActualPI, PrevioPI, TargetPI, i, Pasos);
    Actualizar (ActualTorso, PrevioTorso, TargetTorso, i, Pasos);
    //Mando la orden a los sevos
    PiernaD(ActualPD[0], ActualPD[1], ActualPD[2]);
    PiernaI(ActualPI[0], ActualPI[1], ActualPI[2]);
    CaderaM(ActualTorso[0]);
    BrazoD.write(ActualTorso[1]);
    BrazoI.write(ActualTorso[2]);
    delay(20); //Delay acorde a Pasos
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
  for (int i=0; i<2; i++){
    resultado[i]=arr1[i]-arr2[i];
}
}

void Actualizar (int Actual[3], int Previo[3], int Target[3], int TiempoActual, int TimeTotal){ //Actualiza la variable "Actual" 
  int Diff[3];
  Resta(Target, Previo, Diff);
  for (int j=0; j<2; j++){
    Actual[j]= Previo[j] + round(TiempoActual*Diff[j]/(float)TimeTotal);
  }
}

