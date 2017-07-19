#ifndef UNORDERED_SETTEST_H
#define UNORDERED_SETTEST_H

#include <unordered_set>
#include <iostream>

#include "containerTest.h"

using namespace std;

class UnorderedSetTest : public ContainerTest
{
   unordered_set<int> s;
public:
   explicit UnorderedSetTest();
   ~UnorderedSetTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // UNORDERED_SETTEST_H

