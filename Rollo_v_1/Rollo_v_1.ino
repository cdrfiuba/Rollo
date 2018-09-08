
#include <Servo.h> 

//const int L1 = 150; // Distancia en mm desde el eje Muslo al eje Rodilla
//const int L2 = 145; // Distancia en mm desde el eje Rodilla al eje Tobillo
//const int L3 = 31; // Distancia en mm desde el eje Tobillo al suelo (referencia)
const int DH[3][3]={{0, 0, 0},{150, 140, 0},{0, 0, 0}};
const int ToolPunta[3]={30, 65, 0};
const int ToolTaco[3]={30, -33, 0};
Servo MusloI;
Servo RodillaI;
Servo TobilloI;
Servo MusloD;
Servo RodillaD;
Servo TobilloD;
Servo Cadera;

/* Pierna izquierda > 90 ------   Adelante    /
                                             _|
   
   Pierna derecha > 90 --------   Atras      \
                                             _|
                                             */
//int i=0;

//char Inicio='Izquierda';
//int pasos =5;


void setup() 
{
  
    
  MusloI.attach(A5);
  TobilloI.attach(A4);
  RodillaI.attach(A3);
  MusloD.attach(A0); 
  TobilloD.attach(A2); 
  RodillaD.attach(A1); 
  Cadera.attach(A6); // Digital 4
  MusloI.write(90);  // set servo to mid-point
  TobilloI.write(90);  
  RodillaI.write(90);  
  MusloD.write(90);  
  TobilloD.write(90);  
  RodillaD.write(90);  
  Cadera.write(90);

}
void Walking(int pasos);

void loop() { 
  delay(2000); //espera 2 segundos desde que se conecta
  Walking(/*'Izquierda',*/ 5);
  delay(10000); // espera para apagar o reposicionar
  
} 



void Walking(/*char Inicio,*/ int pasos){
//  int tmov; //calculo tiempo de los movimientos
  int cont = 0;
  //int paso_actual;
  const int dt = 300;
  
  Servo Muslo1;
  Servo Rodilla1;
  Servo Tobillo1;
  Servo Muslo2;
  Servo Rodilla2;
  Servo Tobillo2;
  int pie_delantero;  
    
//  if (Inicio == 'Izquierda'){
//    Muslo1 = MusloI;
//    Rodilla1 = RodillaI;
//    Tobillo1 = TobilloI;
//    Muslo2 = MusloD;
//    Rodilla2 = RodillaD;
//    Tobillo2 = TobilloD;
//  }else if(Inicio == 'Derecha'){
//    Muslo1 = MusloD;
//    Rodilla1 = RodillaD;
//    Tobillo1 = TobilloD;
//    Muslo2 = MusloI;
//    Rodilla2 = RodillaI;
//    Tobillo2 = TobilloI;
//  };
  if (pasos>0){
    if (pasos == 1){pasos = 2;};
    // Primer paso
    Cadera.write(30);
    PiernaI(60, 60, -30);
    delay (dt);
    Cadera.write(90);
    PiernaD( -20, 10, 30);
    PiernaI(60, 60, 30);    
    pie_delantero = 1;
    delay (dt);
    
    //pasos continuos
    while (cont < pasos-2){
      if (pie_delantero == 1){
        Cadera.write(120);
        PiernaD(-30, 10, -30);
        PiernaI(40, 30, 0);
        delay (dt);
        Cadera.write(150);
        PiernaI(20, 00, 0);
        PiernaD(50, 60, 0);
        delay (dt);
        Cadera.write(90);
        PiernaI( -20, 10, 30);
        PiernaD(60, 60, 30);    
        pie_delantero = 2;
        delay (dt);
        cont++;
      }
      else{
        Cadera.write(60);
        PiernaI(-30, 10, -30);
        PiernaD(40, 30, 0);
        delay (dt);
        Cadera.write(30);
        PiernaD(20, 00, 0);
        PiernaI(50, 60, 0);
        delay (dt);
        Cadera.write(90);
        PiernaD( -20, 10, 30);
        PiernaI(60, 60, 30);    
        pie_delantero = 1;
        delay (dt);
        cont++;
      }
      
      //detencion
      if (pie_delantero == 1){
        Cadera.write(120);
        PiernaD(-30, 10, -30);
        PiernaI(40, 30, 0);
        delay (dt);
        Cadera.write(150);
        PiernaI(10, 00, 0);
        PiernaD(20, 50,30);
        delay (dt);
        Cadera.write(90);
        PiernaD( 0, 0, 0);
        PiernaI(00, 00, 00);    
        pie_delantero = 2;
        delay (dt);
      }
      else{
        Cadera.write(30);
        PiernaI(-30, 10, -30);
        PiernaD(40, 30, 0);
        delay (dt);
        Cadera.write(60);
        PiernaD(10, 00, 0);
        PiernaI(20, 50,30);
        delay (dt);
        Cadera.write(90);
        PiernaI( 0, 0, 0);
        PiernaD(00, 00, 00);    
        pie_delantero = 2;
        delay (dt);
      }
      
      
      
//      PiernaI(60, 60, 0);
//      PiernaD( -20, 10, 30);
    }
  }
  
//  while (int i=0 <90){ // doblo la otra rodilla un poco
//    Muslo1.write(90+round(i*90/90)); // reemplazar por Muslo1.write(Muslo1.read()+i*90/90)
//    Rodilla1.write(90+round(i*90/90));
//    Tobillo1.write(90-round(i*40/90));
//    delay(5);
//    i++;
//  }
//  
//  while (i>-90){
//    MusloI.write(90+round(i*70/90));
//    RodillaI.write(90+round(i*50/90));
//    TobilloI.write(90+round(i*40/90));
//    MusloD.write(10);
//    delay(5);
//    i--;
//        }
//  while (i<0){
//    MusloI.write(90+round(i*70/90));
//    RodillaI.write(90+round(i*50/90));
//    TobilloI.write(90+round(i*40/90));
//    delay(5);
//    i++;
//  }
//  MusloI.write(90);  // set servo to mid-point
//  TobilloI.write(90);  // set servo to mid-point
//  RodillaI.write(90);  // set servo to mid-point
//  MusloD.write(90);
//  delay(2000);  
  
}



// Funciones Auxiliares cosd y sind
int cent(float angle){
  float centrado;
  
  centrado = 90 + round(angle);
  return centrado;
}

void Directo(float* angulos[]) {
  //float A[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
  
  for (int i=1; i<=3; i++) {
    for (int j=1; j<=3; j++) {
      angulos[i][j] = angulos[i][j] * cosd(angulos[i][j]);
    }
  }
}

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
    MusloI.write(90+round(M/*i*M/90*/));
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

//Funcion problema directo


 
 
 //Funcion Problema Inverso
 
