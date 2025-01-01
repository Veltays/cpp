#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <set>
#include "Classroom.h"
#include "Professor.h"
#include "Group.h"

using namespace std;

class Timetable
{
private:
    set<Classroom> classrooms;
    set<Professor> professors;
    set<Group> groups;
    Timetable();

    Timetable(const Timetable &x) = delete; //constructeur de copie
    const Timetable& operator=(const Timetable&) = delete;
    static Timetable instance;

public:
    ~Timetable();


    
    int addClassroom(const string &name, int seatingCapacity);
    void displayClassrooms() const;
    Classroom findClassroomByIndex(int index) const;
    Classroom findClassroomById(int id) const;
    void deleteClassroomByIndex(int index);
    void deleteClassroomById(int id);



    int addProfessor(const string &lastName, const string &firstName);
    void displayProfessors() const;
    Professor findProfessorByIndex(int index) const;
    Professor findProfessorById(int id) const;
    void deleteProfessorByIndex(int index);
    void deleteProfessorById(int id);


    int addGroup(const string &name);
    void displayGroups() const;
    Group findGroupByIndex(int index) const;
    Group findGroupById(int id) const;
    void deleteGroupByIndex(int index);
    void deleteGroupById(int id);

    static Timetable& getInstance();


    string getProfessorTupleByIndex(int);
    string getGroupTupleByIndex(int);
    string getClassroomTupleByIndex(int);
};


#endif