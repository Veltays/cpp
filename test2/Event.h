#ifndef EVENT_H
#define EVENT_H

class Event
{
  private:
    int code;
    char* title;

  public:
    Event(); // Constructeur d'initilisation

    Event(int c, const char* t);    // constructeur par défaut

    Event (const Event& x);    //constructeur de copie

    void display() const;

    void setCode(int c);
    void setTitle(const char* t);

    int getCode() const;
    const char* getTitle() const;

  
    ~Event();         //destructeur
};
#endif