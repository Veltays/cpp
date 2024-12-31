#include "Timetable.h"
#include "Schedulable.h"
#include "Schedulable.h"

Timetable::Timetable()
{
}
Timetable::~Timetable()
{
}

//? ------------Les classroom ----------------
int Timetable::addClassroom(const string &name, int seatingCapacity)
{
    classrooms.insert(Classroom(Schedulable::currentId, name, seatingCapacity));
    cout << "l'id" << Schedulable::currentId << endl;
    Schedulable::currentId++;
    return 1;
}
void Timetable::displayClassrooms() const
{
    for (set<Classroom>::const_iterator it = classrooms.cbegin(); it != classrooms.cend(); it++)
    {                                             //cbegin = debutde la liste classroom (constant);
        cout << "--> " << it->toString()  << "  d'ID :  " << it->getId() << endl; //cend = fin de la liste classroom (constant)
    }
}

Classroom Timetable::findClassroomByIndex(int index) const
{
    auto it = classrooms.cbegin();
    int i = 0;

    while (it != classrooms.cend() && i < index )
    {
        it++;
        i++;
    }

    return *it;
}

Classroom Timetable::findClassroomById(int id) const
{
    auto it = classrooms.cbegin();

    while (it != classrooms.cend() && it->getId() != id)
    {
        it++;
    }

    if (it != classrooms.cend())
        return *it;

    cout << "Classroom pas trouvé" << endl;
    return Classroom();

}

void Timetable::deleteClassroomByIndex(int index)
{
    auto it = classrooms.cbegin();
    int i = 0;

    while (i < index)
    {
        it++;
        i++;
    }
    if (it != classrooms.end())
        classrooms.erase(it);
    else
        cout << "index inatteignable" << endl;
}
void Timetable::deleteClassroomById(int id)
{

    Classroom Deleted = findClassroomById(id);

    auto it = classrooms.find(Deleted);

    if (it != classrooms.cend())
        classrooms.erase(it);
    else
        cout << "Classroom pas trouvé pour suppression" << endl;
}




//? ------------Les Professeurs ----------------
int Timetable::addProfessor(const string &lastName, const string &firstName)
{
}
void Timetable::displayProfessors() const
{
}
Professor Timetable::findProfessorByIndex(int index) const
{
}
Professor Timetable::findProfessorById(int id) const
{
}
void Timetable::deleteProfessorByIndex(int index)
{
}

void Timetable::deleteProfessorById(int id)
{
}

//? ------------Les groupes ----------------
int Timetable::addGroup(const string &name)
{
}
void Timetable::displayGroups() const
{
}
Group Timetable::findGroupByIndex(int index) const
{
}
Group Timetable::findGroupById(int id) const
{
}
void Timetable::deleteGroupByIndex(int index)
{
}
void Timetable::deleteGroupById(int id)
{
}