#include "listTest.h"

ListTest::ListTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        lst.push_front(rand());
    }
}

ListTest::~ListTest()
{

}

void ListTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << *(lst.cbegin()) << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void ListTest::searchMidTest()
{
    size_t index;
    clock_t begin = clock();
    auto iterator = lst.begin();
    for(int i = 0; i < N; i++){
        iterator = lst.begin();
        index = rand() % N;
        if(index != 0){
            for(size_t j = 0; j < index; j++)
                iterator++;
            cout << *(iterator) << endl;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchMidTest = time_spent;
}

void ListTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        auto last = lst.cend();
        for(auto it = lst.cbegin(); it != lst.cend(); it++)
            last = it;
        cout << *(last) << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchTailTest = time_spent;
}

void ListTest::insHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        lst.push_front(rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insHeadTest = time_spent;
}

void ListTest::insMidTest()
{
    clock_t begin = clock();
    int index;
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        auto it = lst.begin();
        index = rand() % (2 * N);
        for(int i = 0; i < index; i++, it++);
        srand(time(NULL));
        lst.insert(it, rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insMidTest = time_spent;
}

void ListTest::insTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        auto it = lst.begin();
        for(auto i = lst.begin(); i != lst.end(); i++)
            it = i;
        lst.insert(it, rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void ListTest::delHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++)
        lst.erase(lst.begin());
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insHeadTest = time_spent;
}

void ListTest::delMidTest()
{
    clock_t begin = clock();
    int index;
    int count = 3 * N - 1;
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        auto it = lst.begin();
        index = rand() % (count--);
        for(int i = 0; i < index; i++, it++);
        lst.erase(it);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insMidTest = time_spent;
}

void ListTest::delTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        auto it = lst.begin();
        for(auto i = lst.begin(); i != lst.end(); i++){
            it = i;
        }
        lst.erase(it);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

