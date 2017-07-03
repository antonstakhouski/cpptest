#include "listwidget.h"

#include <iostream>
#include <cstdio>
#include <time.h>

#include <array>
#include <vector>

#define N 100000

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
    QListWidget* list = (QListWidget*)_list;
    // list->clear();

    // containerTest();
    list->addItem("test");
}

void ListWidget::vectorHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();

    vector<int> v;
    for(int i = 0; i < N; i++){
        v.push_back(rand());
    }
    for(auto el : v)
        cout << el << endl;

    containerTest<>(v);

    list->addItem("Search time: " + QString::number(results.searchTest));
    list->addItem("Insert time: " + QString::number(results.insertTest));
    list->addItem("Delete time: " + QString::number(results.deleteTest));
}

template<typename T>
void ListWidget::containerTest(T& container)
{
    searchTest<>(container);
    insertTest<>(container);

    for(auto el : container)
        cout << el << endl;

    deleteTest<>(container);

    for(auto el : container)
        cout << el << endl;
}

template<typename T>
void ListWidget::searchTest(const T& container)
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
void ListWidget::insertTest(T& container)
{
    int item;
    size_t index;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        index = rand() % container.size();
        container.insert(container.begin() + index, item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.insertTest = time_spent;
}

template<typename T>
void ListWidget::deleteTest(T& container)
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

