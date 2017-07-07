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

    void printRes(QListWidget* list);

public:
    explicit ListWidget(QWidget* parent = 0);
    ~ListWidget();

    template<typename T>
    void containerTest(T& container);

    void searchTest(const vector<int>& container);
    void insertTest(vector<int>& container);
    template<typename T> void vec_deleteTest(T& container);

    void searchTest(const array<int, N>& container);
    void insertTest(array<int, N>& container);
    void deleteTest(array<int, N>& container);

    void searchTest(const deque<int>& container);
    void insertTest(deque<int>& container);

    void searchTest(const forward_list<int>& container);
    void insertTest(forward_list<int>& container);
    void deleteTest(forward_list<int>& container);

    void searchTest(const list<int>& container);
    void insertTest(list<int>& container);
    void deleteTest(list<int>& container);

    void searchTest(const stack<int>& container);
    template<typename T> void stack_insertTest(T& container);
    void deleteTest(stack<int>& container);

    void searchTest(const queue<int>& container);
    void deleteTest(queue<int>& container);

    void searchTest(const priority_queue<int>& container);
    template<typename T> void queue_deleteTest(T& container);

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

