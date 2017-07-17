#ifndef TESTRESULTS_H
#define TESTRESULTS_H

struct testResults{
    double searchHeadTest;
    double searchMidTest;
    double searchTailTest;

    double insHeadTest;
    double insMidTest;
    double insTailTest;

    double delHeadTest;
    double delMidTest;
    double delTailTest;
};

typedef struct testResults testResults;

#endif // TESTRESULTS_H

