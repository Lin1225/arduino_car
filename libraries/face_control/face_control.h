#include "LedControl.h"
class face_control
{
  public:
    face_control(int PIN_DIN,int PIN_CLK,int PIN_CS,int num);
    
    void face(int num_face);
    void face_say();
  private:
    void display_mouth(int * mouth);
    LedControl _lc = LedControl(2, 3, 4, 1);
};

