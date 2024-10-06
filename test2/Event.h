#ifndef EVENT_H
#define EVENT_H
#include "Timing.h"
class Event
{
  private:
    int code;
    char* title;
    Timing* timing;

  public:
    Event(); // Constructeur d'initilisation

    Event(int c, const char* t);    // constructeur par défaut

    Event (const Event& x);    //constructeur de copie

    ~Event();         //destructeur


    //LES SET
    

    void setCode(int c);

    void setTitle(const char* t);
    
    void setTiming(Timing*);



    //LES GET
    

    int getCode() const;

    const char* getTitle() const;

    void getTiming() const;

    void display() const;
  
};
#endif