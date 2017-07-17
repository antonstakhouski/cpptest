#ifndef CONTAINERFORM_H
#define CONTAINERFORM_H

#include <QWidget>
#include <QListWidget>
#include <QSignalMapper>

#include "containers/arrayTest.h"
#include "containers/vectorTest.h"
// #include "containers/forward_listTest.h"
#include "containers/dequeTest.h"
// #include "containers/listTest.h"
// #include "containers/stackTest.h"
// #include "containers/queueTest.h"
#include "containers/setTest.h"
// #include "containers/mapTest.h"
// #include "containers/unordered_setTest.h"
// #include "containers/unordered_setTest.h"
//
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
    void arrayHandler(QWidget* list);
    void vectorHandler(QWidget* list);
    // void forward_listHandler(QWidget* list);
    void dequeHandler(QWidget* list);
    // void listHandler(QWidget* list);
    // void stackHandler(QWidget* list);
    // void queueHandler(QWidget* list);
    // void priority_queueHandler(QWidget* list);
    void setHandler(QWidget* list);
    // void multisetHandler(QWidget* list);
    // void mapHandler(QWidget* list);
    // void multimapHandler(QWidget* list);
    // void unordered_setHandler(QWidget* list);
    // void unordered_multisetHandler(QWidget* list);
    // void unordered_mapHandler(QWidget* list);
    // void unordered_multimapHandler(QWidget* list);

private:
    Ui::ContainerForm *ui;

    QSignalMapper** signalMapper;
    testResults results;
};

#endif // CONTAINERFORM_H

