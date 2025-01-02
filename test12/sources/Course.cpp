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

int Course::getProfessorId() const
{
    return professorId;
}
int Course::getClassroomId() const
{
    return classroomId;
}
set<int> Course::getGroupsId() const
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

bool Course::operator==(const Course &other) const
{
    return this->getCode() == other.getCode();
}

ostream &operator<<(ostream &s, const Course &x)
{

    s << "<Course>" << endl;
    s << static_cast<const Event &>(x); //casting explicite de x en event pour ainsi appelé son opérateur <<

    s << "<professorId>" << endl;
    s << x.getProfessorId() << endl;
    s << "</professorId>" << endl;
    s << "<classroomId>" << endl;
    s << x.getClassroomId() << endl;
    s << "</classroomId>" << endl;
    set<int> test = x.getGroupsId();

    for (auto it = test.cbegin(); it != test.cend(); it++)
    {
        s << "<groupsIds>" << endl;
        cout << "voici votre *it lire" << *it << endl;
        s << *it << endl;
        s << "</groupsIds>" << endl;
        if (next(it) == test.cend())
            break;
    }
    cout << "on sort avant d'avoir fini" << endl;
    s << "</Course>";
    return s;
}

istream &operator>>(istream &s, Course &x)
{
    string line;
    bool ok = true;

    getline(s, line); // <Course>

    s >> static_cast<Event &>(x); //<variable event>

    getline(s, line); // <professorId>

    getline(s, line);

    x.setProfessorId(stoi(line)); // Lire l'ID du professeur

    getline(s, line); // </professorId>

    getline(s, line);

    getline(s, line);

    x.setClassroomId(stoi(line));

    getline(s, line);

    set<int> Envoyer;

    while (ok)
    {

        getline(s, line); // <GroupId> ou classroom

        if (line == "</Course>")
            ok = false;
        else
        {

            getline(s, line); // <var>

            Envoyer.insert(stoi(line)); // Lire l'ID du Group)

            getline(s, line);
        }
    }
    x.setGroupsId(Envoyer); // Lire l'ID du Group
    cout << "cc";
    return s;
}
