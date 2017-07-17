#include <cstdlib>
#include <ctime>

#include "containerTest.h"

ContainerTest::ContainerTest()
{

}

ContainerTest::~ContainerTest()
{

}

testResults ContainerTest::test()
{
    searchTest();
    insTest();
    delTest();

    return res;
}

void ContainerTest::searchTest()
{
    searchHeadTest();
    searchMidTest();
    searchTailTest();
}

void ContainerTest::insTest()
{
    insHeadTest();
    insMidTest();
    insTailTest();
}

void ContainerTest::delTest()
{
    delHeadTest();
    delMidTest();
    delTailTest();
}

void ContainerTest::searchHeadTest()
{
    res.searchHeadTest = -1;
}

void ContainerTest::searchMidTest()
{
    res.searchMidTest = -1;
}

void ContainerTest::searchTailTest()
{
    res.searchTailTest = -1;
}

void ContainerTest::insHeadTest()
{
    res.insHeadTest = -1;
}

void ContainerTest::insMidTest()
{
    res.insMidTest = -1;
}

void ContainerTest::insTailTest()
{
    res.insTailTest = -1;
}

void ContainerTest::delHeadTest()
{
    res.delHeadTest = -1;
}

void ContainerTest::delMidTest()
{
    res.delMidTest = -1;
}

void ContainerTest::delTailTest()
{
    res.delTailTest = -1;
}

