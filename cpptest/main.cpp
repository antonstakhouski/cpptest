#include "mainwindow.h"
#include <QApplication>
#include "contact.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Contact vasya("Vasya", "+375291112233");
    vector<string> nums = {"+3754422233444", "+3752988877444"};

    Contact ivan("Ivan", nums);
    vasya.show();
    ivan.show();
    return 0;
    /**
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();**/
}
