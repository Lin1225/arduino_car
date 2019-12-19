class sensor_control
{
  public:
    sensor_control(int PIN_Light_Digital,int PIN_Light_Analog,int PIN_Trig,int PIN_Echo);
    void Get_light();
    int GetR_light(char type);
    int GetR_distance();
    void Get_distance();

  private:
    int _PIN_Light_Digital;
    int _PIN_Light_Analog;
    int _PIN_Trig;
    int _PIN_Echo;
    int microsec;
    int cmMsec;
    int light_digital;
    int light_analog;
};
