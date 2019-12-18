void Face_test() {
  for (int i = 0; i <= 14; i++) {
    face(i);
    delay(delayTime);
  }
}

//==================================
void Buzzer_test() {
  for (int i = 0; i <= 18; i++) {
    sing(i);
    delay(500);
  }
}

//==================================
void Ultrasound_test () {
  Get_distance();
  Serial.print("MS: ");
  Serial.print(microsec);
  Serial.print(", CM: ");
  Serial.print(cmMsec);
  Serial.println();
  delay(50);
}

//==================================
void Light_test () {
  Get_light();
  Serial.print("Digital: ");
  Serial.print(light_digital);
  Serial.print(", Analog: ");
  Serial.print(light_analog);
  Serial.println();
  delay(50);
}

//==================================
void Motor_test() {
  OnFwd(80, 0);//power should be -250~250
  delay(5000);
  OnFwd(-80, 0);
  delay(5000);
  OnFwd(0, 80);
  delay(5000);
  OnFwd(0, -80);
  delay(5000);
  OnFwd(0, 0);
  delay(50000);
}
