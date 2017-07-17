
#include "containerform.h"
#include "ui_containerform.h"

using namespace std;

ContainerForm::ContainerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContainerForm),
    m_btnGroup(new QButtonGroup(this))
{
    ui->setupUi(this);

//    signalMapper = new QSignalMapper*[CONTAINERS_NUM];

//    signalMapper[0] = new QSignalMapper(this);
//    signalMapper[0]->setMapping(ui->btnArray, (QWidget*)ui->listWidget);
//    signalMapper[0]->setMapping(ui->btnArray_2, (QWidget*)ui->listWidget_2);
//    connect(ui->btnArray, SIGNAL(clicked()), signalMapper[0], SLOT(map()));
//    connect(ui->btnArray_2, SIGNAL(clicked()), signalMapper[0], SLOT(map()));
//    connect(signalMapper[0], SIGNAL(mapped(QWidget*)), this,
//            SLOT(arrayHandler(QWidget*)));

//    signalMapper[1] = new QSignalMapper(this);
//    signalMapper[1]->setMapping(ui->btnVector, (QWidget*)ui->listWidget);
//    signalMapper[1]->setMapping(ui->btnVector_2, (QWidget*)ui->listWidget_2);
//    connect(ui->btnVector, SIGNAL(clicked()), signalMapper[1], SLOT(map()));
//    connect(ui->btnVector_2, SIGNAL(clicked()), signalMapper[1], SLOT(map()));
//    connect(signalMapper[1], SIGNAL(mapped(QWidget*)), this,
//            SLOT(vectorHandler(QWidget*)));

//    signalMapper[3] = new QSignalMapper(this);
//    signalMapper[3]->setMapping(ui->btnDeque, (QWidget*)ui->listWidget);
//    signalMapper[3]->setMapping(ui->btnDeque_2, (QWidget*)ui->listWidget_2);
//    connect(ui->btnDeque, SIGNAL(clicked()), signalMapper[3], SLOT(map()));
//    connect(ui->btnDeque_2, SIGNAL(clicked()), signalMapper[3], SLOT(map()));
//    connect(signalMapper[3], SIGNAL(mapped(QWidget*)), this,
//            SLOT(dequeHandler(QWidget*)));


//    signalMapper[8] = new QSignalMapper(this);
//    signalMapper[8]->setMapping(ui->btnSet, (QWidget*)ui->listWidget);
//    signalMapper[8]->setMapping(ui->btnSet_2, (QWidget*)ui->listWidget_2);
//    connect(ui->btnSet, SIGNAL(clicked()), signalMapper[8], SLOT(map()));
//    connect(ui->btnSet_2, SIGNAL(clicked()), signalMapper[8], SLOT(map()));
//    connect(signalMapper[8], SIGNAL(mapped(QWidget*)), this,
//            SLOT(dequeHandler(QWidget*)));

//    connect(signalMapper[1], SIGNAL(mapped(QWidget*)), this,
//            SLOT(vectorHandler(QWidget*)));
//    connect(signalMapper[2], SIGNAL(mapped(QWidget*)), this,
//            SLOT(dequeHandler(QWidget*)));
//    connect(signalMapper[3], SIGNAL(mapped(QWidget*)), this,
//            SLOT(forward_listHandler(QWidget*)));
//    connect(signalMapper[4], SIGNAL(mapped(QWidget*)), this,
//            SLOT(listHandler(QWidget*)));
//    connect(signalMapper[5], SIGNAL(mapped(QWidget*)), this,
//            SLOT(stackHandler(QWidget*)));
//    connect(signalMapper[6], SIGNAL(mapped(QWidget*)), this,
//            SLOT(queueHandler(QWidget*)));
//    connect(signalMapper[7], SIGNAL(mapped(QWidget*)), this,
//            SLOT(priority_queueHandler(QWidget*)));
//    connect(signalMapper[8], SIGNAL(mapped(QWidget*)), this,
//            SLOT(setHandler(QWidget*)));
//    connect(signalMapper[9], SIGNAL(mapped(QWidget*)), this,
//            SLOT(multisetHandler(QWidget*)));
//    connect(signalMapper[10], SIGNAL(mapped(QWidget*)), this,
//            SLOT(mapHandler(QWidget*)));
//    connect(signalMapper[11], SIGNAL(mapped(QWidget*)), this,
//            SLOT(multimapHandler(QWidget*)));
//    connect(signalMapper[12], SIGNAL(mapped(QWidget*)), this,
//            SLOT(unordered_setHandler(QWidget*)));
//    connect(signalMapper[13], SIGNAL(mapped(QWidget*)), this,
//            SLOT(unordered_multisetHandler(QWidget*)));
//    connect(signalMapper[14], SIGNAL(mapped(QWidget*)), this,
//            SLOT(unordered_mapHandler(QWidget*)));
//    connect(signalMapper[15], SIGNAL(mapped(QWidget*)), this,
//            SLOT(unordered_multimapHandler(QWidget*)));
    m_btnGroup->addButton(ui->btnArray, 0);
    m_btnGroup->addButton(ui->btnDeque, 1);
    m_btnGroup->addButton(ui->btnVector, 2);
    m_btnGroup->addButton(ui->btnFList, 3);
    m_btnGroup->addButton(ui->btnList, 4);
    m_btnGroup->addButton(ui->btnMap, 5);
    m_btnGroup->addButton(ui->btnMmap, 6);
    m_btnGroup->addButton(ui->btnMset, 7);
    connect(m_btnGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
        [=](int id){ handleBtnPress(id); });

}

ContainerForm::~ContainerForm()
{
    delete ui;

    delete signalMapper[0];
    delete[] signalMapper;
}

void ContainerForm::arrayHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;

    ArrayTest* tst = new ArrayTest();
    results = tst->test();
    delete tst;

    printRes(lst);
}

void ContainerForm::vectorHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;

    VectorTest* tst = new VectorTest();
    results = tst->test();
    delete tst;

    printRes(lst);
}
//
// void ContainerForm::mapHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     map<int, int> m;
//     for(int i = 0; i < N; i++){
//         m.emplace(rand(), rand());
//     }
//
//     map_searchTest(m);
//     map_insertTest(m);
//     map_deleteTest(m);
//
//     printRes(lst);
// }
//
// void ContainerForm::multimapHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     multimap<int, int> m;
//     for(int i = 0; i < N; i++){
//         m.emplace(rand(), rand());
//     }
//
//     map_searchTest(m);
//     map_insertTest(m);
//     map_deleteTest(m);
//
//     printRes(lst);
// }
//
// void ContainerForm::unordered_mapHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     unordered_map<int, int> m;
//     for(int i = 0; i < N; i++){
//         m.emplace(rand(), rand());
//     }
//
//     map_searchTest(m);
//     map_insertTest(m);
//     map_deleteTest(m);
//
//     printRes(lst);
// }
//
// void ContainerForm::unordered_multimapHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     unordered_multimap<int, int> m;
//     for(int i = 0; i < N; i++){
//         m.emplace(rand(), rand());
//     }
//
//     map_searchTest(m);
//     map_insertTest(m);
//     map_deleteTest(m);
//
//     printRes(lst);
// }

void ContainerForm::setHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;

    //SetTest* tst = new SetTest();
    //results = tst->test();
    //delete tst;

    printRes(lst);
}

void ContainerForm::handleBtnPress(int id)
{
    if (m_btnGroup->id(ui->btnArray) == id) {
        qDebug()<<" YEP!";
    }
}

// void ContainerForm::multisetHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     multiset<int> s;
//     for(int i = 0; i < N; i++){
//         s.insert(rand());
//     }
//
//     set_searchTest(s);
//     set_insertTest(s);
//     map_deleteTest(s);
//
//     printRes(lst);
// }
//
// void ContainerForm::unordered_setHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     unordered_set<int> s;
//     for(int i = 0; i < N; i++){
//         s.insert(rand());
//     }
//
//     set_searchTest(s);
//     set_insertTest(s);
//     map_deleteTest(s);
//
//     printRes(lst);
// }
//
// void ContainerForm::unordered_multisetHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     unordered_multiset<int> s;
//     for(int i = 0; i < N; i++){
//         s.insert(rand());
//     }
//
//     set_searchTest(s);
//     set_insertTest(s);
//     map_deleteTest(s);
//
//     printRes(lst);
// }

void ContainerForm::dequeHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;

    DequeTest* tst = new DequeTest();
    results = tst->test();
    delete tst;

    printRes(lst);
}

void ContainerForm::printRes(QListWidget* list)
{
    list->clear();

    list->addItem("SearchHead time: " + QString::number(results.searchHeadTest));
    list->addItem("SearchMid time: " + QString::number(results.searchMidTest));
    list->addItem("SearchTail time: " + QString::number(results.searchTailTest));
    list->addItem("");

    list->addItem("InsHead time: " + QString::number(results.insHeadTest));
    list->addItem("InsMid time: " + QString::number(results.insMidTest));
    list->addItem("InsTail time: " + QString::number(results.insTailTest));
    list->addItem("");

    list->addItem("DelHead time: " + QString::number(results.delHeadTest));
    list->addItem("DelMid time: " + QString::number(results.delMidTest));
    list->addItem("DelTail time: " + QString::number(results.delTailTest));
}

// void ContainerForm::forward_listHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     forward_list<int> l;
//     for(int i = 0; i < N; i++){
//         l.push_front(rand());
//     }
//
//     list_searchTest(l);
//     list_insertTest(l);
//     list_deleteTest(l);
//
//     printRes(lst);
// }
//
// void ContainerForm::listHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     ListTest* tst = new ListTest();
//     results = tst->test();
//     delete tst;
//
//     printRes(lst);
// }
//
// void ContainerForm::stackHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     stack<int> l;
//     for(int i = 0; i < N; i++){
//         l.push(rand());
//     }
//
//     searchTest();
//     stack_insertTest(l);
//     stack_deleteTest(l);
//
//     printRes(lst);
// }
//
// void ContainerForm::queueHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     queue<int> q;
//     for(int i = 0; i < N; i++){
//         q.push(rand());
//     }
//
//     searchTest();
//     stack_insertTest(q);
//     stack_deleteTest(q);
//
//     printRes(lst);
// }
//
// void ContainerForm::priority_queueHandler(QWidget* _list)
// {
//     QListWidget* lst = (QListWidget*)_list;
//     lst->clear();
//
//     priority_queue<int> q;
//     for(int i = 0; i < N; i++){
//         q.push(rand());
//     }
//
//     searchTest();
//     stack_insertTest(q);
//     stack_deleteTest(q);
//
//     printRes(lst);
// }
//
// template<typename T>
// void ContainerForm::arr_searchTest(const T& container)
// {
//     int item;
//     size_t index;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         index = rand() % N;
//         item = *(container.begin() + index);
//         cout << item << endl;
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.searchTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::vec_insertTest(T& container)
// {
//     int item;
//     size_t index;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         item = rand();
//         index = rand() % container.size();
//         container.insert(container.begin() + index, item);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.insertTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::vec_deleteTest(T& container)
// {
//     size_t index;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         index = rand() % container.size();
//         container.erase(container.begin() + index);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.deleteTest = time_spent;
// }
//
// void ContainerForm::insertTest()
// {
//     results.insertTest = -1;
// }
//
// void ContainerForm::deleteTest()
// {
//     results.deleteTest = -1;
// }
//
// template<typename T>
// void ContainerForm::list_searchTest(const T& container)
// {
//     int item;
//     size_t index;
//     clock_t begin = clock();
//     auto iterator = container.begin();
//     for(int i = 0; i < N; i++){
//         iterator = container.begin();
//         index = rand() % N;
//         for(size_t j = 0; j < index; j++)
//             iterator++;
//         item = *(iterator);
//         cout << item << endl;
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.searchTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::list_insertTest(T& container)
// {
//     int item;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         item = rand();
//         container.push_front(item);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.insertTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::list_deleteTest(T& container)
// {
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         container.pop_front();
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.deleteTest = time_spent;
// }
//
// void ContainerForm::searchTest()
// {
//     results.searchTest = -1;
// }
//
// template<typename T>
// void ContainerForm::stack_insertTest(T& container)
// {
//     int item;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         item = rand();
//         container.push(item);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.insertTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::stack_deleteTest(T& container)
// {
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         container.pop();
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.deleteTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::set_searchTest(const T& container)
// {
//     int item;
//     size_t index;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         index = rand() % N;
//         if(container.count(index)){
//             item = *(container.find(index));
//             cout << item << endl;
//         }
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.searchTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::set_insertTest(T& container)
// {
//     int item;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         item = rand();
//         container.insert(item);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.insertTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::map_searchTest(const T& container)
// {
//     int item;
//     size_t index;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         index = rand() % N;
//         if(container.count(index) > 0){
//             item = container.find(index)->second;
//             cout << item << endl;
//         }
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.searchTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::map_insertTest(T& container)
// {
//     int item;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         item = rand();
//         container.emplace(item, item);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.insertTest = time_spent;
// }
//
// template<typename T>
// void ContainerForm::map_deleteTest(T& container)
// {
//     size_t index;
//     clock_t begin = clock();
//     for(int i = 0; i < N; i++){
//         index = rand() % container.size();
//         container.erase(index);
//     }
//     clock_t end = clock();
//     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//     results.deleteTest = time_spent;
// }
/*  */
