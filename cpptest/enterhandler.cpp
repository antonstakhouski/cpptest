#include "enterhandler.h"
#include "movewidget.h"

#include <QPoint>
#include <QCursor>

EnterHandler::EnterHandler(): trickyOffset(10)
{

}

void EnterHandler::moveToDir(int btnX, int btnY, direction finalDir, int* res)
{
    MoveLeft moveLeft = MoveLeft(btnWidth, btnHeight, trickyOffset);
    MoveRight moveRight(btnWidth, btnHeight, trickyOffset);
    MoveUp moveUp(btnWidth, btnHeight, trickyOffset);
    MoveDown moveDown(btnWidth, btnHeight, trickyOffset);
    MoveTopLeft moveTopLeft(btnWidth, btnHeight, trickyOffset);
    MoveTopRight moveTopRight(btnWidth, btnHeight, trickyOffset);
    MoveBottomLeft moveBottomLeft(btnWidth, btnHeight, trickyOffset);
    MoveBottomRight moveBottomRight(btnWidth, btnHeight, trickyOffset);
    MoveNull moveNull(btnWidth, btnHeight, trickyOffset);

    switch (finalDir) {
    case LEFT:
        moveLeft.move(btnX, btnY, res);
        break;
    case RIGHT:
        moveRight.move(btnX, btnY, res);
        break;
    case UP:
        moveUp.move(btnX, btnY, res);
        break;
    case DOWN:
        moveDown.move(btnX, btnY, res);
        break;
    case TOPLEFT:
        moveTopLeft.move(btnX, btnY, res);
        break;
    case TOPRIGHT:
        moveTopRight.move(btnX, btnY, res);
        break;
    case BOTTOMLEFT:
        moveBottomLeft.move(btnX, btnY, res);
        break;
    case BOTTOMRIGHT:
        moveBottomRight.move(btnX, btnY, res);
        break;
    default:
        moveNull.move(btnX, btnY, res);
        break;
    }
}

void EnterHandler::testXaxis(direction* xDir, int rx, int btnX)
{
    if (rx <= btnWidth / 2){
        if (btnX + 2 * btnWidth + trickyOffset >= widgetWidth) {
            *xDir = STAY;
        } else {
            *xDir = RIGHT;
        }
    } else {
        if (btnX - btnWidth  - trickyOffset <= widgetX) {
            *xDir = STAY;
        } else {
            *xDir = LEFT;
        }
    }
}

void EnterHandler::testYaxis(int ry, direction* yDir, int btnY)
{
    if(ry <= btnHeight / 2) {
        if (btnY + 2 * btnHeight  + trickyOffset >= widgetHeight){
            *yDir = STAY;
        } else {
            *yDir = DOWN;
        }
    } else {
        if (btnY - btnHeight  - trickyOffset <= widgetY) {
            *yDir = STAY;
        } else {
            *yDir = UP;
        }
    }
}

void EnterHandler::chooseDirSimple(int rx, int ry, int btnX, int btnY, direction* resDirect)
{
    direction xDir;
    direction yDir;
    testXaxis(&xDir, rx, btnX);
    testYaxis(ry, &yDir, btnY);

    resDirect[0] = xDir;
    resDirect[1] = yDir;
}

void EnterHandler::topRight(int btnY, direction* finalDir, int btnX)
{
    if (btnY + 2 * btnHeight + trickyOffset < widgetHeight) {
        *finalDir = DOWN;
    } else {
        if (btnX - btnWidth - trickyOffset > widgetX) {
            *finalDir = LEFT;
        }
    }
}

void EnterHandler::bottomRight(int btnX, direction* finalDir, int btnY)
{
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
}

void EnterHandler::bottomLeft(direction* finalDir, int btnX, int btnY)
{
    if (btnY - btnHeight - trickyOffset > widgetY) {
        *finalDir = UP;
    } else {
        if (btnX + 2 * btnWidth + trickyOffset < widgetWidth) {
            *finalDir = RIGHT;
        }
    }
}

void EnterHandler::topLeft(int btnX, int btnY, direction* finalDir)
{
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

void EnterHandler::moveOrtho(direction* finalDir, direction xDir, direction yDir)
{
    if (xDir == LEFT && yDir == STAY )
        *finalDir = LEFT;
    if (xDir == RIGHT && yDir == STAY )
        *finalDir = RIGHT;
    if (xDir == STAY && yDir == UP)
        *finalDir = UP ;
    if (xDir == STAY && yDir == DOWN)
        *finalDir = DOWN;
}

void EnterHandler::moveDiag(direction* finalDir, direction yDir, direction xDir)
{
    if (xDir == LEFT && yDir == UP)
        *finalDir = TOPLEFT;
    if (xDir == RIGHT && yDir == UP)
        *finalDir = TOPRIGHT;
    if (xDir == LEFT && yDir == DOWN)
        *finalDir = BOTTOMLEFT;
    if (xDir == RIGHT && yDir == DOWN)
        *finalDir = BOTTOMRIGHT;
}

void EnterHandler::moveCorner(int btnX, direction xDir, int btnY, direction* finalDir, direction yDir)
{
    if (xDir == STAY && yDir == STAY) {
        if (btnX > widgetWidth / 2 && btnY < widgetHeight / 2) {
            topRight(btnY, finalDir, btnX);
        } else {
            if (btnX > widgetWidth / 2 && btnY > widgetHeight / 2) {
                bottomRight(btnX, finalDir, btnY);
            } else {
                if (btnX < widgetWidth / 2 && btnY > widgetHeight / 2) {
                    bottomLeft(finalDir, btnX, btnY);
                } else {
                    if (btnX < widgetWidth / 2 && btnY < widgetHeight / 2) {
                        topLeft(btnX, btnY, finalDir);
                    }
                }
            }
        }
    }
}

void EnterHandler::chooseDestination(direction xDir, direction yDir,
                                         int btnX, int btnY, direction* finalDir)
{
    *finalDir = STAY;
    moveOrtho(finalDir, xDir, yDir);
    moveDiag(finalDir, yDir, xDir);
    moveCorner(btnX, xDir, btnY, finalDir, yDir);
}

void EnterHandler::moveAway(int x, int y,
                            int _btnX, int _btnY, int _btnWidth , int _btnHeight,
                            int _widgetX, int _widgetY, int _widgetWidth , int _widgetHeight,
                            int* _res)
{
    btnX = _btnX;
    btnY = _btnY;
    btnWidth = _btnWidth;
    btnHeight = _btnHeight;
    widgetHeight = _widgetHeight;
    widgetWidth = _widgetWidth;
    widgetX = _widgetX;
    widgetY = _widgetY;
    widgetWidth = _widgetWidth;
    widgetHeight = _widgetHeight;

    int rx = x - btnX;
    int ry = y - btnY;

    direction xDir = STAY;
    direction yDir = STAY;

    direction* resDirect = new direction[2];
    chooseDirSimple(rx, ry, btnX, btnY, resDirect);
    xDir = resDirect[0];
    yDir = resDirect[1];

    direction* finalDir = new direction;
    chooseDestination(xDir, yDir, btnX, btnY, finalDir);

    int* res = new int[2];
    moveToDir(btnX, btnY, *finalDir, res);
    _res[0] = res[0];
    _res[1] = res[1];

    delete resDirect;
    delete res;
    delete finalDir;
}
