#include "Classroom.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

Classroom::Classroom() : Schedulable()
{
    setName("----");
    setSeatingCapacity(0);
};

Classroom::Classroom(int id, string name, int place):Schedulable(id)
{
    setName(name);
    setSeatingCapacity(place);
};

void Classroom::setSeatingCapacity(int x)
{
    if (x < 0)
        return;
    seatingCapacity = x;
    
}
void Classroom::setName(string name)
{
    if (name.empty())
        return;
    this->name = name;
    
}

int Classroom::getSeatingCapacity() const{
    return this->seatingCapacity;
}
string Classroom::getName() const{
    return this->name;
}

ostream& operator<<(ostream& s,const Classroom& x)
{
    return s << x.toString();
}

string Classroom::toString() const {
    return this->name + "(" + to_string(this->seatingCapacity) + ")";

}
string Classroom::tuple() const {
     return to_string(id) + ";" + this->name + "(" +to_string(this->seatingCapacity) + ")";
    
}