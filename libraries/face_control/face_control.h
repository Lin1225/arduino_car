class face_control
{
  public:
    face_control(int PIN_Motor1,int PIN_Motor2,int PIN_Motor3,int PIN_Motor4);
    void face(int num_face);

    void say();
    
  private:
    void display_mouth(byte *);
};

