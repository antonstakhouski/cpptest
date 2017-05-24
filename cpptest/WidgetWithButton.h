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

public:


Q_SIGNALS:
    void hovered();

private:
    Ui::WidgetWithButton *ui;

    enum direction { STAY, LEFT, RIGHT, UP, DOWN, BOTTOMLEFT, BOTTOMRIGHT, TOPLEFT, TOPRIGHT};
    int btnWidth;
    int btnHeight;
    int trickyOffset;
    int widgetHeight;
    int widgetWidth;
    int widgetX;
    int widgetY;

    void moveToDir(int btnX, int btnY, direction finalDir, int* res);
    void chooseDirSimple(int rx, int ry, int btnX, int btnY, direction *resDirect);
    void chooseDestination(direction xDir, direction yDir, int btnX, int btnY, direction* finalDir);

    void moveLeft(int btnX, int btnY, int *res);
    void moveRight(int btnX, int btnY, int *res);
    void moveUp(int btnX, int btnY, int *res);
    void moveDown(int btnX, int btnY, int *res);
    void moveTopLeft(int btnX, int btnY, int *res);
    void moveTopRight(int btnX, int btnY, int *res);
    void moveBottomLeft(int btnX, int btnY, int *res);
    void moveBottomRight(int btnX, int btnY, int *res);
    void moveNull(int btnX, int btnY, int *res);
};

#endif // WIDGETWITHBUTTON_H
