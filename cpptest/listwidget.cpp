#include "listwidget.h"
#include <cstdio>

ListWidget::ListWidget(QWidget* parent) :
    QWidget(parent)
{
    windowLayout = new QGridLayout();

    leftList = new QListWidget();
    rightList = new QListWidget();

    leftBox = new QVBoxLayout();
    rightBox = new QVBoxLayout();

    arrayLeft = new QPushButton("Array");
    arrayRight = new QPushButton("Array");

    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(arrayLeft, (QWidget*)leftList);
    signalMapper->setMapping(arrayRight, (QWidget*)rightList);

    connect(arrayLeft, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(arrayRight, SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(signalMapper, SIGNAL(mapped(QWidget*)), this,
            SLOT(arrayClicked(QWidget*)));

    leftBox->addWidget(arrayLeft);
    rightBox->addWidget(arrayRight);

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

    delete arrayLeft;
    delete arrayRight;

    delete leftBox;
    delete rightBox;

    delete signalMapper;
    delete windowLayout;
}

void ListWidget::arrayClicked(QWidget* _list)
{
    QListWidget* list = (QListWidget*)_list;
    list->clear();
    list->addItem("test");
    puts("tst");
}

