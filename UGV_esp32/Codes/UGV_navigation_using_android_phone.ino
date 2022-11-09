#include <esp32PWMUtilities.h>
#include <DabbleESP32.h>

Motor Motor1;
Motor Motor2;

void _setup() {
  Motor1.attach(14, 16, 17); //Defining pins for Motor-1

  Motor2.attach(15, 18, 19);  //Defining pins for Motor-1

  Dabble.begin("Esp32");
}

void _loop() {
  Dabble.processInput(); //Continously process input from the dabble app over bluetooth
}

void setup() {
  _setup();
}

void loop() {
  _loop();
  if (GamePad.isPressed(0)) { //Move forward
    Motor1.moveMotor(100);
    Motor2.moveMotor(100); 
  }
  else {
    if (GamePad.isPressed(1)) { //Move backward
      Motor1.moveMotor(-100);
      Motor2.moveMotor(-100);
    }
    else {
      if (GamePad.isPressed(3)) { //Move right
        Motor1.moveMotor(100);
        Motor2.moveMotor(-100);
      }
      else {
        if (GamePad.isPressed(2)) { //Move left
          Motor1.moveMotor(-100);
          Motor2.moveMotor(100);
        }
        else {
          Motor1.lockMotor(); //Stop
          Motor2.lockMotor();
        }
      }
    }
  }
}
