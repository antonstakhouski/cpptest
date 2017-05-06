#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <vector>

using namespace std;

class Contact
{
    string name;
    vector<string> numbers;
public:
    Contact(const char* name, const char* num);
    Contact(const char* name, const vector<string> nums);
    void show();
};

#endif // CONTACT_H
