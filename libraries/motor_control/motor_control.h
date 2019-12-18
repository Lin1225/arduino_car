class motor_control
{
  public:
    motor_control(int PIN_Motor1,int PIN_Motor2,int PIN_Motor3,int PIN_Motor4);
    void OnFwd(int power_R, int power_L);
    void OnFwdTime(int power_R, int power_L, int delaytime);
    void switch_moving(int num_action);
    void say();
    
  private:
    int _PIN_Motor1;
    int _PIN_Motor2;
    int _PIN_Motor3;
    int _PIN_Motor4; 
};
