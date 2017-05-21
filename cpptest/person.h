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

    string getFirstName() const;
    void setFirstName(const string &value);

    string getMiddleName() const;
    void setMiddleName(const string &value);

    string getLastName() const;
    void setLastName(const string &value);

    string getId() const;
    void setId(const string &value);

private:
    string firstName;
    string middleName;
    string lastName;
    string id;

};

#endif // PERSON_H
