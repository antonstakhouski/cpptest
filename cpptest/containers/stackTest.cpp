#include "stackTest.h"

StackTest::StackTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        s.push(rand());
    }
}

StackTest::~StackTest()
{

}

void StackTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << s.top() << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void StackTest::insTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        s.push(rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void StackTest::delTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        s.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

