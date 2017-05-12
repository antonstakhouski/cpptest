#include <QGridLayout>
#include <QListWidget>
#include <vector>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    windowLayout = new QGridLayout();
    contacts = new QListWidget();
    numbers = new QListWidget();

    windowLayout->addWidget(contacts, 0, 0);
    windowLayout->addWidget(numbers, 0, 1);

    setLayout(windowLayout);
    setWindowTitle("MyAddressBook");
}

void MainWindow::initContactList(Contact** contacts, size_t size){
    QStringList lst;
    for(size_t i = 0; i < size; i++){
        this->contVec.push_back(contacts[i]);
        lst.append(contacts[i]->getName());
    }
    this->contacts->addItems(lst);
}

MainWindow::~MainWindow()
{

}
