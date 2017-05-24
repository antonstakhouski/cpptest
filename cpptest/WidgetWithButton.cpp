#include "WidgetWithButton.h"
#include "ui_WidgetWithButton.h"

#include <iostream>

using namespace std;

WidgetWithButton::WidgetWithButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetWithButton)
{
    setMouseTracking(true);
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

    int btnHeight = ui->pushButton->height();
    int btnWidth = ui->pushButton->width();

    int widgetX = this->x();
    int widgetY = this->y();

    int btnX = ui->pushButton->x();
    int btnY = ui->pushButton->y();

    int widgetHeight = this->size().height();
    int widgetWidth = this->size().width();

    int rx = x - btnX;
    int ry = y - btnY;

    cout << rx << endl;
    cout << ry << endl;

    int resX;
    int resY;

    if (rx <= btnWidth / 2){
        resX = btnX + btnWidth;
    } else {
        resX = btnX - btnWidth;
    }

    if(ry <= btnHeight / 2) {
        resY = btnY + btnHeight;
    } else {
        resY = btnY - btnHeight;
    }

//    int resX = btnX + btnWidth;
//    int resY = btnY + ry;


    ui->pushButton->move(resX, resY);
    cout << "hovered" << endl;
}

bool WidgetWithButton::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->pushButton) {
        if (event->type() == QEvent::Enter)
        {
            moveAway();
        }
    }
    return QWidget::eventFilter(obj, event);
}
