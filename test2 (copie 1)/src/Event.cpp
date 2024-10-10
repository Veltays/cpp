#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Event.h"
#include "Timing.h"
#include "time.h"


Event::Event()                       // Constructeur d'initilisation
    {
      cout << "Initialisation" << endl;
      setCode(2);
      title = nullptr;
      setTitle("default");
      timing->setDay("default");
      timing->setDuration(Time(0));
      timing->setStart(Time(0));
    };

Event::Event(int c, const char* t,const Timing& temp)   // constructeur par défaut
    {
      cout << "Constructeur par défaut"<< endl;
      setCode(c);
      title = nullptr;
      setTitle(t);
      timing->setDay(temp.getDay());
      timing->setDuration(temp.getDuration());
      timing->setStart(temp.getStart());

    };

Event::Event (const Event& e)  //constructeur de copie
    {
      cout <<"Constructeur de copie" << endl;
      setCode(e.getCode());
      title = nullptr;
      setTitle(e.getTitle());
    };
Event::~Event(){                //destructeur
      cout << " DESTRUCTEUR " << endl;
      delete title;
      if(timing != nullptr)
        delete timing;
    };
  
const char* Event::getTitle() const{
      return title;
    }

int Event::getCode() const {
  return code;
  }

Timing Event::getTiming() const
{
  cout << "caca";

}

void Event::setTitle(const char* t)
    {
      if(title != nullptr)
        delete title;
      title = new char [strlen(t) + 1];
      strcpy(title,t);
    }


void Event::setCode(int c)
    {
      if(c < 0)
        return;
      code = c;
    }

void Event::setTiming(const Timing& temp)
{
  timing->setDay(temp.getDay());
  timing->setStart(temp.getStart());
  timing->setDuration(temp.getDuration());
}

void Event::display() const{
      cout << "display---------------------------" << endl;
      cout << "title = " << title << endl;
      cout << "code = " << code << endl;
      timing->display();
  }