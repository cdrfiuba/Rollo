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
//  R03 = Identidad;
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
  Serial.println(Angulos[1], DEC);
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
