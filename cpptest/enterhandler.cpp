#include "enterhandler.h"
#include "movewidget.h"

#include <QPoint>
#include <QCursor>

EnterHandler::EnterHandler()
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
    // test X axis
    if (btnRect.x() + (3 * btnRect.width()) >= widgetRect.width()) {
        if (!btnRect.x() - btnRect.width() >= widgetRect.x())
            resDir2d[0] = LEFT;
        else
            resDir2d[0] = STAY;
    } else {
        resDir2d[0] = RIGHT;
    }

    // test Y axis
    if (btnRect.y() + (3 * btnRect.height()) >= widgetRect.height()) {
        if (!btnRect.y() - btnRect.height() >= widgetRect.y())
            resDir2d[1] = UP;
        else
            resDir2d[1] = STAY;
    } else {
        resDir2d[1] = DOWN;
    }
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
    if (btnRect.y() + (2 * btnRect.height()) < widgetRect.height()) {
        *finalDir = DOWN;
    } else {
        if (btnRect.x() - btnRect.width() > widgetRect.x()) {
            *finalDir = LEFT;
        }
    }
}

void EnterHandler::bottomRight(direction* finalDir)
{
    if (btnRect.x() - btnRect.width() > widgetRect.x()) {
        *finalDir = LEFT;
    } else {
        if (btnRect.y() - btnRect.height() > widgetRect.y()) {
            *finalDir = UP;
        } else {
            if (btnRect.x() + 2 * btnRect.width() < widgetRect.width()) {
                *finalDir = RIGHT;
            }
        }
    }
}

void EnterHandler::bottomLeft(direction* finalDir)
{
    if (btnRect.y() - btnRect.height() > widgetRect.y()) {
        *finalDir = UP;
    } else {
        if (btnRect.x() + 2 * btnRect.width() < widgetRect.width()) {
            *finalDir = RIGHT;
        }
    }
}

void EnterHandler::topLeft(direction* finalDir)
{
    if (btnRect.x() + 2 * btnRect.width() < widgetRect.width()) {
        *finalDir = RIGHT;
    } else {
        if (btnRect.y() + 2 * btnRect.height() < widgetRect.height()) {
            *finalDir = DOWN;
        } else{
            if (btnRect.y() - btnRect.height() > widgetRect.y()) {
                *finalDir = UP;
            }
        }
    }
}

void EnterHandler::moveToDir(const direction finalDir, QPoint* res)
{
    switch (finalDir) {
    case LEFT:
        moveLeft(btnRect, res);
        break;
    case RIGHT:
        moveRight(btnRect, res);
        break;
    case UP:
        moveUp(btnRect, res);
        break;
    case DOWN:
        moveDown(btnRect, res);
        break;
    case TOPLEFT:
        moveTopLeft(btnRect, res);
        break;
    case TOPRIGHT:
        moveTopRight(btnRect, res);
        break;
    case BOTTOMLEFT:
        moveBottomLeft(btnRect, res);
        break;
    case BOTTOMRIGHT:
        moveBottomRight(btnRect, res);
        break;
    default:
        moveNull(btnRect, res);
        break;
    }
}
