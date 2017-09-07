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
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    r->lockResolution(checked);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    (void)obj;
    QMouseEvent* e= static_cast<QMouseEvent*>(event);
    qDebug() << e->pos();
  }
  return false;
}
