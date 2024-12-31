#include "Timetable.h"
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
    {                                                                            //cbegin = debutde la liste classroom (constant);
        cout << "--> " << it->toString() << "  d'ID :  " << it->getId() << endl; //cend = fin de la liste classroom (constant)
    }
}

Classroom Timetable::findClassroomByIndex(int index) const
{
    auto it = classrooms.cbegin();
    int i = 0;

    while (it != classrooms.cend() && i < index)
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
    professors.insert(Professor(Schedulable::currentId, lastName, firstName));
    cout << "l'id" << Schedulable::currentId << endl;
    Schedulable::currentId++;
    return 1;
}
void Timetable::displayProfessors() const
{
    for (auto it = professors.cbegin(); it != professors.cend(); it++)
    {                                                                            //cbegin = debutde la liste professors (constant);
        cout << "--> " << it->toString() << "  d'ID :  " << it->getId() << endl; //cend = fin de la liste professors (constant)
    }
}
Professor Timetable::findProfessorByIndex(int index) const
{
    auto it = professors.cbegin();
    int i = 0;

    while (it != professors.cend() && i < index)
    {
        it++;
        i++;
    }

    return *it;
}
Professor Timetable::findProfessorById(int id) const
{
    auto it = professors.cbegin();

    while (it != professors.cend() && it->getId() != id)
    {
        it++;
    }

    if (it != professors.cend())
        return *it;

    cout << "professors pas trouvé" << endl;
    return Professor();
}
void Timetable::deleteProfessorByIndex(int index)
{
    auto it = professors.cbegin();
    int i = 0;

    while (i < index)
    {
        it++;
        i++;
    }
    if (it != professors.end())
        professors.erase(it);
    else
        cout << "index inatteignable" << endl;
}

void Timetable::deleteProfessorById(int id)
{
        Professor Deleted = findProfessorById(id);

    auto it = professors.find(Deleted);

    if (it != professors.cend())
        professors.erase(it);
    else
        cout << "professors pas trouvé pour suppression" << endl;
}

//? ------------Les groupes ----------------
int Timetable::addGroup(const string &name)
{
    groups.insert(Group(Schedulable::currentId, name));
    cout << "l'id" << Schedulable::currentId << endl;
    Schedulable::currentId++;
    return 1;
}
void Timetable::displayGroups() const
{
    for (auto it = groups.cbegin(); it != groups.cend(); it++)
    {                                                                            //cbegin = debutde la liste groups (constant);
        cout << "--> " << it->toString() << "  d'ID :  " << it->getId() << endl; //cend = fin de la liste groups (constant)
    }
}
Group Timetable::findGroupByIndex(int index) const
{
    auto it = groups.cbegin();
    int i = 0;

    while (it != groups.cend() && i < index)
    {
        it++;
        i++;
    }

    return *it;
}
Group Timetable::findGroupById(int id) const
{
    auto it = groups.cbegin();

    while (it != groups.cend() && it->getId() != id)
    {
        it++;
    }

    if (it != groups.cend())
        return *it;

    cout << "professors pas trouvé" << endl;
    return Group();
}
void Timetable::deleteGroupByIndex(int index)
{
    auto it = groups.cbegin();
    int i = 0;

    while (i < index)
    {
        it++;
        i++;
    }
    if (it != groups.end())
        groups.erase(it);
    else
        cout << "index inatteignable" << endl;

}
void Timetable::deleteGroupById(int id)
{
    Group Deleted = findGroupById(id);

    auto it = groups.find(Deleted);

    if (it != groups.cend())
        groups.erase(it);
    else
        cout << "groups pas trouvé pour suppression" << endl;
}