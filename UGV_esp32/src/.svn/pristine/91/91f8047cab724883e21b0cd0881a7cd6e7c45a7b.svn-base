
#include <Arduino.h>
#include <WiFi.h>
#include <esp32PWMUtilities.h>
#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
Motor Motor1;

Motor Motor2;
void _setup() {
  Motor1.attach(14, 16, 17);

  Motor2.attach(15, 18, 19);

  Dabble.begin("manoj");
}

void _loop() {
  Dabble.processInput();
}

void setup() {
  _setup();
}

void loop() {
  _loop();
  if (GamePad.isTrianglePressed()) {
    Motor1.moveMotor(2.55 * 100);
    Motor2.moveMotor(2.55 * 100);
  }
  else {
    if (GamePad.isCrossPressed()) {
      Motor1.moveMotor(-2.55 * 100);
      Motor2.moveMotor(-2.55 * 100);
    }
    else {
      if (GamePad.isCirclePressed()) {
        Motor1.moveMotor(2.55 * 100);
        Motor2.moveMotor(-2.55 * 100);
      }
      else {
          if (GamePad.isSquarePressed()) {
        Motor1.moveMotor(-2.55 * 100);
        Motor2.moveMotor(2.55 * 100);
      }
        
        
        
        float d = GamePad.getYaxisData();
        int PMval = 0;
        PMval = map(d, -7, 7, -255, 255);
        if (PMval > -2){
                Motor1.moveMotor(PMval);
         Motor2.moveMotor(PMval);
        }
       
        else{
         if (PMval < -5 ){
        Motor1.moveMotor(-210);
        Motor2.moveMotor(-210);
       
        }
        else {
          Motor1.lockMotor();
          Motor2.lockMotor();
        
        }
        }
        }
    }
    }
    }
