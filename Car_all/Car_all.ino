#include "_1_mouth.h"
#include "_2_sing.h"
#include "LedControl.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(A2, A3);

#define PIN_DIN 2     //DataIn
#define PIN_CS  3     //LOAD
#define PIN_CLK 4     //CLK
#define PIN_buzzer 13  //用Pin13 輸出方波至蜂鳴器
#define PIN_Trig 7    //Trig Pin
#define PIN_Echo 8    //Echo Pin
#define PIN_Motor1 6
#define PIN_Motor2 5
#define PIN_Motor3 9
#define PIN_Motor4 10
#define PIN_Light_Digital A1
#define PIN_Light_Analog A6

LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, 2);//(DataIn, CLK, LOAD, numDevices)
//====================
unsigned long delayTime = 1000;
long microsec;
float cmMsec;
int light_digital, light_analog;

//==================================
void setup() {
  
  Serial.begin (115200);
  mySerial.begin(9600);
  pinMode(PIN_buzzer, OUTPUT);
  pinMode(PIN_Trig, OUTPUT);
  pinMode(PIN_Echo, INPUT);
  pinMode(PIN_Motor1, OUTPUT);
  pinMode(PIN_Motor2, OUTPUT);
  pinMode(PIN_Motor3, OUTPUT);
  pinMode(PIN_Motor4, OUTPUT);
  pinMode(PIN_Light_Digital, INPUT);
  pinMode(PIN_Light_Analog, INPUT);
  //====================
  // 設定正常運作模式, true = shutdown mode ; false = normal operation
  lc.shutdown(0, false);  //模組0
  lc.shutdown(1, false);  //模組1
  // 設定亮度
  lc.setIntensity(0, 2);  //模組0
  lc.setIntensity(1, 2);  //模組1
  // 清除DSP
  lc.clearDisplay(0);     //模組0
  lc.clearDisplay(1);     //模組1
  //====================
  OnFwd(0, 0);
  face(0);
}

//==================================
void loop() {
  /*while (true) {
    Light_test();
  }*/
 /* while (true) {
    light_digital=GetR_light("D");
    if (light_digital ==0)
      OnFwd(0, 150);
    else
      OnFwd(150, 0);
  }*/
  int x;
  if (mySerial.available()) {
    x = mySerial.read();
    Serial.println(x);
    if (x == 49) //"1" is 49
      Face_test();
    else if (x == 48) //"0" is 48
      OnFwd(0, 0);
  }
  
  //Buzzer_test();
  //Face_test();
  /*while (true) {
   // Get_distance();
    /*if (GetR_distance < 20)
      sign(2);
    else
      sign(12);
  }*/
//}*/
}
