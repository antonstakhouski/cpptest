#include "person.h"
#include <iostream>

Person::Person():
//    firstName(""),
//    middleName(""),
//    lastName(""),
    id("")
{

}

Person::~Person()
{
}

Person::Person(/* string _lastName, string _firstName, string _middleName, */string _id):
//    firstName(_firstName),
//    middleName(_middleName),
//    lastName(_lastName),
    id(_id) {}

Person::Person(const Person &copy):
//    firstName(copy.firstName),
//    middleName(copy.middleName),
//    lastName(copy.lastName),
    id(copy.id)
{
}

void Person::show()
{
//    cout << "Id:" << id << endl;
//    cout << "Last name: " << lastName << endl;
//    cout << "First name: " << firstName << endl;
//    cout << "Middle name: " << middleName << endl;
}
