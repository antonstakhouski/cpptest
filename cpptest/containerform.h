#ifndef CONTAINERFORM_H
#define CONTAINERFORM_H

#include <QWidget>
#include <QListWidget>
#include <QSignalMapper>
#include <QButtonGroup>
#include <QDebug>

#include <iostream>
#include <cstdio>
#include <time.h>

#include "containers/arrayTest.h"
#include "containers/vectorTest.h"
#include "containers/forward_listTest.h"
#include "containers/dequeTest.h"
#include "containers/listTest.h"
#include "containers/stackTest.h"
#include "containers/queueTest.h"
#include "containers/priority_queueTest.h"
#include "containers/setTest.h"
#include "containers/multisetTest.h"
#include "containers/mapTest.h"
#include "containers/multimapTest.h"
#include "containers/unordered_setTest.h"
#include "containers/unordered_multisetTest.h"
#include "containers/unordered_mapTest.h"
#include "containers/unordered_multimapTest.h"

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

public slots:
    void arrayHandler(QListWidget* list);
    void vectorHandler(QListWidget* list);
    void forward_listHandler(QListWidget* list);
    void dequeHandler(QListWidget* list);
    void listHandler(QListWidget* list);
    void stackHandler(QListWidget* list);
    void queueHandler(QListWidget* list);
    void priority_queueHandler(QListWidget* list);
    void setHandler(QListWidget* list);
    void multisetHandler(QListWidget* list);
    void mapHandler(QListWidget* list);
    void multimapHandler(QListWidget* list);
    void unordered_setHandler(QListWidget* list);
    void unordered_multisetHandler(QListWidget* list);
    void unordered_mapHandler(QListWidget* list);
    void unordered_multimapHandler(QListWidget* list);
private slots:
    void handleBtnPress(int id);

private:
    Ui::ContainerForm *ui;

    testResults results;
    QButtonGroup *m_btnGroup;
};

#endif // CONTAINERFORM_H

