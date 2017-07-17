#include "dequeTest.h"

DequeTest::DequeTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        d.push_back(rand());
    }
}

DequeTest::~DequeTest()
{

}

void DequeTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << d[0] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void DequeTest::searchMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        index = rand() % N;
        if(index != 0 && index != N - 1)
            cout << d[index] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchMidTest = time_spent;
}

void DequeTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << d[N - 1] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchTailTest = time_spent;
}

void DequeTest::insHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        d.insert(d.begin(), rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insHeadTest = time_spent;
}

void DequeTest::insMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % d.size();
        if(index != 0 && (unsigned long)index != d.size() - 1){
            srand(time(NULL));
            d.insert(d.begin() + index, rand());
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insMidTest = time_spent;
}

void DequeTest::insTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        d.push_back(rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void DequeTest::delHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++)
        d.erase(d.begin());
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delHeadTest = time_spent;
}

void DequeTest::delMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % d.size();
        if(index != 0 && (unsigned long)index != d.size() - 1)
            d.erase(d.begin() + index);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delMidTest = time_spent;
}

void DequeTest::delTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        d.pop_back();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delTailTest = time_spent;
}

