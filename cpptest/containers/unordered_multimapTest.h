#ifndef UNORDERED_MULTIMAPTEST_H
#define UNORDERED_MULTIMAPTEST_H

#include <unordered_map>
#include <iostream>

#include "containerTest.h"

using namespace std;

class UnorderedMultimapTest : public ContainerTest
{
   unordered_multimap<int, int> m;
public:
   explicit UnorderedMultimapTest();
   ~UnorderedMultimapTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // UNORDERED_MULTIMAPTEST_H

