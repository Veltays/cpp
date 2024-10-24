#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Time.h"
namespace planning
{

    Time::Time()
    {

        setHour(0);
        setMinute(0);
    };

    Time::Time(int h, int m)
    {

        setHour(h);
        setMinute(m);
    };

    Time::Time(int duree)
    {

        setHour(duree / 60);
        setMinute(duree % 60);
    };

    Time::Time(const Time &x)
    {

        setHour(x.getHour());
        setMinute(x.getMinute());
    };

    Time::~Time(){
        //cout << "Destructeur" << endl;
    };

    void Time::setHour(int h)
    {
        if (h < 0 || h >= 24)
            return;
        hour = h;
    };

    void Time::setMinute(int min)
    {
        if (min < 0 || min >= 60)
            return;
        minute = min;
    }

    int Time::getHour() const
    {
        return hour;
    }

    int Time::getMinute() const
    {
        return minute;
    }

    void Time::display() const
    {
        if (minute == 0)
        {
            cout << "Il est actuellement " << hour << ":" << "00" << endl;
        }
        else
        {
            cout << "Il est actuellement " << hour << ":" << minute << endl;
        }
        
    }

    const Time &Time::operator=(const Time &x)
    {
        hour = x.hour;
        minute = x.minute;
        return (*this);
    }

    Time Time::operator+(int minAdd)
    {
        Time d(*this);
        int hourAdd = d.hour;
        minAdd = minAdd + d.minute;

        if (minAdd == 0)
            return d;

        if (minAdd >= 60)
        {
            hourAdd = hourAdd + (minAdd / 60);
            minAdd = minAdd % 60;
        }
        if (hourAdd >= 24) //si l'heure depasse 23h59
            hourAdd = hourAdd % 24;
            
        d.hour = hourAdd;
        d.minute = minAdd;

        return d;
    }

    Time operator+(int minAdd, Time x)
    {
        return x + minAdd;
    }

    Time operator+(const Time &a, const Time &b)
    {
        Time d;

        int hourAdd = a.hour + b.hour;
        int minAdd = a.minute + b.minute;

        if (minAdd >= 60)
        {
            hourAdd = hourAdd + (minAdd / 60);
            minAdd = minAdd % 60;
        }
        if (hourAdd >= 24) //si l'heure depasse 23h59
            hourAdd = hourAdd % 24;

        d.minute = minAdd;
        d.hour = hourAdd;

        return d;
    }

    Time Time::operator-(int minAdd)
    {
      
        Time d(*this);
        int minX = (d.hour * 60) + d.minute;
        cout << "Minute de this" << minX << endl;

        minAdd = abs(minAdd - minX);
        
        cout << "MinuteAdd " << minAdd << endl;

        if (minAdd < 0)
        {
           minAdd = minAdd + (24*60);     //ainsi le mod donnera une reponse coherente
        }
        
        d.minute = minAdd %60;
        d.hour = minAdd /60;
        
        return d;
    }

    Time operator-(int minAdd, const Time &x)
    {
        Time d;
        int minX = (x.hour * 60) + x.minute;
        cout << "Minute " << minX << endl;

        
        minAdd = minAdd - minX;

        if (minAdd < 0)
        {
           minAdd = minAdd + (24*60);     //ainsi le mod donnera une reponse coherente
        }


        d.minute = minAdd %60;
        d.hour = minAdd /60;
        
        return d;
    }


    Time operator-(const Time &a, const Time &b)
    {
        Time d;
        

        int minA = (a.hour * 60) + a.minute;
        int minB = (b.hour * 60) + b.minute;

        int minAdd = minA - minB;

        if (minAdd < 0)
        {
            minAdd = minAdd + (24*60);
        }
        
        d.minute = minAdd %60;
        d.hour = minAdd /60;

        return d;
    }

    int Time::operator>(const Time &x){
        return compTime(x) == -1;

    }

    int Time::operator<(const Time &x){
        return compTime(x) == 1;

    }

    int Time::operator==(const Time &x){
        return compTime(x) == 0;

    }

    int Time::compTime(const Time& x)
    {
        //comparaison des heure 
        if(hour < x.hour)     
            return 1;
        if(hour > x.hour)
            return -1;

        //comparaison des minute
        if(minute < x.minute)     
            return 1;
        if(minute > x.minute)
            return -1;

        //égalité 
        return 0;

    }

    ostream& operator<<(ostream& s,const Time& x)
    {
        s << x.hour << "h" << x.minute;
        return s;
    }

    istream& operator>>(istream& s, Time& x)
    {
        int heure, minute;
        do
        {
            cout <<endl << "entrer une heure entre (0-23)" << endl;
            s >> heure;
        }while (heure < 0 || heure >= 24);
        
        do
        {
            cout << "entre des minutes" <<endl;
            s >> minute;
        }while(minute < 0 || minute >= 60);

        x.minute = minute;
        x.hour = heure;
        return s;
    }


    
}
