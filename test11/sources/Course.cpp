#include "Course.h"
using namespace planning;

Course::Course() : Event()
{
    setProfessorId(0);
    setClassroomId(0);
    groupsIds.clear();
}

Course::Course(int code, const char *title, int profId, int classId, const set<int> &grupId) : Event(code, title)
{
    setProfessorId(profId);
    setClassroomId(classId);
    setGroupsId(grupId);
}
// Course::Course(const Course &x)
// {
// }
// Course::~Course()
// {
// }

void Course::setProfessorId(int id)
{
    if (id < 0)
        return;
    professorId = id;
}
void Course::setClassroomId(int id)
{
    if (id < 0)
        return;
    classroomId = id;
}

void Course::setGroupsId(const set<int> &groupsId)
{
    this->groupsIds = groupsId;
}

int Course::getProfessorId()
{
    return professorId;
}
int Course::getClassroomId()
{
    return classroomId;
}
set<int> Course::getGroupsId()
{
    return groupsIds;
}

bool Course::operator<(const Course &c) const
{
   
    Timing t = this->getTiming();
    Timing ct = c.getTiming();

    // Comparer d'abord les jours
    if (t.dayToInt(t) < ct.dayToInt(ct))
        return true;
    if (t.dayToInt(t) > ct.dayToInt(ct))
        return false;

    // Si les jours sont égaux, comparer les heures de début (start)
    return t.getStart() < ct.getStart();



}

void Course::addGroupId(int id)
{
    getGroupsId().insert(id);
}

bool Course::isGroupIdPresent(int id)
{
    auto Grp = getGroupsId();

    auto it = Grp.find(id);

    if (it != Grp.end())
    {
        cout << "Int trouvé " << *it << endl;
        return true;
    }
    else
    {
        cout << "pas trouvé..." << endl;
        return false;
    }
}
