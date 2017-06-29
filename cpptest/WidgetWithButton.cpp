#include "WidgetWithButton.h"
#include "ui_WidgetWithButton.h"
#include <iostream>

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

void WidgetWithButton::moveAway()
{
    QRect widgetRect = rect();

    QRect btnRect = QRect(ui->pushButton->pos(), ui->pushButton->size());

    QPoint res;
    enterHandler.moveAway(widgetRect, btnRect, &res);

    ui->pushButton->move(res);
}

void WidgetWithButton::btnClicked()
{
    std::cout << "You WIN!" << std::endl;
}

bool WidgetWithButton::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton) {
        if (event->type() == QEvent::Enter) {
            moveAway();
        }
    }
    return QWidget::eventFilter(obj, event);
}
