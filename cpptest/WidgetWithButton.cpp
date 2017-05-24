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

    widgetX = this->mapFromGlobal(this->pos()).x();
    widgetY = this->mapFromGlobal(this->pos()).y();

    int btnX = ui->pushButton->x();
    int btnY = ui->pushButton->y();

    int widgetHeight = this->size().height();
    int widgetWidth = this->size().width();

    int rx = x - btnX;
    int ry = y - btnY;

//    cout << widgetX << endl;
//    cout << widgetY << endl;

    int resX;
    int resY;

    enum direction { STAY, LEFT, RIGHT, UP, DOWN, BOTTOMLEFT, BOTTOMRIGHT, TOPLEFT, TOPRIGHT};

    direction xDir = STAY;
    direction yDir = STAY;
    direction finalDir = STAY;

    if (rx <= btnWidth / 2){
        if (btnX + 2 * btnWidth >= widgetWidth) {
            xDir = STAY;
        } else {
            xDir = RIGHT;
        }
    } else {
        if (btnX - btnWidth <= widgetX) {
            xDir = STAY;
        } else {
            xDir = LEFT;
        }
    }

    if(ry <= btnHeight / 2) {
        if (btnY + 2 * btnHeight >= widgetHeight){
            yDir = STAY;
        } else {
            yDir = DOWN;
        }
    } else {
        if (btnY - btnHeight <= widgetY) {
            yDir = STAY;
        } else {
            yDir = UP;
        }
    }

    if (xDir == LEFT && yDir == STAY )
        finalDir = LEFT;
    if (xDir == RIGHT && yDir == STAY )
        finalDir = RIGHT;
    if (xDir == STAY && yDir == UP)
        finalDir = UP ;
    if (xDir == STAY && yDir == DOWN)
        finalDir = DOWN;

    if (xDir == LEFT && yDir == UP)
        finalDir = TOPLEFT;
    if (xDir == RIGHT && yDir == UP)
        finalDir = TOPRIGHT;
    if (xDir == LEFT && yDir == DOWN)
        finalDir = BOTTOMLEFT;
    if (xDir == RIGHT && yDir == DOWN)
        finalDir = BOTTOMRIGHT;
    if (xDir == STAY && yDir == STAY) {
        if (btnX > widgetWidth / 2 && btnY < widgetHeight / 2)
            finalDir = DOWN;
        if (btnX > widgetWidth / 2 && btnY > widgetHeight / 2)
            finalDir = LEFT;
        if (btnX < widgetWidth / 2 && btnY > widgetHeight / 2)
            finalDir = UP;
        if (btnX < widgetWidth / 2 && btnY < widgetHeight / 2)
            finalDir = RIGHT;
    }

    switch (finalDir) {
    case LEFT:
        resX = btnX - btnWidth;
        resY = btnY;
        break;
    case RIGHT:
        resX = btnX + btnWidth;
        resY = btnY;
        break;
    case UP:
        resX = btnX;
        resY = btnY - btnHeight;
        break;
    case DOWN:
        resX = btnX;
        resY = btnY + btnHeight;
        break;
    case TOPLEFT:
        resX = btnX - btnWidth;
        resY = btnY - btnHeight;
        break;
    case TOPRIGHT:
        resX = btnX + btnWidth;
        resY = btnY - btnHeight;
        break;
    case BOTTOMLEFT:
        resX = btnX - btnWidth;
        resY = btnY + btnHeight;
        break;
    case BOTTOMRIGHT:
        resX = btnX + btnWidth;
        resY = btnY + btnHeight;
        break;
    default:
        resX = btnX;
        resY = btnY;
        break;
    }

    ui->pushButton->move(resX, resY);
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
