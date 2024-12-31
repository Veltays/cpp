#include "Timetable.h"
#include "Schedulable.h"

Timetable Timetable::instance;

Timetable::Timetable()
{
}
Timetable::~Timetable()
{
}

//? ------------Les classroom ----------------
int Timetable::addClassroom(const string &name, int seatingCapacity)
{
    auto result = classrooms.insert(Classroom(Schedulable::currentId, name, seatingCapacity));


    if (result.second)  // result.second est true si l'insertion a réussi
    {
        cout << "Le groupe a été ajouté avec succès." << endl;
        Schedulable::currentId++;
        return 1;
    }
    else
    {
        cout << "Le groupe existe déjà." << endl;
        return 0;
    }
}
void Timetable::displayClassrooms() const
{
    int index = 0;
    for (set<Classroom>::const_iterator it = classrooms.cbegin(); it != classrooms.cend(); it++)
    {
        cout << "-->" << index << " | "
             << "Id"
             << "[" << it->getId() << "]"
             << "  |  " << it->toString() << it->getId() << endl;
        index++;
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

    if (it != classrooms.cend())
        return *it;
    else
    {
        cout << "Index hors limites" << endl;
        return Classroom(); // Retourne un objet Classroom vide ou un autre objet par défaut
    }
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
    auto result = professors.insert(Professor(Schedulable::currentId, lastName, firstName));
    if (result.second)  // result.second est true si l'insertion a réussi
    {
        cout << "Le groupe a été ajouté avec succès." << endl;
        Schedulable::currentId++;
        return 1;
    }
    else
    {
        cout << "Le groupe existe déjà." << endl;
        return 0;
    }
}
void Timetable::displayProfessors() const
{
    int index = 0;
    for (set<Professor>::const_iterator it = professors.cbegin(); it != professors.cend(); it++)
    {
        cout << "-->" << index << " | "
             << "Id"
             << "[" << it->getId() << "]"
             << "  |  " << it->toString() << it->getId() << endl;
        index++;
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

    if (it != professors.cend())
        return *it;
    else
    {
        cout << "Index hors limites" << endl;
        return Professor(); // Retourne un objet Professorr vide ou un autre objet par défaut
    }
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
    auto result = groups.insert(Group(Schedulable::currentId, name));

    if (result.second)  // result.second est true si l'insertion a réussi
    {
        cout << "Le groupe a été ajouté avec succès." << endl;
        Schedulable::currentId++;
        return 1;
    }
    else
    {
        cout << "Le groupe existe déjà." << endl;
        return 0;
    }
}
void Timetable::displayGroups() const
{
    int index = 0;
    for (set<Group>::const_iterator it = groups.cbegin(); it != groups.cend(); it++)
    {
        cout << "-->" << index << " | "
             << "Id"
             << "[" << it->getId() << "]"
             << "  |  " << it->toString() << it->getId() << endl;
        index++;
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

    if (it != groups.cend())
        return *it;
    else
    {
        cout << "Index hors limites" << endl;
        return Group(); // Retourne un objet Group vide ou un autre objet par défaut
    }
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

Timetable &Timetable::getInstance()
{
    return instance;
}




//Fonction get 


string Timetable::getProfessorTupleByIndex(int index)
{
    Professor t = findProfessorByIndex(index);
    if(t.getFirstName().empty() && t.getLastName().empty())
        return "";

    return t.tuple();
}


string Timetable::getGroupTupleByIndex(int index)
{

    Group t = findGroupByIndex(index);
    if(t.getName().empty())
        return "";

    return t.tuple();
}


string Timetable::getClassroomTupleByIndex(int index)
{

    Classroom t = findClassroomByIndex(index);
    if(t.getName().empty() && t.getSeatingCapacity() == 0)
        return "";

    return t.tuple();
}


