#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H
#include <iostream>
#include <string>
#include "Exception.h"

namespace planning
{
    using namespace std;

    class TimingException : public Exception
    {
    private:
        int code;

    public:
        static int INVALID_DAY;
        static int NO_TIMING;
        static int TIMING_NOT_AVAIBLE;

        TimingException();
        TimingException(const TimingException &) = default;
        TimingException(int, string);
        ~TimingException() = default;

        void setCode(int);
        int getCode();
    };
}
#endif