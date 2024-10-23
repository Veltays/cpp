#ifndef TIME_H
#define TIME_H

namespace planning
{
    class Time
    {
    friend  Time operator+(int,const Time&);
    //friend  Time operator+(const Time&,const Time&);


    private:
        int hour;
        int minute;

    public:
        // constructeur
        Time(); //initiliateur

        Time(int h, int m); //construucteur par défaut de sur une heure et des minutes

        Time(int duree); //construucteur par défaut de sur des minutes

        Time(const Time &x); // constructeur de copie


        //operateur d'affectatio 

        void setHour(int h);

        void setMinute(int m);

        int getHour() const;

        int getMinute() const;

        void display() const;

        //operateur de surcharge

        Time operator+(int);
        
        const Time& operator=(const Time&);

        

        //destructeur

        ~Time();
    };
}
#endif