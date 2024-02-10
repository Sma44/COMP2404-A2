#ifndef TIME_H
#define TIME_H

class Time
{
  public:
    Time(int=0, int=0);
    void print();

  private:
    int  hours;
    int  minutes;
    void set(int, int);
    int  convertToMins();
};

#endif
