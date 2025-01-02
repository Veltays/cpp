#ifndef GROUP_H
#define GROUP_H
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include "Schedulable.h"

using namespace std;

class Group : public Schedulable
{
    friend ostream &operator<<(ostream &, const Group &);
    friend istream &operator>>(istream &, Group &);

private:
    string name;

public:
    Group();
    Group(int, string);
    Group(const Group &) = default;
    ~Group() = default;

    string toString() const override;
    string tuple() const override;

    void setName(string);
    string getName() const;
    bool operator<(const Group &c) const;
};

#endif
