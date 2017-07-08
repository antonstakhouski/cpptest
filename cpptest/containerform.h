#ifndef CONTAINERFORM_H
#define CONTAINERFORM_H

#include <QWidget>
#include <QListWidget>
#include <QSignalMapper>

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

namespace Ui {
class ContainerForm;
}

class ContainerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ContainerForm(QWidget *parent = 0);
    ~ContainerForm();

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

private:
    Ui::ContainerForm *ui;

    QSignalMapper** signalMapper;
    testResults results;
};

#endif // CONTAINERFORM_H
