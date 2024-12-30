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
    classrooms.insert(Classroom(Schedulable::currentId,name,seatingCapacity));
    return 1;
}
void Timetable::displayClassrooms() const
{
}
Classroom Timetable::findClassroomByIndex(int index) const
{
}
Classroom Timetable::findClassroomById(int id) const
{
}
void Timetable::deleteClassroomByIndex(int index)
{
}
void Timetable::deleteClassroomById(int id)
{
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