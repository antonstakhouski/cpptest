#ifndef CONTAINERTEST_H
#define CONTAINERTEST_H

#include "testResults.h"

#define N 10

class ContainerTest
{
public:
    explicit ContainerTest();
    virtual ~ContainerTest() = 0;

    testResults test();
protected:
    testResults res;

    virtual void searchTest();
    virtual void insTest();
    virtual void delTest();

    virtual void searchHeadTest();
    virtual void searchMidTest();
    virtual void searchTailTest();

    virtual void insHeadTest();
    virtual void insMidTest();
    virtual void insTailTest();

    virtual void delHeadTest();
    virtual void delMidTest();
    virtual void delTailTest();
};

#endif // CONTAINERTEST_H

