#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    r(new SmartResizer(this))
{
    ui->setupUi(this);
    r->installWidget(this);
    setMouseTracking(true);
    qApp->installEventFilter(r);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    r->lockResolution(checked);
}
