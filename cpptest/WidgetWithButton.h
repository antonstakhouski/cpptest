#ifndef WIDGETWITHBUTTON_H
#define WIDGETWITHBUTTON_H

#include <QWidget>
#include <QPushButton>

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
    void moveAway();
    void btnClicked();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

public: Q_SIGNALS:
    void hovered();

private:
    Ui::WidgetWithButton *ui;
};

#endif // WIDGETWITHBUTTON_H
