#include "unordered_multisetTest.h"

UnorderedMultisetTest::UnorderedMultisetTest() : ContainerTest()
{
   for(int i = 0; i < N; i++){
       srand(time(NULL));
       s.insert(rand());
   }
}

UnorderedMultisetTest::~UnorderedMultisetTest()
{

}

void UnorderedMultisetTest::searchMidTest()
{
   int key;
   clock_t begin = clock();
   for(int i = 0; i < N; i++){
       srand(time(NULL));
       key = rand();
       if(s.count(key) > 0){
           cout << *(s.find(key)) << endl;
       }
   }
   clock_t end = clock();
   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   res.searchMidTest = time_spent;
}

void UnorderedMultisetTest::insMidTest()
{
   int item;
   clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        s.insert(item);
    }
   clock_t end = clock();
   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   res.insMidTest = time_spent;
}

void UnorderedMultisetTest::delMidTest()
{
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % s.size();
        s.erase(index);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delMidTest = time_spent;
}

