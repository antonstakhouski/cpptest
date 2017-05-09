#include "contact.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

Contact::Contact(){
    char name[16] = "Enter name here";
    char num[21] = "Enter number here";
    this->name = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(this->name, name);

    char* tmp;
    tmp = (char*)malloc(sizeof(char) * strlen(num));
    strcpy(tmp, num);
    this->numbers = (char**)malloc(sizeof(char*));
    numbers[0] = tmp;
    this->size = 1;
}

Contact::Contact(const char* name, const char* num)
{
    this->name = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(this->name, name);

    char* tmp;
    tmp = (char*)malloc(sizeof(char) * strlen(num));
    strcpy(tmp, num);
    this->numbers = (char**)malloc(sizeof(char*));
    numbers[0] = tmp;
    this->size = 1;
}

Contact::Contact(const char* name, const char** nums, size_t size)
{
    this->name = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(this->name, name);

    char* tmp;
    this->size = size;
    this->numbers = (char**)malloc(sizeof(char*) * size);

    for(size_t i = 0; i < size; i++){
        tmp = (char*)malloc(sizeof(char) * strlen(nums[i]));
        strcpy(tmp, nums[i]);
        numbers[i] = tmp;
    }
}

void Contact::show(){
    cout << "Name: " << name << endl;
    cout << "Numbers:" << endl;
    for(size_t i = 0; i < size; i++){
        cout << "   " << i + 1 << ". " << this->numbers[i] << endl;
    }
}

void Contact::clean(){
    free(this->name);
    for(size_t i = 0; i < size; i++){
        free(this->numbers[i]);
    }
    free(this->numbers);
    this->size = 0;
}

Contact::Contact(const Contact& copy){
    this->clean();
    this->name = (char*)malloc(sizeof(char) * strlen(copy.name));
    strcpy(this->name, copy.name);

    char* tmp;
    this->size = copy.size;
    this->numbers = (char**)malloc(sizeof(char*) * copy.size);

    for(size_t i = 0; i < copy.size; i++){
        tmp = (char*)malloc(sizeof(char) * strlen(copy.numbers[i]));
        strcpy(tmp, copy.numbers[i]);
        numbers[i] = tmp;
    }
}

void Contact::addNumber(const char* num){
    this->size++;
    this->numbers = (char**)realloc(this->numbers, this->size);

    char* tmp;
    tmp = (char*)malloc(sizeof(char) * strlen(num));
    strcpy(tmp, num);
    numbers[this->size - 1] = tmp;
}

void Contact::addNumber(const char** num, size_t size){
    this->size += size;
    this->numbers = (char**)realloc(this->numbers, this->size);

    char* tmp;
    for(size_t i = this->size - size, j = 0; i < this->size; i++, j++){
        tmp = (char*)malloc(sizeof(char) * strlen(num[j]));
        strcpy(tmp, num[j]);
        this->numbers[i] = tmp;
    }
}
