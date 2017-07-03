#include "listwidget.h"

#include <cstdio>
#include <time.h>
#include <array>

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

    signalMapper = new QSignalMapper(this);
    for(int i = 0; i < CONTAINERS_NUM; i++){
        leftButtons[i] = new QPushButton(labels[i]);
        rightButtons[i] = new QPushButton(labels[i]);
        signalMapper->setMapping(leftButtons[i], (QWidget*)leftList);
        signalMapper->setMapping(rightButtons[i], (QWidget*)rightList);
        connect(leftButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        connect(rightButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        leftBox->addWidget(leftButtons[i]);
        rightBox->addWidget(rightButtons[i]);
    }
    connect(signalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(btnHandler(QWidget*)));

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

    delete signalMapper;
    delete windowLayout;

    for(int i = 0; i < CONTAINERS_NUM; i++){
        delete leftButtons[i];
        delete rightButtons[i];
    }
    delete[] leftButtons;
    delete[] rightButtons;
}

void ListWidget::btnHandler(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    // list->clear();

    // containerTest();
    list->addItem("test");
}

void ListWidget::containerTest()
{
    array<int, N> arr;

    for(int i = 0; i < N; i++){
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }

    int item;
    clock_t begin = clock();
    for(int i = 0; i < N; i++){
        item = arr[i];
        printf("%d\n", item);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    results.searchTest = time_spent;

    printf("search time: %f\n", time_spent);
    //
    // array<int, N> arr2;
    // for(int i = 0; i < N; i++){
    //     arr2[ i] = rand();
    // }
}

int ListWidget::searchTest()
{

    return 0;
}

int ListWidget::insertTest()
{

    return 0;
}

int ListWidget::deleteTest()
{

    return 0;
}

