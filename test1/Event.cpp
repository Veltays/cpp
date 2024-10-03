#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Event.h"


Event::Event()                       // Constructeur d'initilisation
    {
      cout << "Initialisation" << endl;
      title = new char[100];
      strcpy(title,"cinema");
      code = 2;
    };

Event::Event(int c, const char* t)   // constructeur par défaut
    {
      cout << "Constructeur par défaut"<< endl;
      title = new char[100];
      setCode(c);
      setTitle(t);
    };

Event::~Event(){                //destructeur
      cout << " DESTRUCTEUR " << endl;
      delete(title);
    };

  
Event::Event (const Event& x)  //constructeur de copie
    {
      cout <<"Constructeur de copie" << endl;
      title = new char[100];
      strcpy(title,x.title);
      code = x.code;
      
    };

char* Event::getTitle(){
      return title;
    };
int Event::getCode(){
  return code;
  };

void Event::setTitle(const char* t)
    {
      if(strlen(t) == 0)
        return;
      strcpy(title,t);
    }


void Event::setCode(int c)
    {
      if(c < 0)
        return;
      code = c;
    }
void Event::display(){
      cout << "title = " << title << endl;
      cout << "code = " << code << endl;
    }