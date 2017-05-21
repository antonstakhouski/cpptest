#include "person.h"
#include <iostream>

Person::Person():lastName("Ivanov"), firstName("Ivan"), middleName("Ivanovich"), id("000000")
{
}

Person::~Person()
{
}

Person::Person( string _lastName, string _firstName, string _middleName, string _id):
    firstName(_firstName), middleName(_middleName), lastName(_lastName), id(_id){}

Person::Person(const Person &copy): firstName(copy.firstName), middleName(copy.middleName),
    lastName(copy.lastName), id(copy.id)
{
}

void Person::show()
{
    cout << "Id:" << id << endl;
    cout << "Last name: " << lastName << endl;
    cout << "First name: " << firstName << endl;
    cout << "Middle name: " << middleName << endl;
}

string Person::getFirstName() const
{
    return firstName;
}

void Person::setFirstName(const string &value)
{
    firstName = value;
}

string Person::getMiddleName() const
{
    return middleName;
}

void Person::setMiddleName(const string &value)
{
    middleName = value;
}

string Person::getLastName() const
{
    return lastName;
}

void Person::setLastName(const string &value)
{
    lastName = value;
}

string Person::getId() const
{
    return id;
}

void Person::setId(const string &value)
{
    id = value;
}
