#include "WidgetWithButton.h"
#include "ui_WidgetWithButton.h"
#include <iostream>

using namespace std;

WidgetWithButton::WidgetWithButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetWithButton)
{
    setMouseTracking(true);
    setFixedSize(size());
    ui->setupUi(this);
    ui->pushButton->installEventFilter(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(btnClicked()));
}

WidgetWithButton::~WidgetWithButton()
{
    delete ui;
}

void WidgetWithButton::btnClicked()
{
    cout << "You WIN!" << endl;
}

void WidgetWithButton::moveAway()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());
    int x = p.x();
    int y = p.y();
    int* res = new int[2];
    enterHandler.moveAway(x,
                          y,
                          ui->pushButton->x(),
                          ui->pushButton->y(),
                          ui->pushButton->width(),
                          ui->pushButton->height(),
                          this->mapFromGlobal(this->pos()).x(),
                          this->mapFromGlobal(this->pos()).y(),
                          this->size().width(),
                          this->size().height(),
                          res
                          );
    ui->pushButton->move(res[0], res[1]);
}

bool WidgetWithButton::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->pushButton) {
        if (event->type() == QEvent::Enter) {
            moveAway();
        }
    }
    return QWidget::eventFilter(obj, event);
}
