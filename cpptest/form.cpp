#include "form.h"
//#include "ui_form.h"
#include <iostream>

using namespace std;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    installEventFilter(this);
}

Form::~Form()
{
    delete ui;
}

//void Form::resizeEvent(QResizeEvent* event)
//{
//   Form::resizeEvent(event);
//   (void) event;

//   cout << "lol" << endl;
//}

bool Form::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this) {
        if (event->type() == QEvent::Resize) {
            cout << "lol" << endl;
            event->ignore();
        }
    }
    return QWidget::eventFilter(obj, event);
}
