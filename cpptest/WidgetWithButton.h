#ifndef WIDGETWITHBUTTON_H
#define WIDGETWITHBUTTON_H

#include <QWidget>

namespace Ui {
class WidgetWithButton;
}

class WidgetWithButton : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetWithButton(QWidget *parent = 0);
    ~WidgetWithButton();

private:
    Ui::WidgetWithButton *ui;
};

#endif // WIDGETWITHBUTTON_H
