#ifndef PRIORITY_QUEUETEST_H
#define PRIORITY_QUEUETEST_H

#include <queue>
#include <iostream>

#include "containerTest.h"

using namespace std;

class PriorityQueueTest : public ContainerTest
{
    priority_queue<int> q;
public:
    explicit PriorityQueueTest();
    ~PriorityQueueTest();
protected:
    void searchHeadTest();

    void insTailTest();

    void delHeadTest();
};

#endif // PRIORITY_QUEUETEST_H

