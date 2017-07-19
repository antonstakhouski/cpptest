#ifndef MULTISETTEST_H
#define MULTISETTEST_H

#include <set>
#include <iostream>

#include "containerTest.h"

using namespace std;

class MultisetTest : public ContainerTest
{
   set<int> s;
public:
   explicit MultisetTest();
   ~MultisetTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // MULTISETTEST_H

