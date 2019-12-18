void Get_distance() {
  digitalWrite(PIN_Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_Trig, LOW);
  microsec = pulseIn(PIN_Echo, HIGH);
  cmMsec = (microsec / 2) / 29.1; //將時間換算成距離cm
}//end of void Get_distance()

int GetR_distance() {
  digitalWrite(PIN_Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_Trig, LOW);
  microsec = pulseIn(PIN_Echo, HIGH);
  cmMsec = (microsec / 2) / 29.1; //將時間換算成距離cm
  return cmMsec;
}//end of void Get_distance()


//==================================
void Get_light() {
  light_digital = digitalRead(PIN_Light_Digital);
  light_analog = analogRead(PIN_Light_Analog);
}//end of void Get_light()

int GetR_light(char type) {
  if(type =='D'){
    light_digital = digitalRead(PIN_Light_Digital);
    return light_digital;}
  else if (type =='A'){
    light_analog = analogRead(PIN_Light_Analog);
    return light_analog;}
  else
    return -1;
}//end of void Get_light()
