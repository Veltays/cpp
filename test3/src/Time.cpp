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
        setMinute(10);
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

    Time::~Time()
    {
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
        cout << "Il est actuellement " << hour << ":" << minute << endl;
    }

    const Time& Time::operator=( const Time& x)
    {
        hour = x.hour;
        minute = x.minute;
        cout << "operator = est effectivement utilisé et non la copie" << endl;
        return (*this);
    }


    Time Time::operator+(int minAdd)
    {
        Time d(*this);
        int heurAdd = 0;
        
        if (minAdd == 0) 
            return d;

        if(minAdd >= 60)
        {
            heurAdd = minAdd / 60;
            minAdd = minAdd % 60;
        }
        d.hour += heurAdd;
        d.minute += minAdd;
        return d;
    }



    Time operator+(int minAdd, const Time& x)
    {
        Time d;
        int heurAdd = 0;

        if (minAdd == 0) 
            return x;

        if (minAdd > 60)
        {
            heurAdd /= 60;
            minAdd %=  60;
        }
        d.hour = x.hour + heurAdd;
        d.minute = x.minute + minAdd;
        return d;
    }

}
