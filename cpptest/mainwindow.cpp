#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::resizeEvent(QResizeEvent* event)
//{
//    (void) event;
//   float ratio = width() / height();
//   cout << ui->centralwidget->cursor().pos().x() << endl;
//   cout << ui->centralwidget->cursor().pos().y() << endl << endl;
//   cout << "lol" << endl;

//}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->centralwidget) {
        if (event->type() == QEvent::Resize) {
            cout << "lol" << endl;
            event->ignore();
        }
    }
    return QWidget::eventFilter(obj, event);
}
