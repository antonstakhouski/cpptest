#include "vectorTest.h"

VectorTest::VectorTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        vec.push_back(rand());
    }
}

VectorTest::~VectorTest()
{

}

void VectorTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << vec[0] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void VectorTest::searchMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        index = rand() % N;
        if(index != 0 && index != N - 1)
            cout << vec[index] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchMidTest = time_spent;
}

void VectorTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << vec[N - 1] << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchTailTest = time_spent;
}

void VectorTest::insHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        vec.insert(vec.begin(), rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insHeadTest = time_spent;
}

void VectorTest::insMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % vec.size();
        if(index != 0 && (unsigned long)index != vec.size() - 1){
            srand(time(NULL));
            vec.insert(vec.begin() + index, rand());
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insMidTest = time_spent;
}

void VectorTest::insTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        vec.push_back(rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void VectorTest::delHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++)
        vec.erase(vec.begin());
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delHeadTest = time_spent;
}

void VectorTest::delMidTest()
{
    int index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % vec.size();
        if(index != 0 && (unsigned long)index != vec.size() - 1)
            vec.erase(vec.begin() + index);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delMidTest = time_spent;
}

void VectorTest::delTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        vec.pop_back();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delTailTest = time_spent;
}

