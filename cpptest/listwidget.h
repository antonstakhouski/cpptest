#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QSignalMapper>

#include "testResults.h"

class ListWidget : public QWidget
{
    Q_OBJECT
    QGridLayout* windowLayout;

    QListWidget* leftList;
    QListWidget* rightList;

    QVBoxLayout* leftBox;
    QVBoxLayout* rightBox;

    QPushButton* arrayLeft;
    QPushButton* arrayRight;

    QSignalMapper* signalMapper;

    testResults results;

public:
    explicit ListWidget(QWidget* parent = 0);
    ~ListWidget();

    void containerTest();

    int searchTest();
    int insertTest();
    int deleteTest();

public slots:
    void arrayClicked(QWidget* list);
};

#endif // LISTWIDGET_H

