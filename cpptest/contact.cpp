#include "contact.h"
#include <iostream>

Contact::Contact(const char* name, const char* num)
{
    this->name = name;
    this->numbers.push_back(num);
}

Contact::Contact(const char* name, const vector<string> nums)
{
    this->name = name;
    this->numbers = nums;
}

void Contact::show(){
    cout << "Name: " << name << endl;
    cout << "Numbers:" << endl;
    for(size_t i = 0; i < numbers.size(); i++){
        cout << "   " << i + 1 << ". " << numbers[i] << endl;
    }
}
