#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
#include "Group.h"

Group::Group():Schedulable()
{
    setName("");
}
Group::Group(int id, string name):Schedulable(id)
{
    setName(name);
}

void Group::setName(string name)
{
    if(name.empty())
        return;
    this->name = name;
}

string Group::getName() const
 {
     return this->name;
 }


string Group::toString() const
{
    return name;
}

string Group::tuple() const
{
    return to_string(id) + ";" + name;
}

 bool Group::operator<(const Group& c) const
 {
     return this->getName() < c.getName();
 }
 
 ostream& operator<<(ostream &s,const Group &x )
{
    s << "<Group>" << endl;
    s << "<id>" << endl;
    s << x.id << endl;
    s << "</id>" << endl;
    s << "<name>" << endl;
    s << x.name << endl;
    s << "</name>" << endl;
    s << "</Group>";
    return s;
}

istream& operator>>(istream& s,Group& x){
    string line;
    getline(s, line); // <Group>
    getline(s, line); //   <id>
    getline(s, line); //     <variable>
    x.setId(stoi(line));
    getline(s, line); //   </id>
    getline(s, line); //   <name>
    getline(s, line); //    <variable>
    x.setName(line);
    getline(s, line); //   </name>
    getline(s, line); // </Group>

}