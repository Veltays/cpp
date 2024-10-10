#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Timing.h"
#include "Time.h"

Timing::Timing()
{
    cout << "Initilisation" << endl;
    setDay("default");
    setStart(0);
    setDuration(0);
};

Timing::Timing(string d, Time str, Time dur)
{
    cout << "Constructeur par défaut" << endl;
    setDay(d);
    setStart(str);
    setDuration(dur);
};

Timing::Timing(const Timing &x)
{
    cout << "Constructeur de copie" << endl;
    setDay(x.getDay());
    setStart(x.getStart());
    setDuration(x.getDuration());
};

Timing::~Timing()
{
    cout << "Destructeur" << endl;
};

void Timing::setDay(string jour)
{
    if (jour.empty())
        return;

    if (jour == "lundi" || jour == "Lundi")
    {
        day = "Lundi";
    }
    else if (jour == "mardi" || jour == "Mardi")
    {
        day = "Mardi";
    }
    else if (jour == "mercredi" || jour == "Mercredi")
    {
        day = "Mercredi";
    }
    else if (jour == "jeudi" || jour == "Jeudi")
    {
        day = "Jeudi";
    }
    else if (jour == "vendredi" || jour ==  "Vendredi")
    {
        day = "Vendredi";
    }
    else if (jour == "samedi" || jour == "Samedi")
    {
        day = "Samedi";
    }
    else if (jour == "dimanche" || jour == "Dimanche")
    {
        day = "Dimanche";
    }
    else if (jour == "default" || jour == "Default")
    {
        day = "default";
    }
    else
    {
    
        cout << "Jour non valide." << endl;
    }
}

void Timing::setStart(Time str)
{
    start.setHour(str.getHour());
    start.setMinute(str.getMinute());
}

void Timing::setDuration(Time dur)
{
    duration.setHour(dur.getHour());
    duration.setMinute(dur.getMinute());
}


const string Timing::getDay() const
{
    return day;
}

Time Timing::getStart() const
{
    return start;
}

Time Timing::getDuration() const
{
    return duration;
}

void Timing::display() const
{
    cout << "Date :" << day << endl;
    cout << " Le début de l'évenement est à " << start.getHour() << ":" << start.getMinute() << "Heure"<<endl;
    cout << " Le durée de l'évenement est de " << start.getHour() << ":" << start.getMinute() << "Heure"<<endl;
}