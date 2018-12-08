#include <Servo.h>'=
struct Motor{
  Servo motor;
  int cur;
  void init(int pin);
  void rotateUntil(int deg);
  void rotateNext(int deg);
  };


void Motor::init(int pin){
  motor.attach(pin);
  cur=0;
  motor.write(cur);
  }

  
void Motor::rotateUntil(int deg){
    cur=deg;
    motor.write(cur);
  }

void Motor::rotateNext(int deg){
    cur+=deg;
    cur%=360;
    motor.write(cur);
  }
