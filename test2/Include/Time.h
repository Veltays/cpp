#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int hour;
    int minute;

public:
    Time(); //initiliateur

    Time(int h, int m); //construucteur par défaut de sur une heure et des minutes

    Time(int duree); //construucteur par défaut de sur des minutes

    Time(const Time &x); // constructeur de copie


    void setHour(int h);

    void setMinute(int m);

    int getHour() const;

    int getMinute() const;

    void display() const;

    ~Time();
};
#endif