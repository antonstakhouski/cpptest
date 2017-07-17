#ifndef DEQUE_H
#define DEQUE_H

#include <deque>
#include <iostream>

#include "containerTest.h"

using namespace std;

class DequeTest : public ContainerTest
{
    deque<int> d;
public:
    explicit DequeTest();
    ~DequeTest();
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

#endif // DEQUE_H

