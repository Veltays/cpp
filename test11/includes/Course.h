#ifndef COURSE_H
#define COURSE_H

#include <set>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>

#include "Event.h"

using namespace planning;
class Course : public Event
{

private:
    int professorId;
    int classroomId;
    set<int> groupsIds;

public:
    Course();
    Course(int code, const char *title, int profId, int classId, const set<int> &groupsId);
    Course(const Course &x) = default;
    ~Course() = default;

    void setProfessorId(int);
    void setClassroomId(int);
    void setGroupsId(const set<int> &groupsId);

    int getProfessorId() const;
    int getClassroomId() const;
    set<int> getGroupsId() const;

    bool operator<(const Course &) const;

    void addGroupId(int id);
    bool isGroupIdPresent(int id);
};

#endif