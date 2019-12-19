#include <sensor_control.h>
#include <Arduino.h>

sensor_control::sensor_control(int PIN_Light_Digital,int PIN_Light_Analog,int PIN_Trig,int PIN_Echo) {
  pinMode(PIN_Light_Digital, INPUT);
  pinMode(PIN_Light_Analog, INPUT);
  _PIN_Light_Digital=PIN_Light_Digital;
  _PIN_Light_Analog=PIN_Light_Analog;
  _PIN_Echo=PIN_Echo;
  _PIN_Trig=PIN_Trig;
}

void sensor_control::Get_distance() {
  digitalWrite(_PIN_Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(_PIN_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_PIN_Trig, LOW);
  microsec = pulseIn(_PIN_Echo, HIGH);
  cmMsec = (microsec / 2) / 29.1; //將時間換算成距離cm
}//end of void Get_distance()

int sensor_control::GetR_distance() {
  digitalWrite(_PIN_Trig, LOW);
  delayMicroseconds(5);
  digitalWrite(_PIN_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_PIN_Trig, LOW);
  microsec = pulseIn(_PIN_Echo, HIGH);
  cmMsec = (microsec / 2) / 29.1; //將時間換算成距離cm
  return cmMsec;
}//end of void Get_distance()


//==================================
void sensor_control::Get_light() {
  light_digital = digitalRead(_PIN_Light_Digital);
  light_analog = analogRead(_PIN_Light_Analog);
}//end of void Get_light()

int sensor_control::GetR_light(char type) {
  if(type =='D'){
    light_digital = digitalRead(_PIN_Light_Digital);
    return light_digital;}
  else if (type =='A'){
    light_analog = analogRead(_PIN_Light_Analog);
    return light_analog;}
  else
    return -1;
}//end of void Get_light()