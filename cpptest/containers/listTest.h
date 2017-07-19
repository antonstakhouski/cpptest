#ifndef LISTTEST_H
#define LISTTEST_H

#include <list>
#include <iostream>

#include "containerTest.h"

using namespace std;

class ListTest : public ContainerTest
{
    list<int> lst;
public:
    explicit ListTest();
    ~ListTest();
protected:
    void searchHeadTest();
    void searchMidTest();
    void searchTailTest();

    void insHeadTest();
    void insMidTest();
    void insTailTest();

    void delHeadTest();
    void delMidTest();
    void delTailTest();
};

#endif // LISTTEST_H

