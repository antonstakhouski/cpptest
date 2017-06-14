#include "studentcard.h"
#include <iostream>

StudentCard::StudentCard(): Person(), faculty("")
{

}

StudentCard::StudentCard(string _name, enum Person::Sex _sex, int _age, string _faculty):
    Person(_name, _sex, _age),
    faculty(_faculty)
{

}

StudentCard::StudentCard(const StudentCard &copy):
    Person(copy),
    faculty(copy.faculty)
{

}

void StudentCard::setName(string _name)
{
    name = "student " +  _name;
}

void StudentCard::show()
{
    Person::show();
    cout << "Faculty: " << faculty << endl;
}
