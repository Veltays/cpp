#include "Professor.h"

Professor::Professor() : Schedulable()
{
    setFirstName("");
    setLastName("");
};

Professor::Professor(int id, string Nom, string Prenom) : Schedulable(id)
{
    setFirstName(Prenom);
    setLastName(Nom);
};

void Professor::setFirstName(string name)
{
    if (name.empty())
        return;
    firstName = name;
}

void Professor::setLastName(string name)
{
    if (name.empty())
        return;
    lastName = name;
}

string Professor::getFirstName() const
{
    return firstName;
}

string Professor::getLastName() const
{
    return lastName;
}

string Professor::toString() const
{
    return lastName +" "+ firstName;
};

string Professor::tuple() const
{
    return to_string(id) + ";" + lastName + ";" + firstName;
};

bool Professor::operator<(const Professor &c) const
{
    return this->getLastName() < c.getLastName();

    // on n'admet pas deux fois le même nom de familles ducoup
}

ostream &operator<<(ostream &s, const Professor &x)
{
    s << "<Professor>" << endl;
    s << "<id>" << endl;
    s << x.id << endl;
    s << "</id>" << endl;
    s << "<firstName>" << endl;
    s << x.firstName << endl;
    s << "</firstName>" << endl;
    s << "<lastName>" << endl;
    s << x.lastName << endl;
    s << "</lastName>" << endl;
    s << "</Professor>";
    return s;
};

istream &operator>>(istream &s, Professor &x)
{
    string line;
    getline(s, line); // <Professor>
    getline(s, line); //   <id>
    getline(s, line); //     <variable>
    x.setId(stoi(line));
    getline(s, line); //   </id>
    getline(s, line); //   <firstName>
    getline(s, line); //    <variable>
    x.setFirstName(line);
    getline(s, line); //   </firstName>

    getline(s, line); //   <lastName>
    getline(s, line); //    <variable>
    x.setLastName(line);
    getline(s, line); //   </lastName>
    getline(s, line); // </Professor>
    return s;
}