#include <Servo.h> 

//const int L1 = 150; // Distancia en mm desde el eje Muslo al eje Rodilla
//const int L2 = 145; // Distancia en mm desde el eje Rodilla al eje Tobillo
//const int L3 = 31; // Distancia en mm desde el eje Tobillo al suelo (referencia)
const char DANCE_MOVE_DURA = 'D';

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

/* Pierna izquierda > 90 ------   Adelante    /
                                             _|
   
   Pierna derecha > 90 --------   Atras      \
                                             _|
                                             */
//int i=0;

//char Inicio='Izquierda';
//int pasos =5;


// Prototipos: definir las funciones arriba para avisar que existen mas abajo

//void PiernaD (int M, int R, int T);

void setup() 
{
  Serial.begin(9600);
  // Asigno cada servo a una salida "analogica"  
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
  Torso(0, 0,0);
  Cabeza.write(90);

}

void loop() { 
//  delay(500);
//  BrazoD.write(90-45);
//  BrazoI.write(90+45);
  delay(1000);
  //espera 1 segundo desde que se conecta
  //Walking(/*'Izquierda',*/ 5);
  Dance(DANCE_MOVE_DURA);
  delay(2000);
} 

void Dance(char DanceMove){
  int A=millis();
  
  Serial.println("sin switch");
  
  switch (DanceMove){
    case DANCE_MOVE_DURA:
    {
    int DireccionCadera=1;
    float BPM = 90; //beats por minuto del ritmo que se baila
    int dt = round((60.0/BPM)*1000); //Variable de tiempo para marcar el ritmo
    Serial.println("Dura");
    Serial.println("9");
      for (int i=1; i<3; i++){ //Intro
        for (int j=1; j<15; j++){
          if (i==1){
            DireccionCadera = DireccionCadera*(-1);
            //Cadera.write(110+DireccionCadera*30);
            delay(dt);
            Serial.println("intro");
            A= millis();
            MegaSweep(0, 0, 0, 0, 0, 0, DireccionCadera*30, 0, 0, 0, dt);
            A= millis()-A;
            Serial.println("Invierto cadera");
            Serial.print("Tiempo Transcurrido: ");
            Serial.println(A);
            Serial.print("Tiempo Teorico: ");
            Serial.println(dt);
              
          }
          else {
            DireccionCadera = DireccionCadera*(-1);
            Serial.println("Cadera y brazos");
            if (DireccionCadera>0){
              MegaSweep(0, 0, 0, 7, -15, 8, DireccionCadera*30, DireccionCadera*45, -DireccionCadera*45, 0, dt);
             }
            else{MegaSweep(7, -15, 8, 0, 0, 0, DireccionCadera*30, DireccionCadera*45, -DireccionCadera*45, 0, dt);}
            
          }
       }
     }
            delay(dt);
            Serial.println("meneo");
     break;
    }
     default:
     Serial.println("no entro en dura");
  }
}

void Walking(/*char Inicio,*/ int pasos){
//  int tmov; //calculo tiempo de los movimientos
  int cont = 0;
  int paso_actual;
  const int dt = 5000;
  
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
//    Rodill-a2 = RodillaD;
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
   }
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
    RodillaI.write(90+R);
    TobilloI.write(90+T);

}
void PiernaIRead (int PrevioI[3]){
    PrevioI[0] = 90 - MusloI.read(); // porque esta cambiado el signo
    PrevioI[1] = RodillaI.read() - 90;
    PrevioI[2] = TobilloI.read() - 90;
}

void PiernaD (int M, int R, int T){

    MusloD.write(90-M);
    RodillaD.write(90-R);
    TobilloD.write(90-T);

}
void PiernaDRead (int PrevioD[3]){
    PrevioD[0] = 90 - MusloD.read(); // porque esta cambiado el signo
    PrevioD[1] = 90 - RodillaD.read();
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
  
  //Obtengo el valor de la posicion inicial del movimiento
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
    ElTimerloco = micros();
  }
}


void Resta (int arr1[3],int arr2[3],int resultado[3]){ //Resta 2 Arrays componente a componente y lo devuelve en "resultado"
  for (int i=0; i<3; i++){
    resultado[i]=arr1[i]-arr2[i];
  }
}

void Actualizar (int Actual[3], int Previo[3], int Target[3], int TiempoActual, int TimeTotal){ //Actualiza la variable "Actual" 
  int Diff[3];
  Resta(Target, Previo, Diff);
  for (int j=0; j<3; j++){
    Actual[j]= Previo[j] + round(TiempoActual*Diff[j]/(float)TimeTotal);
  }
}

