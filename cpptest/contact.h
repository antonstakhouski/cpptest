#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <vector>

using namespace std;

class Contact
{
    char* name;
    char** numbers;
    size_t size;
public:
    Contact();
    Contact(const char* name, const char* num);
    Contact(const char* name, const char** nums, size_t size);
    Contact(const Contact& copy);

    void addNumber(const char* num);
    void addNumber(const char** num, size_t size);
    void clean();
    void show();
};

#endif // CONTACT_H
