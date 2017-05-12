#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QListWidget>
#include <vector>
#include "contact.h"

using namespace std;

class MainWindow : public QWidget
{
    Q_OBJECT
    QGridLayout* windowLayout;
    QListWidget* contacts;
    QListWidget* numbers;
    vector<Contact*> contVec;

public:
    explicit MainWindow(QWidget *parent = 0);
    void initContactList(Contact** contacts, size_t size);
    ~MainWindow();
};

#endif // MAINWINDOW_H
