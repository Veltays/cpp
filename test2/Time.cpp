#include <stdlib.h>
#include <iostream>
#include <cstring>

#include "Time.h"

    Time::Time(){
        cout <<"Constructeur par défaut" << endl;
    }

    Time(int h, int m);

    Time(const Time& x);


