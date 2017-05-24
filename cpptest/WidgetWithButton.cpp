#include "WidgetWithButton.h"
#include "ui_WidgetWithButton.h"

#include <iostream>

using namespace std;

WidgetWithButton::WidgetWithButton(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::WidgetWithButton)
{
    setMouseTracking(true);
    //    setFixedSize(size());
    ui->setupUi(this);
    ui->pushButton->installEventFilter(this);

    btnHeight = ui->pushButton->height();
    btnWidth = ui->pushButton->width();
    trickyOffset = 10;
    widgetHeight = this->size().height();
    widgetWidth = this->size().width();
    widgetX = this->mapFromGlobal(this->pos()).x();
    widgetY = this->mapFromGlobal(this->pos()).y();

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

void WidgetWithButton::moveToDir(int btnX, int btnY, direction finalDir, int* res)
{
    int resX;
    int resY;
    switch (finalDir) {
    case LEFT:
        resX = btnX - btnWidth - trickyOffset;
        resY = btnY;
        break;
    case RIGHT:
        resX = btnX + btnWidth + trickyOffset;;
        resY = btnY;
        break;
    case UP:
        resX = btnX;
        resY = btnY - btnHeight - trickyOffset;;
        break;
    case DOWN:
        resX = btnX;
        resY = btnY + btnHeight + trickyOffset;;
        break;
    case TOPLEFT:
        resX = btnX - btnWidth;
        resY = btnY - btnHeight - trickyOffset;;
        break;
    case TOPRIGHT:
        resX = btnX + btnWidth;
        resY = btnY - btnHeight - trickyOffset;;
        break;
    case BOTTOMLEFT:
        resX = btnX - btnWidth;
        resY = btnY + btnHeight + trickyOffset;;
        break;
    case BOTTOMRIGHT:
        resX = btnX + btnWidth;
        resY = btnY + btnHeight + trickyOffset;;
        break;
    default:
        resX = btnX;
        resY = btnY;
        break;
    }
    res[0] = resX;
    res[1] = resY;
}

void WidgetWithButton::chooseDirSimple(int rx, int ry, int btnX, int btnY, direction* resDirect)
{
    direction xDir;
    direction yDir;
    if (rx <= btnWidth / 2){
        if (btnX + 2 * btnWidth + trickyOffset >= widgetWidth) {
            xDir = STAY;
        } else {
            xDir = RIGHT;
        }
    } else {
        if (btnX - btnWidth  - trickyOffset <= widgetX) {
            xDir = STAY;
        } else {
            xDir = LEFT;
        }
    }

    if(ry <= btnHeight / 2) {
        if (btnY + 2 * btnHeight  + trickyOffset >= widgetHeight){
            yDir = STAY;
        } else {
            yDir = DOWN;
        }
    } else {
        if (btnY - btnHeight  - trickyOffset <= widgetY) {
            yDir = STAY;
        } else {
            yDir = UP;
        }
    }
    resDirect[0] = xDir;
    resDirect[1] = yDir;
}

void WidgetWithButton::chooseDestination(direction xDir, direction yDir,
                                         int btnX, int btnY, direction* finalDir)
{
    *finalDir = STAY;
    if (xDir == LEFT && yDir == STAY )
        *finalDir = LEFT;
    if (xDir == RIGHT && yDir == STAY )
        *finalDir = RIGHT;
    if (xDir == STAY && yDir == UP)
        *finalDir = UP ;
    if (xDir == STAY && yDir == DOWN)
        *finalDir = DOWN;

    if (xDir == LEFT && yDir == UP)
        *finalDir = TOPLEFT;
    if (xDir == RIGHT && yDir == UP)
        *finalDir = TOPRIGHT;
    if (xDir == LEFT && yDir == DOWN)
        *finalDir = BOTTOMLEFT;
    if (xDir == RIGHT && yDir == DOWN)
        *finalDir = BOTTOMRIGHT;

    if (xDir == STAY && yDir == STAY) {
        if (btnX > widgetWidth / 2 && btnY < widgetHeight / 2) {
            if (btnY + 2 * btnHeight + trickyOffset < widgetHeight) {
                *finalDir = DOWN;
            } else {
                if (btnX - btnWidth - trickyOffset > widgetX) {
                    *finalDir = LEFT;
                }
            }
        } else {

            if (btnX > widgetWidth / 2 && btnY > widgetHeight / 2) {
                if (btnX - btnWidth - trickyOffset > widgetX) {
                    *finalDir = LEFT;
                } else {
                    if (btnY - btnHeight - trickyOffset > widgetY) {
                        *finalDir = UP;
                    } else {
                        if (btnX + 2 * btnWidth + trickyOffset < widgetWidth) {
                            *finalDir = RIGHT;
                        }
                    }
                }
            } else {

                if (btnX < widgetWidth / 2 && btnY > widgetHeight / 2) {
                    if (btnY - btnHeight - trickyOffset > widgetY) {
                        *finalDir = UP;
                    } else {
                        if (btnX + 2 * btnWidth + trickyOffset < widgetWidth) {
                            *finalDir = RIGHT;
                        }
                    }
                } else {

                    if (btnX < widgetWidth / 2 && btnY < widgetHeight / 2) {
                        if (btnX + 2 * btnWidth + trickyOffset < widgetWidth) {
                            *finalDir = RIGHT;
                        } else {
                            if (btnY + 2 * btnHeight + trickyOffset < widgetHeight) {
                                *finalDir = DOWN;
                            } else{
                                if (btnY - btnHeight - trickyOffset > widgetY) {
                                    *finalDir = UP;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void WidgetWithButton::moveAway()
{
    QPoint p = this->mapFromGlobal(QCursor::pos());

    int x = p.x();
    int y = p.y();

    int btnX = ui->pushButton->x();
    int btnY = ui->pushButton->y();

    int rx = x - btnX;
    int ry = y - btnY;

    direction xDir = STAY;
    direction yDir = STAY;

    direction* resDirect = new direction[2];
    chooseDirSimple(rx, ry, btnX, btnY, resDirect);
    xDir = resDirect[0];
    yDir = resDirect[1];
    delete(resDirect);

    direction* finalDir = new direction;
    chooseDestination(xDir, yDir, btnX, btnY, finalDir);

    int* res = new int[2];
    moveToDir(btnX, btnY, *finalDir, res);
    delete(finalDir);
    ui->pushButton->move(res[0], res[1]);
    delete(res);
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
