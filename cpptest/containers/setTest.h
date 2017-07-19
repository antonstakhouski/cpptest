#ifndef SETTEST_H
#define SETTEST_H

#include <set>
#include <iostream>

#include "containerTest.h"

using namespace std;

class SetTest : public ContainerTest
{
   set<int> s;
public:
   explicit SetTest();
   ~SetTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // SETTEST_H

