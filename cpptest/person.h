#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person();
    explicit Person(/*string _lastName, string _firstName, string _middleName,*/ string _id);
    Person(const Person& copy);
    ~Person();

    virtual void addName() = 0;
    virtual void addSex() = 0;
    virtual void addAge() = 0;
    void show();

private:
    string firstName = 0;
    string middleName = 0;
    string lastName = 0;
    string id;

};

#endif // PERSON_H
