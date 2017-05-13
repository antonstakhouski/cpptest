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

    btn = new QPushButton("Push");

    connect(btn, SIGNAL(clicked()), this, SLOT(printMessage()));
    windowLayout->addWidget(btn, 1, 0);

    setLayout(windowLayout);
    //contacts->selectedItems()
    setWindowTitle("MyAddressBook");
    reloadNumTable();
}

void MainWindow::printMessage(){
    QStringList lst;
    lst.append("TEST");
    this->numbers->addItems(lst);
}

void MainWindow::initContactList(Contact **contacts, size_t size){
    QStringList lst;
    for(size_t i = 0; i < size; i++){
        this->contVec.push_back(contacts[i]);
        lst.append(contacts[i]->getName());
    }
    this->contacts->addItems(lst);
}

void MainWindow::reloadNumTable(){
    puts("lol");
    //QTimer.singleShot(1000, this, SLOT(this->reloadNumTable));
}

MainWindow::~MainWindow()
{

}
