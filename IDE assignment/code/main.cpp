/*Code by Shreyash Chandra
 August, 2022
 under FWC program by IITH
 Design 4x2 encoder */

#include <Arduino.h>
//Declaring all variables as integers
int D0=0,D1=0,D2=0,D3=0;
int Q1,Q0;
//output display with the help of pin 13 & a LED at pin 4
void disp_encoder(int Q1, int Q0)
{
  digitalWrite(13, Q1); 
  digitalWrite(4, Q0); 
  
    
}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(4, OUTPUT);  
    pinMode(13, OUTPUT);
    pinMode(8, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT); 
    
}

// the loop function runs over and over again forever
void loop() {
    D1 = digitalRead(5);
    D2 = digitalRead(6);
    D3 = digitalRead(7);
    D0 = digitalRead(8);
    Q0= D1 || D3; // logic: (!D3&&!D2&&D1&&!D0) || (D3&&!D2&&!D1&&!D0);
    Q1= D2 || D3; // logic: (!D3&&D2&&!D1&&!D0) || (D3&&!D2&&!D1&&!D0);
    disp_encoder(Q1,Q0);   

}
