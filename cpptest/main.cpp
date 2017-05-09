#include "mainwindow.h"
#include <QApplication>
#include "contact.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    Contact vasya("Vasya", "+375291112233");
    vasya.show();

    char** nums;
    size_t size = 2;
    nums = (char**)malloc(sizeof(char*) * size);
    nums[0] = (char*)malloc(sizeof(char) * strlen("hello"));
    strcpy(nums[0], "hello");
    nums[1] = (char*)malloc(sizeof(char) * strlen("world"));
    strcpy(nums[1], "world");
    Contact ivan("Ivan", (const char**)nums, size);
    ivan.show();

    Contact noname;
    noname.show();
    noname = vasya;
    noname.addNumber("666");
    noname.addNumber((const char**)nums, size);
    noname.show();

    //contacts.push_back(vasya);
    //vector<string> nums = {"+3754422233444", "+3752988877444"};

  /**  Contact ivan("Ivan", nums);
    contacts.push_back(ivan);
    vasya.show();
    ivan.show();**/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
