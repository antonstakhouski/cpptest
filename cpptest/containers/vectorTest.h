#ifndef VECTORTEST_H
#define VECTORTEST_H

#include <vector>
#include <iostream>

#include "containerTest.h"

using namespace std;

class VectorTest : public ContainerTest
{
    vector<int> vec;
public:
    explicit VectorTest();
    ~VectorTest();
protected:
    void searchHeadTest();
    void searchMidTest();
    void searchTailTest();

    void insHeadTest();
    void insMidTest();
    void insTailTest();

    void delHeadTest();
    void delMidTest();
    void delTailTest();
};

#endif // VECTORTEST_H

