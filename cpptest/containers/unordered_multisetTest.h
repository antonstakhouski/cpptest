#ifndef UNORDERED_MULTISETTEST_H
#define UNORDERED_MULTISETTEST_H

#include <unordered_set>
#include <iostream>

#include "containerTest.h"

using namespace std;

class UnorderedMultisetTest : public ContainerTest
{
   unordered_multiset<int> s;
public:
   explicit UnorderedMultisetTest();
   ~UnorderedMultisetTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // UNORDERD_MULTISETTEST_H

