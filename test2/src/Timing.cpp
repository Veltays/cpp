#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Timing.h"
#include "Time.h"

namespace planning
{

    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

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

        if (jour == MONDAY)
        {
            day = "Lundi";
        }
        else if (jour == TUESDAY)
        {
            day = "Mardi";
        }
        else if (jour == WEDNESDAY)
        {
            day = "Mercredi";
        }
        else if (jour == THURSDAY)
        {
            day = "Jeudi";
        }
        else if (jour == FRIDAY)
        {
            day = "Vendredi";
        }
        else if (jour == SATURDAY)
        {
            day = "Samedi";
        }
        else if (jour == SUNDAY)
        {
            day = "Dimanche";
        }
        else
            cout << "Jour non valide." << endl;
        day = "Jour non valide.";
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
        cout << " Le début de l'évenement est à " << start.getHour() << ":" << start.getMinute() << "Heure" << endl;
        cout << " Le durée de l'évenement est de " << start.getHour() << ":" << start.getMinute() << "Heure" << endl;
    }

}