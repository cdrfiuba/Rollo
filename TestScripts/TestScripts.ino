#include <Servo.h> 

const int G[3][3]={{0, 0, 0},{150, 140, 0},{0, 0, 0}};
float angulos[3];
const int Matriz[4][4]={{1, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0},{0, 0, 0, 1}};

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop(){
//for (i=1; i=3; i++){
//    A=A*{{cosd(angulos(i)), 
  Serial.println(Matriz[4][1], DEC);
    Serial.println(Matriz[4][2], DEC);
      Serial.println(Matriz[4][3], DEC);
        Serial.println(Matriz[4][4], DEC);
}
