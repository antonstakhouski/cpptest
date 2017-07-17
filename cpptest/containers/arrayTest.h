#ifndef ARRAYTEST_H
#define ARRAYTEST_H

#include <array>
#include <iostream>

#include "containerTest.h"

using namespace std;

class ArrayTest : public ContainerTest
{
    array<int, N> arr;
public:
    explicit ArrayTest();
    ~ArrayTest();
protected:
    void searchHeadTest();
    void searchMidTest();
    void searchTailTest();
};

#endif // ARRAYTEST_H

