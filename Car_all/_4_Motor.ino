void OnFwd(int power_R, int power_L) {
  if (power_R >= 0) {
    int power_R_PWM = power_R;
    if (power_R_PWM > 255)
      power_R_PWM = 255;
    analogWrite(PIN_Motor1, power_R_PWM);
    analogWrite(PIN_Motor2, 0);
  }
  else {
    int power_R_PWM = -power_R;
    if (power_R_PWM > 255)
      power_R_PWM = 255;
    analogWrite(PIN_Motor1, 0);
    analogWrite(PIN_Motor2, power_R_PWM);
  }
  if (power_L >= 0) {
    int power_L_PWM = power_L;
    if (power_L_PWM > 255)
      power_L_PWM = 255;
    analogWrite(PIN_Motor3, power_L_PWM);
    analogWrite(PIN_Motor4, 0);
  }
  else {
    int power_L_PWM = -power_L;
    if (power_L_PWM > 255)
      power_L_PWM = 255;
    analogWrite(PIN_Motor3, 0);
    analogWrite(PIN_Motor4, power_L_PWM);
  }
}//end of void OnFwd(int power_R, int power_L)

//==================================
void OnFwdTime(int power_R, int power_L, int delaytime) {
  OnFwd(power_R, power_L);
  delay(delaytime);
}//end of void OnFwdTime(int power_R, int power_L, int delaytime)

//==================================
void switch_moving(int num_action) {
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
    case 'x':
      OnFwdTime(-80, -80, 2000);
      OnFwd(0, 0);
      break;    
    default:
      OnFwd(0, 0);
      break;
  }
}//end of switch_moving(int num_action)
