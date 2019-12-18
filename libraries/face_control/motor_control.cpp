#include <face_control.h>
#include <Arduino.h>
#include "LedControl.h"

face_control::face_control(int PIN_DIN,int PIN_CLK,int PIN_CS,int num) {
  
  LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, num);//(DataIn, CLK, LOAD, numDevices)
  lc.shutdown(0, false);  //模組0
  lc.setIntensity(0, 2);  //模組0
  lc.clearDisplay(0);     //模組0
}

void face_control::display_mouth(byte mouth[]) {
  //Examples:
  //  display_mouth(mouth_8);
  for (int i = 0; i < 8; i++) {
    lc.setColumn(1, i, mouth[i]);
    lc.setColumn(0, i, mouth[i + 8]);
  }
}
void face_control::face(int num_face) {
  switch (num_face) {
    case 0:
      display_mouth(mouth_0);
      break;
    case 1:
      display_mouth(mouth_1);
      break;
    case 2:
      display_mouth(mouth_2);
      break;
    case 3:
      display_mouth(mouth_3);
      break;
    case 4:
      display_mouth(mouth_4);
      break;
    case 5:
      display_mouth(mouth_5);
      break;
    case 6:
      display_mouth(mouth_6);
      break;
    case 7:
      display_mouth(mouth_7);
      break;
    case 8:
      display_mouth(mouth_8);
      break;
     default:
      break;
  }
}//end of void face(int num_face)



void face_control::say() {
  Serial.println("test done");
}