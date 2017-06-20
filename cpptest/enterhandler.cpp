#include "enterhandler.h"
#include "movewidget.h"

#include <QPoint>
#include <QCursor>

EnterHandler::EnterHandler()
{

}

void EnterHandler::moveAway(const QPoint _cursorPos, const QRect _widgetRect,
                            const QRect _btnRect, QPoint *res)
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
    if (btnRect.x() - (2 * btnRect.width()) >= widgetRect.x())
        resDir2d[0] = LEFT;
    else
        resDir2d[0] = RIGHT;

    // test Y axis
    if (btnRect.y() - (4 * btnRect.height()) >= widgetRect.y())
        resDir2d[1] = UP;
    else
        resDir2d[1] = DOWN;
}

void EnterHandler::chooseDestination(const direction* resDir2d, direction* finalDir)
{
    *finalDir = STAY;

    //move Diag
    if (resDir2d[0] == LEFT && resDir2d[1] == UP)
        *finalDir = TOPLEFT;
    if (resDir2d[0] == RIGHT && resDir2d[1] == UP)
        *finalDir = TOPRIGHT;
    if (resDir2d[0] == LEFT && resDir2d[1] == DOWN)
        *finalDir = BOTTOMLEFT;
    if (resDir2d[0] == RIGHT && resDir2d[1] == DOWN)
        *finalDir = BOTTOMRIGHT;
}

void EnterHandler::moveToDir(const direction finalDir, QPoint* res)
{
    switch (finalDir) {
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
