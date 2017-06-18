#ifndef WIDGETWITHBUTTON_H
#define WIDGETWITHBUTTON_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QEnterEvent>
#include "enterhandler.h"

namespace Ui {
class WidgetWithButton;
}

class WidgetWithButton : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetWithButton(QWidget *parent = 0);
    ~WidgetWithButton();
public slots:
    void moveAway(const QPoint &cursorPos);
    void btnClicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void hovered();

private:
    Ui::WidgetWithButton *ui;
    EnterHandler enterHandler;
};

#endif // WIDGETWITHBUTTON_H
