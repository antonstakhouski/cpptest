#include <forward_list>
#include <iostream>

#include "containerTest.h"

using namespace std;

class ForwardListTest : public ContainerTest
{
    forward_list<int> lst;
public:
    explicit ForwardListTest();
    ~ForwardListTest();
protected:
    void searchHeadTest();
    void searchMidTest();
    void searchTailTest();

    // void insHeadTest();
    // void insMidTest();
    // void insTailTest();
    //
    // void delHeadTest();
    // void delMidTest();
    // void delTailTest();
};

