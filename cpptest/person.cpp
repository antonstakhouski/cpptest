#include "person.h"
#include <iostream>
#include <ctime>
#include <cstring>

Person::Person():
    name(""),
    sex(Sex(0)),
    age(0),
    id("")
{

}

Person::~Person()
{

}

Person::Person(string _name, enum Sex _sex, int _age):
    name(_name),
    sex(_sex),
    age(_age)
{
    srand(time(0));
    id[id_size] = '\0';
    for (int i = 0; i < id_size; i++)
        id[i] = rand() % (128 - 33) + 32;
}

Person::Person(const Person &copy):
    name(copy.name),
    sex(copy.sex),
    age(copy.age)
{
    strcpy(id, copy.id);
}

void Person::show()
{
   cout << "Id: " << id << endl;
   cout << "Name: " << name << endl;
   cout << "Sex: ";
   if (sex == MALE)
       cout << "MALE" << endl;
   if (sex == FEMALE)
       cout << "FEMALE" << endl;
   cout << "Age: " << age << endl;
}
