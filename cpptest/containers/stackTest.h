#ifndef STACKTEST_H
#define STACKTEST_H

#include <stack>
#include <iostream>

#include "containerTest.h"

using namespace std;

class StackTest : public ContainerTest
{
    stack<int> s;
public:
    explicit StackTest();
    ~StackTest();
protected:
    void searchTailTest();
    void insTailTest();
    void delTailTest();
};

#endif // STACKTEST_H

