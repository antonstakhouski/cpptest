#include "listwidget.h"

#include <iostream>
#include <cstdio>
#include <time.h>

using namespace std;

ListWidget::ListWidget(QWidget* parent) :
    QWidget(parent)
{
    windowLayout = new QGridLayout();

    leftList = new QListWidget();
    rightList = new QListWidget();

    leftBox = new QVBoxLayout();
    rightBox = new QVBoxLayout();

    leftButtons = new QPushButton*[CONTAINERS_NUM];
    rightButtons = new QPushButton*[CONTAINERS_NUM];
    signalMapper = new QSignalMapper*[CONTAINERS_NUM];
    for(int i = 0; i < CONTAINERS_NUM; i++){
        leftButtons[i] = new QPushButton(labels[i]);
        rightButtons[i] = new QPushButton(labels[i]);
        signalMapper[i] = new QSignalMapper(this);
        signalMapper[i]->setMapping(leftButtons[i], (QWidget*)leftList);
        signalMapper[i]->setMapping(rightButtons[i], (QWidget*)rightList);
        connect(leftButtons[i], SIGNAL(clicked()), signalMapper[i], SLOT(map()));
        connect(rightButtons[i], SIGNAL(clicked()), signalMapper[i], SLOT(map()));
        leftBox->addWidget(leftButtons[i]);
        rightBox->addWidget(rightButtons[i]);
    }
    connect(signalMapper[0], SIGNAL(mapped(QWidget*)), this,
            SLOT(arrayHandler(QWidget*)));
    connect(signalMapper[1], SIGNAL(mapped(QWidget*)), this,
            SLOT(vectorHandler(QWidget*)));
    connect(signalMapper[2], SIGNAL(mapped(QWidget*)), this,
            SLOT(dequeHandler(QWidget*)));
    connect(signalMapper[3], SIGNAL(mapped(QWidget*)), this,
            SLOT(forward_listHandler(QWidget*)));
    connect(signalMapper[4], SIGNAL(mapped(QWidget*)), this,
            SLOT(listHandler(QWidget*)));
    connect(signalMapper[5], SIGNAL(mapped(QWidget*)), this,
            SLOT(stackHandler(QWidget*)));
    connect(signalMapper[6], SIGNAL(mapped(QWidget*)), this,
            SLOT(queueHandler(QWidget*)));
    connect(signalMapper[7], SIGNAL(mapped(QWidget*)), this,
            SLOT(priority_queueHandler(QWidget*)));
    connect(signalMapper[8], SIGNAL(mapped(QWidget*)), this,
            SLOT(setHandler(QWidget*)));
    connect(signalMapper[9], SIGNAL(mapped(QWidget*)), this,
            SLOT(multisetHandler(QWidget*)));
    connect(signalMapper[10], SIGNAL(mapped(QWidget*)), this,
            SLOT(mapHandler(QWidget*)));
    connect(signalMapper[11], SIGNAL(mapped(QWidget*)), this,
            SLOT(multimapHandler(QWidget*)));
    connect(signalMapper[12], SIGNAL(mapped(QWidget*)), this,
            SLOT(unordered_setHandler(QWidget*)));
    connect(signalMapper[13], SIGNAL(mapped(QWidget*)), this,
            SLOT(unordered_multisetHandler(QWidget*)));
    connect(signalMapper[14], SIGNAL(mapped(QWidget*)), this,
            SLOT(unordered_mapHandler(QWidget*)));
    connect(signalMapper[15], SIGNAL(mapped(QWidget*)), this,
            SLOT(unordered_multimapHandler(QWidget*)));

    windowLayout->addLayout(leftBox, 0, 0, 0);
    windowLayout->addWidget(leftList, 0, 1);
    windowLayout->addWidget(rightList, 0, 2);
    windowLayout->addLayout(rightBox, 0, 3, 0);

    setLayout(windowLayout);
    setWindowTitle("Containers/SmartPointers comparison test");
}

ListWidget::~ListWidget()
{
    delete leftList;
    delete rightList;

    delete leftBox;
    delete rightBox;

    delete windowLayout;

    for(int i = 0; i < CONTAINERS_NUM; i++){
        delete leftButtons[i];
        delete rightButtons[i];
        delete signalMapper[i];
    }
    delete[] leftButtons;
    delete[] rightButtons;
    delete[] signalMapper;
}

void ListWidget::arrayHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    array<int, N> arr;
    for(int i = 0; i < N; i++){
        arr[i] = rand();
    }

    containerTest(arr);
    printRes(lst);
}

void ListWidget::vectorHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    vector<int> v;
    for(int i = 0; i < N; i++){
        v.push_back(rand());
    }

    containerTest(v);
    printRes(list);
}

void ListWidget::mapHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    map<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    containerTest(m);
    printRes(list);
}

void ListWidget::multimapHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    multimap<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    containerTest(m);
    printRes(list);
}

void ListWidget::unordered_mapHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    unordered_map<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    containerTest(m);
    printRes(list);
}

void ListWidget::unordered_multimapHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    unordered_multimap<int, int> m;
    for(int i = 0; i < N; i++){
        m.emplace(rand(), rand());
    }

    containerTest(m);
    printRes(list);
}

void ListWidget::setHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    set<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    containerTest(s);
    printRes(list);
}

void ListWidget::multisetHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    multiset<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    containerTest(s);
    printRes(list);
}

void ListWidget::unordered_setHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    unordered_set<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    containerTest(s);
    printRes(list);
}

void ListWidget::unordered_multisetHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    unordered_multiset<int> s;
    for(int i = 0; i < N; i++){
        s.insert(rand());
    }

    containerTest(s);
    printRes(list);
}

void ListWidget::dequeHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    deque<int> d;
    for(int i = 0; i < N; i++){
        d.push_back(rand());
    }

    containerTest(d);
    printRes(list);
}

void ListWidget::printRes(QListWidget* list)
{
    list->addItem("Search time: " + QString::number(results.searchTest));
    list->addItem("Insert time: " + QString::number(results.insertTest));
    list->addItem("Delete time: " + QString::number(results.deleteTest));
}

void ListWidget::forward_listHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    forward_list<int> l;
    for(int i = 0; i < N; i++){
        l.push_front(rand());
    }

    containerTest(l);
    printRes(list);
}

void ListWidget::listHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    list<int> l;
    for(int i = 0; i < N; i++){
        l.push_front(rand());
    }

    containerTest(l);
    printRes(lst);
}

void ListWidget::stackHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    stack<int> l;
    for(int i = 0; i < N; i++){
        l.push(rand());
    }

    containerTest(l);
    printRes(lst);
}

void ListWidget::queueHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    queue<int> q;
    for(int i = 0; i < N; i++){
        q.push(rand());
    }

    containerTest(q);
    printRes(lst);
}

void ListWidget::priority_queueHandler(QWidget* _list)
{
    QListWidget* lst = (QListWidget*)_list;
    lst->clear();

    priority_queue<int> q;
    for(int i = 0; i < N; i++){
        q.push(rand());
    }

    containerTest(q);
    printRes(lst);
}

template<typename T>
void ListWidget::containerTest(T& container)
{
    searchTest(container);
    insertTest(container);
    deleteTest(container);
}

void ListWidget::searchTest(const vector<int>& container)
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

void ListWidget::insertTest(vector<int>& container)
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

void ListWidget::deleteTest(vector<int>& container)
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

void ListWidget::searchTest(const array<int, N>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        item = container[index];
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

void ListWidget::insertTest(array<int, N>& container)
{
    results.insertTest = -1;
}

void ListWidget::deleteTest(array<int, N>& container)
{
    results.deleteTest = -1;
}

void ListWidget::searchTest(const deque<int>& container)
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

void ListWidget::insertTest(deque<int>& container)
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

void ListWidget::deleteTest(deque<int>& container)
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

void ListWidget::searchTest(const forward_list<int>& container)
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

void ListWidget::insertTest(forward_list<int>& container)
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

void ListWidget::deleteTest(forward_list<int>& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop_front();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ListWidget::searchTest(const list<int>& container)
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

void ListWidget::insertTest(list<int>& container)
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

void ListWidget::deleteTest(list<int>& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop_front();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ListWidget::searchTest(const stack<int>& container)
{
    results.searchTest = -1;
}

void ListWidget::insertTest(stack<int>& container)
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

void ListWidget::deleteTest(stack<int>& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ListWidget::searchTest(const queue<int>& container)
{
    results.searchTest = -1;
}

void ListWidget::insertTest(queue<int>& container)
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

void ListWidget::deleteTest(queue<int>& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ListWidget::searchTest(const priority_queue<int>& container)
{
    results.searchTest = -1;
}

void ListWidget::insertTest(priority_queue<int>& container)
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

void ListWidget::deleteTest(priority_queue<int>& container)
{
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        container.pop();
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.deleteTest = time_spent;
}

void ListWidget::searchTest(const set<int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        item = *(container.find(index));
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

void ListWidget::insertTest(set<int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.insert(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(set<int>& container)
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

void ListWidget::searchTest(const multiset<int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        item = *(container.find(index));
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

void ListWidget::insertTest(multiset<int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.insert(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(multiset<int>& container)
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

void ListWidget::searchTest(const map<int, int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        item = container.find(index)->second;
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

void ListWidget::insertTest(map<int, int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.emplace(item, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(map<int, int>& container)
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

void ListWidget::searchTest(const multimap<int, int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % N;
        item = container.find(index)->second;
        cout << item << endl;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;
}

void ListWidget::insertTest(multimap<int, int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.emplace(item, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(multimap<int, int>& container)
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

void ListWidget::searchTest(const unordered_set<int>& container)
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

void ListWidget::insertTest(unordered_set<int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.insert(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(unordered_set<int>& container)
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

void ListWidget::searchTest(const unordered_multiset<int>& container)
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

void ListWidget::insertTest(unordered_multiset<int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.insert(item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(unordered_multiset<int>& container)
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

void ListWidget::searchTest(const unordered_map<int, int>& container)
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

void ListWidget::insertTest(unordered_map<int, int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.emplace(item, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(unordered_map<int, int>& container)
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

void ListWidget::searchTest(const unordered_multimap<int, int>& container)
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

void ListWidget::insertTest(unordered_multimap<int, int>& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = rand();
        index = rand() % container.size();
        container.emplace(item, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

void ListWidget::deleteTest(unordered_multimap<int, int>& container)
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

