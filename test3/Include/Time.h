#ifndef TIME_H
#define TIME_H

namespace planning
{
    class Time
    {
    //Les int -+ Time
    friend  Time operator+(int,Time );
    friend  Time operator-(int,const Time&);


    // les Time +- Time
    friend  Time operator+(const Time&,const Time&);    
    friend  Time operator-(const Time&,const Time&);   



    /* il sont en friend car chaque instance de classe ne peut acceder uniquement 
    a ses propres parametre, hors ici on a plusieurs instance d'une meme classe, donc on a besoin 
    de lui autoriser l'acces partout*/


    private:
        int hour;
        int minute;

    public:
        // constructeur
        Time(); //initiliateur

        Time(int h, int m); //constructeur par défaut de sur une heure et des minutes

        Time(int duree); //construucteur par défaut de sur des minutes

        Time(const Time &x); // constructeur de copie


        //operateur d'affectatio

        void setHour(int h);

        void setMinute(int m);

        int getHour() const;

        int getMinute() const;

        void display() const;

        //operateur de surcharge

        const Time& operator=(const Time&);

        Time operator+(int);     // Time - Int
        
        Time operator-(int);     //Time + int


        //destructeur

        ~Time();
    };
}
#endif