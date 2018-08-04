//#include <MatrixMath.h>
#include <math.h>
#include <Servo.h> 

const int DH[3][3]={{0, 0, 0},{150, 140, 0},{0, 0, 0}};
//mtx_type DH2[3][3]={{0, 150, 0}, {0, 140, 0}, {0, 0, 0}};
float angulos[3];
const int Matriz[4][4]={{1, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};
//mtx_type A[4][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
float Angulos[3]={30*M_PI/180, 20*M_PI/180, -10*M_PI/180};

// PAra usar matrices, los subindices empiezan en 0, es decir, 
// el ultimo valor de una matriz de 3x3 es el M[2][2]

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
        //Angulos = Angulos./(180/pi);
        
}

void loop(){
//  angulos=Angular(Angulos);
//for (i=1; i=3; i++){
//    A=A*{{cosd(angulos(i)), 
//  Serial.println(Matriz[3][0], DEC);
//  Serial.println(DH[1][0], DEC);
//  Serial.println(Matriz[3][2], DEC);
  Serial.println(Angulos[1], DEC);
  //Serial.println(Matriz, DEC);
  //Matrix.Print((mtx_type*)DH2, 3, 3, "DH");
  //int R[4][4]={{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  //for (int i= 0: i=2; i++){
    //mtx_type R0i={{cos(Angulos[i]), -sin(Angulos[i]), 0, DH[i][2]*cos(Angulos[i])}, {sin(Angulos[i]), cos(Angulos[i]), 0, DH[i][2]*sin(Angulos[i])}, {0, 0, 1,0}, {0, 0, 0, 1}};
    //Matrix.Multiply((mtx_type*)R, (mtx_type*), N, N, N, (mtx_type*)C);
}

//float  Angular(int Grados[3]){
//  float Radianes[3];
//  for (int i=0; i=2; i++){
//    Radianes[i]=Grados[i]*M_PI/180;
//  }
//  return Radianes;
//}
  

