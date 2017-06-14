#include "driverlicence.h"
#include <iostream>

DriverLicence::DriverLicence(): Person(), category(0)
{

}

DriverLicence::DriverLicence(string _name, enum Person::Sex _sex, int _age, char _category):
    Person(_name, _sex, _age),
    category(_category)
{

}

DriverLicence::DriverLicence(const DriverLicence &copy):
    Person(copy),
    category(copy.category)
{

}

void DriverLicence::setName(string _name)
{
    name = "driver " +  _name;
}

void DriverLicence::show()
{
    Person::show();
    cout << "Category: " << category << endl;
}
