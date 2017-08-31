#include "queueTest.h"

QueueTest::QueueTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        q.push(rand());
    }
}

QueueTest::~QueueTest()
{

}

void QueueTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << q.front() << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void QueueTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << q.back() << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchTailTest = time_spent;
}

void QueueTest::insTailTest()
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

void QueueTest::delHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        q.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delTailTest = time_spent;
}
