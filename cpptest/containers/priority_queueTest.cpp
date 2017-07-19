#include "priority_queueTest.h"

PriorityQueueTest::PriorityQueueTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        q.push(rand());
    }
}

PriorityQueueTest::~PriorityQueueTest()
{

}

void PriorityQueueTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << q.top() << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void PriorityQueueTest::insTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        q.push(rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void PriorityQueueTest::delHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        q.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delTailTest = time_spent;
}

