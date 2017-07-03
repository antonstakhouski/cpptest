#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

#include "testResults.h"

#define CONTAINERS_NUM 16

class ListWidget : public QWidget
{
    Q_OBJECT
    QGridLayout* windowLayout;

    QListWidget* leftList;
    QListWidget* rightList;

    QVBoxLayout* leftBox;
    QVBoxLayout* rightBox;

    const QString labels[CONTAINERS_NUM] = {"Array", "Vector", "Deque",
        "Forward List", "List",
        "Stack", "Queue", "Priority queue", "Set", "Multiset", "Map", "Multimap",
        "Unordered Set", "Unordered Multiset", "Unordered Map", "Unordered Multimap"};
    QPushButton** leftButtons;
    QPushButton** rightButtons;

    QSignalMapper** signalMapper;

    testResults results;

public:
    explicit ListWidget(QWidget* parent = 0);
    ~ListWidget();

    template<typename T> void containerTest(T& container);

    template<typename T> void searchTest(const T& container);
    template<typename T> void insertTest(T& container);
    template<typename T> void deleteTest(T& container);

public slots:
    void arrayHandler(QWidget* list);
    void vectorHandler(QWidget* list);
    // void dequeHandler(QWidget* list);
    // void forwardListHandler(QWidget* list);
    // void listHandler(QWidget* list);
};

#endif // LISTWIDGET_H

