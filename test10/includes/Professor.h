#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Schedulable.h"

using namespace std;

class Professor : public Schedulable
{
    friend ostream& operator<<(ostream&,const Professor&);
    friend istream& operator>>(istream&,Professor&);
private:
    string lastName;
    string firstName;
public:
    Professor();

    Professor(int,string, string);

    Professor(const Professor &x) = default;

    ~Professor() = default;

    string toString() const override;

    string tuple() const override;


    void setFirstName(string);
    void setLastName(string);


    string getFirstName() const;
    string getLastName() const;

    bool operator<(const Professor& c) const;

    
};

#endif