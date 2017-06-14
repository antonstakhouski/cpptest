#ifndef PERSON_H
#define PERSON_H

#include <string>

#define id_size 8

using namespace std;

class Person
{
public:
    Person();
    enum Sex {FEMALE = 0, MALE};
    explicit Person(string _name, enum Sex _sex, int _age);
    Person(const Person& copy);
    ~Person();

    virtual void setName(string _name) = 0;
    void show();

protected:
    string name;
    enum Sex sex;
    unsigned short age;
    char id[id_size + 1];

};

#endif // PERSON_H
