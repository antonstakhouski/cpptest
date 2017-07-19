#ifndef MAPTEST_H
#define MAPTEST_H

#include <map>
#include <iostream>

#include "containerTest.h"

using namespace std;

class MapTest : public ContainerTest
{
   map<int, int> m;
public:
   explicit MapTest();
   ~MapTest();
protected:
   void searchMidTest();

   void insMidTest();

   void delMidTest();
};

#endif // MAPTEST_H

