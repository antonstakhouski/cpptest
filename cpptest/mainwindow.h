#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>
#include <QTimer>
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
    QPushButton* btn;
    void printMessage();

public:
    explicit MainWindow(QWidget *parent = 0);
    void initContactList(Contact** contacts, size_t size);
    void reloadNumTable();
    ~MainWindow();
};

#endif // MAINWINDOW_H
