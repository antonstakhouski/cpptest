#ifndef MULTIMAPTEST_H
#define MULTIMAPTEST_H

#include <map>
#include <iostream>

#include "containerTest.h"

using namespace std;

class MultimapTest : public ContainerTest
{
   multimap<int, int> m;
public:
   explicit MultimapTest();
   ~MultimapTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // MULTIMAPTEST_H

