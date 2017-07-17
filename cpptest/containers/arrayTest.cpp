#include "arrayTest.h"

ArrayTest::ArrayTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        arr[i] = rand();
    }
}

ArrayTest::~ArrayTest()
{

}

void ArrayTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << arr[0] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void ArrayTest::searchMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        index = rand() % N;
        if(index != 0 && index != N - 1)
            cout << arr[index] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchMidTest = time_spent;
}

void ArrayTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << arr[N - 1] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchTailTest = time_spent;
}
