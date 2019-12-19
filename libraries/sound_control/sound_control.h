class sound_control
{
  public:
    sound_control(int PIN_buzzer);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void sing(int songName);
    
  private:
    void _tone(float noteFrequency, long noteDuration, int silentDuration);
    int _PIN_buzzer;
};
