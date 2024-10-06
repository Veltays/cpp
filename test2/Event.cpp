#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Event.h"


Event::Event()                       // Constructeur d'initilisation
    {
      cout << "Initialisation" << endl;
      setCode(2);
      title = nullptr;
      setTitle("default");
    };

Event::Event(int c, const char* t)   // constructeur par défaut
    {
      cout << "Constructeur par défaut"<< endl;
      setCode(c);
      title = nullptr;
      setTitle(t);
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
    };
  

const char* Event::getTitle() const{
      return title;
    }

int Event::getCode() const {
  return code;
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
void Event::display() const{
      cout << "title = " << title << endl;
      cout << "code = " << code << endl;
    }