#include "forward_listTest.h"

ForwardListTest::ForwardListTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        lst.push_front(rand());
    }
}

ForwardListTest::~ForwardListTest()
{

}

void ForwardListTest::searchHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << *(lst.cbegin()) << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchHeadTest = time_spent;
}

void ForwardListTest::searchMidTest()
{
    int item;
    size_t index;
    clock_t begin = clock();
    auto iterator = lst.begin();
    for(int i = 0; i < N; i++){
        iterator = lst.begin();
        index = rand() % N;
        if(index != 0){
            for(size_t j = 0; j < index; j++)
                iterator++;
            item = *(iterator);
            cout << item << endl;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchMidTest = time_spent;
}

void ForwardListTest::searchTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        cout << *(lst.cend()) << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.searchTailTest = time_spent;
}

void ForwardListTest::insHeadTest()
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

void ForwardListTest::insMidTest()
{
    clock_t begin = clock();
    int index;
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        auto it = lst.begin();
        index = rand();
        srand(time(NULL));
        for(int i = 0; i < index; i++, it++);
        lst.insert_after(it, rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insMidTest = time_spent;
}

void ForwardListTest::insTailTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        lst.insert_after(lst.cend(), rand());
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insTailTest = time_spent;
}

void ForwardListTest::delHeadTest()
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++)
        lst.erase_after(lst.begin()++);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.insHeadTest = time_spent;
}
//
// void ForwardListTest::insMidTest()
// {
//     clock_t begin = clock();
//     int index;
//     for(int i = 0; i < N; i++){
//         srand(time(NULL));
//         auto it = lst.begin();
//         index = rand();
//         srand(time(NULL));
//         for(int i = 0; i < index; i++, it++);
//         lst.insert_after(it, rand());
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     res.insMidTest = time_spent;
// }
//
// void ForwardListTest::insTailTest()
// {
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         srand(time(NULL));
//         lst.insert_after(lst.cend(), rand());
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     res.insTailTest = time_spent;
// }
//
