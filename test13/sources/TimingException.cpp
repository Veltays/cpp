#include "TimingException.h"

namespace planning
{
    int TimingException::INVALID_DAY = 4;
    int TimingException::NO_TIMING = 5;
    int TimingException::PROFESSOR_NOT_AVAIBLE = 15;
    int TimingException::CLASSROOM_NOT_AVAIBLE = 16;
    int TimingException::GROUP_NOT_AVAIBLE = 17;
    TimingException::TimingException() : Exception()
    {
        code = 0;
    }

    TimingException::TimingException(int c, string msg) : Exception(msg)
    {
        code = c;
    }

    void TimingException::setCode(int co)
    {
        code = co;
    }

    int TimingException::getCode()
    {
        return code;
    }
}