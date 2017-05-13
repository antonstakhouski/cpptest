#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Contact
{
public:
    explicit Contact();
    ~Contact();
    Contact(const char* name, const char* num);
    Contact(const char* name, const char** nums, size_t size);
    Contact(const Contact& copy);

    char* getName();
    char** getNums();

    void addNumber(const char* num);
    void addNumber(const char** num, size_t size);
    void clean();
    void show();

private:
    char* name;
    char** numbers;
    size_t size;
};

#endif // CONTACT_H
