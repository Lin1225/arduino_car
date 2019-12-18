#include <motor_control.h>
#include <Arduino.h>

motor_control::motor_control(int PIN_Motor1,int PIN_Motor2,int PIN_Motor3,int PIN_Motor4) {
  _PIN_Motor1=PIN_Motor1;
  _PIN_Motor2=PIN_Motor2;
  _PIN_Motor3=PIN_Motor3;
  _PIN_Motor4=PIN_Motor4;
  
  pinMode(_PIN_Motor1, OUTPUT);
  pinMode(_PIN_Motor2, OUTPUT);
  pinMode(_PIN_Motor3, OUTPUT);
  pinMode(_PIN_Motor4, OUTPUT);
  
}



void motor_control::OnFwd(int power_R, int power_L) {
  if (power_R >= 0) {
    int power_R_PWM = power_R;
    if (power_R_PWM > 255)
      power_R_PWM = 255;
    analogWrite(_PIN_Motor1, power_R_PWM);
    analogWrite(_PIN_Motor2, 0);
  }
  else {
    int power_R_PWM = -power_R;
    if (power_R_PWM > 255)
      power_R_PWM = 255;
    analogWrite(_PIN_Motor1, 0);
    analogWrite(_PIN_Motor2, power_R_PWM);
  }
  if (power_L >= 0) {
    int power_L_PWM = power_L;
    if (power_L_PWM > 255)
      power_L_PWM = 255;
    analogWrite(_PIN_Motor3, power_L_PWM);
    analogWrite(_PIN_Motor4, 0);
  }
  else {
    int power_L_PWM = -power_L;
    if (power_L_PWM > 255)
      power_L_PWM = 255;
    analogWrite(_PIN_Motor3, 0);
    analogWrite(_PIN_Motor4, power_L_PWM);
  }
}//end of void OnFwd(int power_R, int power_L)

//==================================
void motor_control::OnFwdTime(int power_R, int power_L, int delaytime) {
  OnFwd(power_R, power_L);
  delay(delaytime);
}//end of void OnFwdTime(int power_R, int power_L, int delaytime)

//==================================
void motor_control::switch_moving(int num_action) {
  switch (num_action) {
    case 'w':
      OnFwdTime(80, 80, 2000);
      OnFwd(0, 0);
      break;
    case 'a':
      OnFwdTime(80, -80, 500);
      OnFwd(0, 0);
      break;
    case 'd':
      OnFwdTime(-80, 80, 500);
      OnFwd(0, 0);
      break;
    case 's':
      OnFwdTime(-80, -80, 2000);
      OnFwd(0, 0);
      break;    
    default:
      OnFwd(0, 0);
      break;
  }
}//end of switch_moving(int num_action)

void motor_control::say() {
  Serial.println("test done");
}