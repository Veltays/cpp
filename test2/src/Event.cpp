#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Event.h"
#include "Timing.h"
#include "time.h"

namespace planning
{
  int Event::currentCode = 1;

  Event::Event() // Constructeur d'initilisation
  {
    cout << "Defaut" << endl;
    setCode(1);
    title = nullptr;
    setTitle("default");
    timing = nullptr;
  };

  Event::Event(int c, const char *t) // constructeur par défaut
  {
    cout << "Constructeur initialisation" << endl;
    setCode(c);
    title = nullptr;
    setTitle(t);
    timing = nullptr;
    currentCode += 1;
  };

  Event::Event(const Event &e) //constructeur de copie

  {
    cout << "Constructeur de copie" << endl;
    setCode(e.getCode());
    title = nullptr;
    timing = new Timing(*(e.timing));
  };
  Event::~Event()
  { //destructeur
    cout << " DESTRUCTEUR " << endl;
    delete title;
    if (timing != nullptr)
      delete timing;
    currentCode -= 1;
  };

  const char *Event::getTitle() const
  {
    return title;
  }

  int Event::getCode() const
  {
    return code;
  }

  Timing Event::getTiming() const
  {
    return *timing;
  }

  void Event::setTitle(const char *t)
  {
    if (title != nullptr)
      delete title;
    title = new char[strlen(t) + 1];
    strcpy(title, t);
  }

  void Event::setCode(int c)
  {
    if (c < 0)
      return;
    code = c;
  }

  void Event::setTiming(const Timing &temp)
  {
    if (timing != nullptr)
      delete timing;
    timing = new Timing(temp);
  }

  void Event::display() const
  {
    cout << "display---------------------------" << endl;
    cout << "title = " << title << endl;
    cout << "code = " << code << endl;
    if (timing != nullptr)
      timing->display();
  }
}