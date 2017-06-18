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

void WidgetWithButton::moveAway(QPoint cursorPos)
{
    QPoint res;
    QRect widgetRect;
    QRect btnRect;

    widgetRect.setTopLeft(pos());
    widgetRect.setHeight(height());
    widgetRect.setWidth(width());

    btnRect.setTopLeft(mapToGlobal(ui->pushButton->pos()));
    btnRect.setHeight(ui->pushButton->height());
    btnRect.setWidth(ui->pushButton->width());

    enterHandler.moveAway(cursorPos,
                          widgetRect,
                          btnRect,
                          &res
                          );
    ui->pushButton->move(res.x(), res.y());
}

bool WidgetWithButton::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->pushButton) {
        if (event->type() == QEvent::Enter) {
            QEnterEvent *e = reinterpret_cast<QEnterEvent*>(event);
            moveAway(e->globalPos());
        }
    }
    return QWidget::eventFilter(obj, event);
}
