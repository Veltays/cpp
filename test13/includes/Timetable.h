#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <set>
#include <list>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

#include <algorithm>

#include "Classroom.h"
#include "Professor.h"
#include "Group.h"
#include "Course.h"

#include "Schedulable.h"
#include "TimingException.h"
#include "XmlFileSerializer.hpp"
#include "XmlFileSerializerException.h"


using namespace std;
using namespace planning;

class Timetable
{
private:
    set<Classroom> classrooms;
    set<Professor> professors;
    set<Group> groups;
    list<Course> courses;
    Timetable();

    Timetable(const Timetable &x) = delete; //constructeur de copie
    const Timetable& operator=(const Timetable&) = delete;
    static Timetable instance;

public:

    ~Timetable();

    int addClassroom(const Classroom&);
    int addProfessor(const Professor&);
    int addGroup(const Group&);
    
    int addClassroom(const string &name, int seatingCapacity);
    void displayClassrooms() const;
    Classroom findClassroomByIndex(int index) const;
    Classroom findClassroomById(int id) const;
    void deleteClassroomByIndex(int index);
    int deleteClassroomById(int id);



    int addProfessor(const string &lastName, const string &firstName);
    void displayProfessors() const;
    Professor findProfessorByIndex(int index) const;
    Professor findProfessorById(int id) const;
    void deleteProfessorByIndex(int index);
    int deleteProfessorById(int id);


    int addGroup(const string &name);
    void displayGroups() const;
    Group findGroupByIndex(int index) const;
    Group findGroupById(int id) const;
    void deleteGroupByIndex(int index);
    int deleteGroupById(int id);


    bool isProfessorAvailable(int id, const Timing& timing);
    bool isGroupAvailable(int id, const Timing& timing);
    bool isClassroomAvailable(int id, const Timing& timing);
    void schedule(Course& c, const Timing& t);

    
    static Timetable& getInstance();


    string getProfessorTupleByIndex(int);
    string getGroupTupleByIndex(int);
    string getClassroomTupleByIndex(int);
    string getCourseTupleByIndex(int index);


    string tuple(const Course & c);


    int vider();
    int save(const string& timetableName);
    int load(const string& timetableName);



    Course findCourseByIndex(int index);
    Course findCourseByCode(int code) const;
    int deleteCourseByCode(int code);



    void importProfessorsFromCsv(const string& filename);
    void importGroupsFromCsv(const string& filename);
    void importClassroomsFromCsv(const string& filename);


    void exportProfessorTimetable(int id);
    void exportGroupTimetable(int id);
    void exportClassroomTimetable(int id);

    list<Course> selectionner(bool dayCheck,string daychecked, bool groupCheck,int groupChecked,bool profCheck,int profChecked, bool classCheck,int classChecked);


};


#endif