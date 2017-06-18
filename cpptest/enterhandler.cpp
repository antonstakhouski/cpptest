#include "enterhandler.h"
#include "movewidget.h"

#include <QPoint>
#include <QCursor>

#include <iostream>

using namespace std;

EnterHandler::EnterHandler(): trickyOffset(10)
{

}

void EnterHandler::moveAway(const QPoint _cursorPos, const QRect _widgetRect, const QRect _btnRect, QPoint *res)
{
    cursorPos = _cursorPos;
    btnRect = _btnRect;
    widgetRect = _widgetRect;

    direction* resDir2d = new direction[2];
    chooseDirSimple(resDir2d);

    direction* finalDir = new direction;
    chooseDestination(resDir2d, finalDir);

    moveToDir(*finalDir, res);

    delete[] resDir2d;
    delete finalDir;
}

void EnterHandler::chooseDirSimple(direction *resDir2d)
{
    int rx = cursorPos.x() - btnRect.x();
    int ry = cursorPos.y() - btnRect.y();

    cout << "rx:"  << endl;
    cout << rx << endl;
    cout << ry << endl << endl;

    // test X axis
    if (rx <= btnRect.width() / 2){
        if (btnRect.x() + (2 * btnRect.width()) + trickyOffset >= widgetRect.width()) {
            resDir2d[0] = STAY;
        } else {
            resDir2d[0] = RIGHT;
        }
    } else {
        if (btnRect.x() - btnRect.width() - trickyOffset <= widgetRect.x()) {
            resDir2d[0] = STAY;
        } else {
            resDir2d[0] = LEFT;
        }
    }

    // test Y axis
    if(ry <= btnRect.height() / 2) {
        if (btnRect.y() + 2 * btnRect.height() + trickyOffset >= widgetRect.height()) {
            resDir2d[1] = STAY;
        } else {
            resDir2d[1] = DOWN;
        }
    } else {
        if (btnRect.y() - 2 * btnRect.height() - trickyOffset <= widgetRect.y()) {
            resDir2d[1] = STAY;
        } else {
            resDir2d[1] = UP;
        }
    }

    cout << "res: " <<endl;
    cout << resDir2d[0] << endl;
    cout << resDir2d[1] << endl;
}

void EnterHandler::chooseDestination(const direction* resDir2d, direction* finalDir)
{
    *finalDir = STAY;

    //move Ortho
    if (resDir2d[0] == LEFT && resDir2d[1] == STAY )
        *finalDir = LEFT;
    if (resDir2d[0] == RIGHT && resDir2d[1] == STAY )
        *finalDir = RIGHT;
    if (resDir2d[0] == STAY && resDir2d[1] == UP)
        *finalDir = UP ;
    if (resDir2d[0] == STAY && resDir2d[1] == DOWN)
        *finalDir = DOWN;

    //move Diag
    if (resDir2d[0] == LEFT && resDir2d[1] == UP)
        *finalDir = TOPLEFT;
    if (resDir2d[0] == RIGHT && resDir2d[1] == UP)
        *finalDir = TOPRIGHT;
    if (resDir2d[0] == LEFT && resDir2d[1] == DOWN)
        *finalDir = BOTTOMLEFT;
    if (resDir2d[0] == RIGHT && resDir2d[1] == DOWN)
        *finalDir = BOTTOMRIGHT;

    if (resDir2d[0] == STAY && resDir2d[1] == STAY) {
        if (btnRect.x() > widgetRect.width() / 2 && btnRect.y() < widgetRect.height() / 2) {
            topRight(finalDir);
        } else {
            if (btnRect.x() > widgetRect.width() / 2 && btnRect.y() > widgetRect.height() / 2) {
                bottomRight(finalDir);
            } else {
                if (btnRect.x() < widgetRect.width() / 2 && btnRect.y() > widgetRect.height() / 2) {
                    bottomLeft(finalDir);
                } else {
                    if (btnRect.x() < widgetRect.width() / 2 && btnRect.y() < widgetRect.height() / 2) {
                        topLeft(finalDir);
                    }
                }
            }
        }
    }
}

void EnterHandler::topRight(direction* finalDir)
{
    if (btnRect.y() + 2 * btnRect.height() + trickyOffset < widgetRect.height()) {
        *finalDir = DOWN;
    } else {
        if (btnRect.x() - btnRect.width() - trickyOffset > widgetRect.x()) {
            *finalDir = LEFT;
        }
    }
}

void EnterHandler::bottomRight(direction* finalDir)
{
    if (btnRect.x() - btnRect.width() - trickyOffset > widgetRect.x()) {
        *finalDir = LEFT;
    } else {
        if (btnRect.y() - btnRect.height() - trickyOffset > widgetRect.y()) {
            *finalDir = UP;
        } else {
            if (btnRect.x() + 2 * btnRect.width() + trickyOffset < widgetRect.width()) {
                *finalDir = RIGHT;
            }
        }
    }
}

void EnterHandler::bottomLeft(direction* finalDir)
{
    if (btnRect.y() - btnRect.height() - trickyOffset > widgetRect.y()) {
        *finalDir = UP;
    } else {
        if (btnRect.x() + 2 * btnRect.width() + trickyOffset < widgetRect.width()) {
            *finalDir = RIGHT;
        }
    }
}

void EnterHandler::topLeft(direction* finalDir)
{
    if (btnRect.x() + 2 * btnRect.width() + trickyOffset < widgetRect.width()) {
        *finalDir = RIGHT;
    } else {
        if (btnRect.y() + 2 * btnRect.height() + trickyOffset < widgetRect.height()) {
            *finalDir = DOWN;
        } else{
            if (btnRect.y() - btnRect.height() - trickyOffset > widgetRect.y()) {
                *finalDir = UP;
            }
        }
    }
}

void EnterHandler::moveToDir(const direction finalDir, QPoint* res)
{
    switch (finalDir) {
    case LEFT:
        moveLeft(btnRect, res, trickyOffset);
        break;
    case RIGHT:
        moveRight(btnRect, res, trickyOffset);
        break;
    case UP:
        moveUp(btnRect, res, trickyOffset);
        break;
    case DOWN:
        moveDown(btnRect, res, trickyOffset);
        break;
    case TOPLEFT:
        moveTopLeft(btnRect, res, trickyOffset);
        break;
    case TOPRIGHT:
        moveTopRight(btnRect, res, trickyOffset);
        break;
    case BOTTOMLEFT:
        moveBottomLeft(btnRect, res, trickyOffset);
        break;
    case BOTTOMRIGHT:
        moveBottomRight(btnRect, res, trickyOffset);
        break;
    default:
        moveNull(btnRect, res);
        break;
    }
}
