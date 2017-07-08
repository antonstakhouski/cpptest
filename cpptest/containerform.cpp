#include <iostream>
#include <cstdio>
#include <time.h>

#include "containerform.h"
#include "ui_containerform.h"

using namespace std;

ContainerForm::ContainerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContainerForm)
{
    ui->setupUi(this);

    signalMapper = new QSignalMapper*[CONTAINERS_NUM];

    signalMapper[0] = new QSignalMapper(this);
    // ui->dequeHandler
    signalMapper[0]->setMapping(ui->btnArray, (QWidget*)ui->listWidget);
    signalMapper[0]->setMapping(ui->btnArray_2, (QWidget*)ui->listWidget_2);
    connect(ui->btnArray, SIGNAL(clicked()), signalMapper[0], SLOT(map()));
    connect(ui->btnArray_2, SIGNAL(clicked()), signalMapper[0], SLOT(map()));

    connect(signalMapper[0], SIGNAL(mapped(QWidget*)), this,
            SLOT(arrayHandler(QWidget*)));
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
}

ContainerForm::~ContainerForm()
{
    delete ui;

    delete signalMapper[0];
    delete[] signalMapper;
}

void ContainerForm::arrayHandler(QWidget* _list)
{
    puts("ok");

    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    puts("ok");

    array<int, N> arr;
    for(int i = 0; i < N; i++){
        arr[i] = rand();
    }

    arr_searchTest(arr);
    insertTest();
    deleteTest();

    printRes(lst);
}

void ContainerForm::vectorHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    vector<int> v;
    for(int i = 0; i < N; i++){
        v.push_back(rand());
    }

    arr_searchTest(v);
    vec_insertTest(v);
    vec_deleteTest(v);

    printRes(lst);
}

void ContainerForm::mapHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    map<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    map_searchTest(m);
    map_insertTest(m);
    map_deleteTest(m);

    printRes(lst);
}

void ContainerForm::multimapHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    multimap<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    map_searchTest(m);
    map_insertTest(m);
    map_deleteTest(m);

    printRes(lst);
}

void ContainerForm::unordered_mapHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    unordered_map<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    map_searchTest(m);
    map_insertTest(m);
    map_deleteTest(m);

    printRes(lst);
}

void ContainerForm::unordered_multimapHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    unordered_multimap<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    map_searchTest(m);
    map_insertTest(m);
    map_deleteTest(m);

    printRes(lst);
}

void ContainerForm::setHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    set<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    set_searchTest(s);
    set_insertTest(s);
    map_deleteTest(s);

    printRes(list);
}

void ContainerForm::multisetHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    multiset<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    set_searchTest(s);
    set_insertTest(s);
    map_deleteTest(s);

    printRes(lst);
}

void ContainerForm::unordered_setHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    unordered_set<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    set_searchTest(s);
    set_insertTest(s);
    map_deleteTest(s);

    printRes(lst);
}

void ContainerForm::unordered_multisetHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    unordered_multiset<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    set_searchTest(s);
    set_insertTest(s);
    map_deleteTest(s);

    printRes(lst);
}

void ContainerForm::dequeHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    deque<int> d;
    for(int i = 0; i < N; i++){
        d.push_back(rand());
    }

    arr_searchTest(d);
    vec_insertTest(d);
    vec_deleteTest(d);

    printRes(lst);
}

void ContainerForm::printRes(QListWidget* list)
{
    list->addItem("Search time: " + QString::number(results.searchTest));
    list->addItem("Insert time: " + QString::number(results.insertTest));
    list->addItem("Delete time: " + QString::number(results.deleteTest));
}

void ContainerForm::forward_listHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    forward_list<int> l;
    for(int i = 0; i < N; i++){
        l.push_front(rand());
    }

    list_searchTest(l);
    list_insertTest(l);
    list_deleteTest(l);

    printRes(lst);
}

void ContainerForm::listHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    list<int> l;
    for(int i = 0; i < N; i++){
        l.push_front(rand());
    }

    list_searchTest(l);
    list_insertTest(l);
    list_deleteTest(l);

    printRes(lst);
}

void ContainerForm::stackHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    stack<int> l;
    for(int i = 0; i < N; i++){
        l.push(rand());
    }

    searchTest();
    stack_insertTest(l);
    stack_deleteTest(l);

    printRes(lst);
}

void ContainerForm::queueHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    queue<int> q;
    for(int i = 0; i < N; i++){
        q.push(rand());
    }

    searchTest();
    stack_insertTest(q);
    stack_deleteTest(q);

    printRes(lst);
}

void ContainerForm::priority_queueHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    priority_queue<int> q;
    for(int i = 0; i < N; i++){
        q.push(rand());
    }

    searchTest();
    stack_insertTest(q);
    stack_deleteTest(q);

    printRes(lst);
}

template<typename T>
void ContainerForm::arr_searchTest(const T& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        item = *(container.begin() + index);
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

template<typename T>
void ContainerForm::vec_insertTest(T& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.insert(container.begin() + index, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

template<typename T>
void ContainerForm::vec_deleteTest(T& container)
{
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % container.size();
        container.erase(container.begin() + index);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ContainerForm::insertTest()
{
    results.insertTest = -1;
}

void ContainerForm::deleteTest()
{
    results.deleteTest = -1;
}

template<typename T>
void ContainerForm::list_searchTest(const T& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    auto iterator = container.begin();
    for(int i = 0; i < N; i++){
        iterator = container.begin();
        index = rand() % N;
        for(size_t j = 0; j < index; j++)
            iterator++;
        item = *(iterator);
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

template<typename T>
void ContainerForm::list_insertTest(T& container)
{
    int item;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        container.push_front(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

template<typename T>
void ContainerForm::list_deleteTest(T& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop_front();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ContainerForm::searchTest()
{
    results.searchTest = -1;
}

template<typename T>
void ContainerForm::stack_insertTest(T& container)
{
    int item;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        container.push(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

template<typename T>
void ContainerForm::stack_deleteTest(T& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

template<typename T>
void ContainerForm::set_searchTest(const T& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        if(container.count(index)){
            item = *(container.find(index));
            cout << item << endl;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

template<typename T>
void ContainerForm::set_insertTest(T& container)
{
    int item;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        container.insert(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

template<typename T>
void ContainerForm::map_searchTest(const T& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        if(container.count(index) > 0){
            item = container.find(index)->second;
            cout << item << endl;
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

template<typename T>
void ContainerForm::map_insertTest(T& container)
{
    int item;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        container.emplace(item, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

template<typename T>
void ContainerForm::map_deleteTest(T& container)
{
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % container.size();
        container.erase(index);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

