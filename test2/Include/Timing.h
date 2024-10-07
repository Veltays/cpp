#ifndef TIMING_H
#define TIMING_H

#include <string>
#include "Time.h"
using namespace std;


class Timing
{
    private:
        string day;
        Time start;
        Time duration;
    public:

        Timing();

        Timing(string d, Time str, Time dur);

        Timing(const Timing &x);

        ~Timing();

        void setDay(string jour);

        void setStart(Time str);

        void setDuration(Time dur);

        const string getDay() const;

        Time getStart() const;

        Time getDuration() const;

        void display() const;
};
#endif