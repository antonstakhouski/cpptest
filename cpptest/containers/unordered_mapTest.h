#ifndef UNORDERED_MAPTEST_H
#define UNORDERED_MAPTEST_H

#include <unordered_map>
#include <iostream>

#include "containerTest.h"

using namespace std;

class UnorderedMapTest : public ContainerTest
{
   unordered_map<int, int> m;
public:
   explicit UnorderedMapTest();
   ~UnorderedMapTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // UNORDERED_MAPTEST_H

