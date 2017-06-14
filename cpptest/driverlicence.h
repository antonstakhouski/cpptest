#ifndef DRIVERLICENCE_H
#define DRIVERLICENCE_H

#include "person.h"
#include <string>

using namespace std;

class DriverLicence : public Person
{
public:
    DriverLicence();
    DriverLicence(string _name, enum Person::Sex _sex, int _age, char _category);
    DriverLicence(const DriverLicence& copy);
    void setName(string _name);
    void show();

private:
    char category;
};

#endif // DRIVERLICENCE_H
