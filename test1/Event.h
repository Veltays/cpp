class Event
{
  private:
    int code;
    char* title;

  public:
    Event(); // Constructeur d'initilisation

    Event(int c, const char* t);    // constructeur par défaut

    Event (const Event& x);    //constructeur de copie

    void display();

    void setCode(int c);
    void setTitle(const char* t);

    int getCode();
    char* getTitle();

  
    ~Event();         //destructeur
};