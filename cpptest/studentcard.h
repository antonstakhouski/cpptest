#ifndef STUDENTCARD_H
#define STUDENTCARD_H

#include "person.h"
#include <string>

using namespace std;

class StudentCard : public Person
{
public:
    StudentCard();
    StudentCard(string _name, enum Person::Sex _sex, int _age, string _faculty);
    StudentCard(const StudentCard& copy);
    void setName(string _name);
    void show();

private:
    string faculty;
};

#endif // STUDENTCARD_H
