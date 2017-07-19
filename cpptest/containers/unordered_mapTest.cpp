#include "unordered_mapTest.h"

UnorderedMapTest::UnorderedMapTest() : ContainerTest()
{
    for(int i = 0; i < N; i++){
        srand(time(NULL));
        m.emplace(rand(), rand());
    }
}

UnorderedMapTest::~UnorderedMapTest()
{

}

void UnorderedMapTest::searchMidTest()
{
   int key;
   clock_t begin = clock();
   for(int i = 0; i < N; i++){
       srand(time(NULL));
       key = rand();
       if(m.count(key) > 0){
           cout << m.find(key)->second << endl;
       }
   }
   clock_t end = clock();
   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   res.searchMidTest = time_spent;
}

void UnorderedMapTest::insMidTest()
{
   clock_t begin = clock();
   for(int i = 0; i < N; i++){
       srand(time(NULL));
       m.emplace(rand(), rand());
   }
   clock_t end = clock();
   double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
   res.searchMidTest = time_spent;
}

void UnorderedMapTest::delMidTest()
{
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand();
        m.erase(index);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    res.delMidTest = time_spent;
}

