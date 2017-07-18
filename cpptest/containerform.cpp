#include "containerform.h"
#include "ui_containerform.h"

using namespace std;

ContainerForm::ContainerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContainerForm),
    m_btnGroup(new QButtonGroup(this))
{
    ui->setupUi(this);

    m_btnGroup->addButton(ui->btnArray, 0);
    m_btnGroup->addButton(ui->btnVector, 1);
    m_btnGroup->addButton(ui->btnDeque, 2);
    m_btnGroup->addButton(ui->btnFList, 3);
    m_btnGroup->addButton(ui->btnList, 4);
    m_btnGroup->addButton(ui->btnStack, 5);
    m_btnGroup->addButton(ui->btnQueue, 6);
    m_btnGroup->addButton(ui->btnPQueue, 7);
    m_btnGroup->addButton(ui->btnSet, 8);
    m_btnGroup->addButton(ui->btnMset, 9);
    m_btnGroup->addButton(ui->btnMap, 10);
    m_btnGroup->addButton(ui->btnMmap, 10);
    m_btnGroup->addButton(ui->btnUnSet, 11);
    m_btnGroup->addButton(ui->btnUnMset, 13);
    m_btnGroup->addButton(ui->btnUnMap, 14);
    m_btnGroup->addButton(ui->btnUnMmap, 15);

    m_btnGroup->addButton(ui->btnArray_2, 16);
    m_btnGroup->addButton(ui->btnVector_2, 17);
    m_btnGroup->addButton(ui->btnDeque_2, 18);
    m_btnGroup->addButton(ui->btnFList_2, 19);
    m_btnGroup->addButton(ui->btnList_2, 20);
    m_btnGroup->addButton(ui->btnStack_2, 21);
    m_btnGroup->addButton(ui->btnQueue_2, 22);
    m_btnGroup->addButton(ui->btnPQueue_2, 23);
    m_btnGroup->addButton(ui->btnSet_2, 24);
    m_btnGroup->addButton(ui->btnMset_2, 25);
    m_btnGroup->addButton(ui->btnMap_2, 26);
    m_btnGroup->addButton(ui->btnMmap_2, 27);
    m_btnGroup->addButton(ui->btnUnSet_2, 28);
    m_btnGroup->addButton(ui->btnUnMset_2, 29);
    m_btnGroup->addButton(ui->btnUnMap_2, 30);
    m_btnGroup->addButton(ui->btnUnMmap_2, 31);

    connect(m_btnGroup,
            static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
            [=](int id){ handleBtnPress(id); });
}

ContainerForm::~ContainerForm()
{
    delete ui;
}

void ContainerForm::handleBtnPress(int id)
{
    if (m_btnGroup->id(ui->btnArray) == id)
        arrayHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnVector) == id)
        vectorHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnDeque) == id)
        dequeHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnFList) == id)
        forward_listHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnList) == id)
        listHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnStack) == id)
        stackHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnQueue) == id)
        queueHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnPQueue) == id)
        priority_queueHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnSet) == id)
        setHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnMset) == id)
        multisetHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnMap) == id)
        mapHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnMmap) == id)
        multimapHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnUnSet) == id)
        unordered_setHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnUnMset) == id)
        unordered_multisetHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnUnMap) == id)
        unordered_mapHandler(ui->listWidget);
    if (m_btnGroup->id(ui->btnUnMmap) == id)
        unordered_multimapHandler(ui->listWidget);

    if (m_btnGroup->id(ui->btnArray_2) == id)
        arrayHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnVector_2) == id)
        vectorHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnDeque_2) == id)
        dequeHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnFList_2) == id)
        forward_listHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnList_2) == id)
        listHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnStack_2) == id)
        stackHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnQueue_2) == id)
        queueHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnPQueue_2) == id)
        priority_queueHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnSet_2) == id)
        setHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnMset_2) == id)
        multisetHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnMap_2) == id)
        mapHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnMmap_2) == id)
        multimapHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnUnSet_2) == id)
        unordered_setHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnUnMset_2) == id)
        unordered_multisetHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnUnMap_2) == id)
        unordered_mapHandler(ui->listWidget_2);
    if (m_btnGroup->id(ui->btnUnMmap_2) == id)
        unordered_multimapHandler(ui->listWidget_2);
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

void ContainerForm::arrayHandler(QListWidget* _list)
{
    ArrayTest tst;
    results = tst.test();
    printRes(_list);
}

void ContainerForm::vectorHandler(QListWidget* _list)
{
    VectorTest tst;
    results = tst.test();
    printRes(_list);
}

void ContainerForm::dequeHandler(QListWidget* _list)
{
    DequeTest tst;
    results = tst.test();
    printRes(_list);
}

void ContainerForm::forward_listHandler(QListWidget* _list)
{
    ForwardListTest tst;
    results = tst.test();
    printRes(_list);
}

void ContainerForm::listHandler(QListWidget* _list)
{
    // ListTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::stackHandler(QListWidget* _list)
{
    // StackTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::queueHandler(QListWidget* _list)
{
    // QueueTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::priority_queueHandler(QListWidget* _list)
{
    // PriorityQueueTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::setHandler(QListWidget* _list)
{
    // SetTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::multisetHandler(QListWidget* _list)
{
    // MultisetTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::mapHandler(QListWidget* _list)
{
    // MapTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::multimapHandler(QListWidget* _list)
{
    // MultimapTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::unordered_setHandler(QListWidget* _list)
{
    // UnorderedSetTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::unordered_multisetHandler(QListWidget* _list)
{
    // UnorderedMultisetTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::unordered_mapHandler(QListWidget* _list)
{
    // UnorderedMapTest tst;
    // results = tst.test();
    // printRes(_list);
}

void ContainerForm::unordered_multimapHandler(QListWidget* _list)
{
    // UnorderedMultimapTest tst;
    // results = tst.test();
    // printRes(_list);
}

//
// void ContainerForm::mapHandler(QListWidget* _list)
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
// void ContainerForm::multimapHandler(QListWidget* _list)
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
// void ContainerForm::unordered_mapHandler(QListWidget* _list)
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
// void ContainerForm::unordered_multimapHandler(QListWidget* _list)
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

// void ContainerForm::multisetHandler(QListWidget* _list)
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
// void ContainerForm::unordered_setHandler(QListWidget* _list)
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
// void ContainerForm::unordered_multisetHandler(QListWidget* _list)
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

// void ContainerForm::forward_listHandler(QListWidget* _list)
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
// void ContainerForm::listHandler(QListWidget* _list)
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
// void ContainerForm::stackHandler(QListWidget* _list)
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
// void ContainerForm::queueHandler(QListWidget* _list)
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
// void ContainerForm::priority_queueHandler(QListWidget* _list)
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
