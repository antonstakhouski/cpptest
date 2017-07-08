#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QString>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "testResults.h"

#define N 100000
#define CONTAINERS_NUM 16

using namespace std;

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

    void printRes(QListWidget* list);

    template<typename T> void vec_insertTest(T& container);
    template<typename T> void vec_deleteTest(T& container);

    template<typename T> void arr_searchTest(const T& container);

    void searchTest();
    void insertTest();
    void deleteTest();

    template<typename T> void list_searchTest(const T& container);
    template<typename T> void list_insertTest(T& container);
    template<typename T> void list_deleteTest(T& container);

    template<typename T> void stack_insertTest(T& container);
    template<typename T> void stack_deleteTest(T& container);

    template<typename T> void set_searchTest(const T& container);
    template<typename T> void set_insertTest(T& container);

    template<typename T> void map_searchTest(const T& container);
    template<typename T> void map_insertTest(T& container);
    template<typename T> void map_deleteTest(T& container);

public slots:
    void arrayHandler(QWidget* list);
    void vectorHandler(QWidget* list);
    void forward_listHandler(QWidget* list);
    void dequeHandler(QWidget* list);
    void listHandler(QWidget* list);
    void stackHandler(QWidget* list);
    void queueHandler(QWidget* list);
    void priority_queueHandler(QWidget* list);
    void setHandler(QWidget* list);
    void multisetHandler(QWidget* list);
    void mapHandler(QWidget* list);
    void multimapHandler(QWidget* list);
    void unordered_setHandler(QWidget* list);
    void unordered_multisetHandler(QWidget* list);
    void unordered_mapHandler(QWidget* list);
    void unordered_multimapHandler(QWidget* list);
};

#endif // LISTWIDGET_H

