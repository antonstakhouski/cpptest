#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    explicit Person();
    Person(string _lastName, string _firstName, string _middleName, string _id);
    Person(const Person& copy);
    ~Person();

    void show();

private:
    string firstName;
    string middleName;
    string lastName;
    string id;

};

#endif // PERSON_H
