#ifndef QUEUETEST_H
#define QUEUETEST_H

#include <queue>
#include <iostream>

#include "containerTest.h"

using namespace std;

class QueueTest : public ContainerTest
{
    queue<int> q;
public:
    explicit QueueTest();
    ~QueueTest();
protected:
    void searchHeadTest();
    void searchTailTest();

    void insTailTest();

    void delHeadTest();
};

#endif // QUEUETEST_H

