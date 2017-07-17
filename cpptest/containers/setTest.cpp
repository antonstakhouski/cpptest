//#include "setTest.h"

//SetTest::SetTest() : ContainerTest()
//{
//    for(int i = 0; i < N; i++){
//        srand(time(NULL));
//        s.insert(rand());
//    }
//}

//SetTest::~SetTest()
//{

//}

//void SetTest::searchHeadTest()
//{
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        cout << *(s.cbegin()) << endl;
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.searchHeadTest = time_spent;
//}

//void SetTest::searchMidTest()
//{
//    int key;
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        srand(time(NULL));
//        key = rand() % N;
//        if(s.count(key) > 0){
//            cout << *(s.find(key)) << endl;
//        }
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.searchMidTest = time_spent;
//}

//void SetTest::searchTailTest()
//{
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        cout << *(s.cend()) << endl;
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.searchTailTest = time_spent;
//}

//void SetTest::insHeadTest()
//{
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        srand(time(NULL));
//        //d.insert(d.begin(), rand());
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.insHeadTest = time_spent;
//}

//void SetTest::insMidTest()
//{
//    int index;
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        index = rand() % d.size();
//        if(index != 0 && (unsigned long)index != d.size() - 1){
//            srand(time(NULL));
//            d.insert(d.begin() + index, rand());
//        }
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.insMidTest = time_spent;
//}

//void SetTest::insTailTest()
//{
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        srand(time(NULL));
//        d.push_back(rand());
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.insTailTest = time_spent;
//}

//void SetTest::delHeadTest()
//{
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++)
//        d.erase(d.begin());
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.delHeadTest = time_spent;
//}

//void SetTest::delMidTest()
//{
//    int index;
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        index = rand() % d.size();
//        if(index != 0 && (unsigned long)index != d.size() - 1)
//            d.erase(d.begin() + index);
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.delMidTest = time_spent;
//}

//void SetTest::delTailTest()
//{
//    clock_t begin = clock();
//    for(int i = 0; i < N; i++){
//        d.pop_back();
//    }
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    res.delTailTest = time_spent;
//}

