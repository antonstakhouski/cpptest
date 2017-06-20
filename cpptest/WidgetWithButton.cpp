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

void WidgetWithButton::moveAway(const QPoint &cursorPos)
{
    QRect widgetRect = rect();

    QRect btnRect = QRect(ui->pushButton->pos(), ui->pushButton->size());

    QPoint res;
    enterHandler.moveAway(mapFromGlobal(cursorPos), widgetRect, btnRect, &res);

    ui->pushButton->move(mapFromGlobal(res));
}

void WidgetWithButton::btnClicked()
{
    cout << "You WIN!" << endl;
}

bool WidgetWithButton::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton) {
        if (event->type() == QEvent::Enter) {
            QEnterEvent *e = reinterpret_cast<QEnterEvent*>(event);
            moveAway(e->globalPos());
        }
    }
    return QWidget::eventFilter(obj, event);
}
