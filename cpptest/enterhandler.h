#ifndef ENTERHANDLER_H
#define ENTERHANDLER_H

#include <QPoint>
#include <QRect>

enum direction { STAY, LEFT, RIGHT, UP, DOWN, BOTTOMLEFT, BOTTOMRIGHT, TOPLEFT, TOPRIGHT};

class EnterHandler
{
public:
    EnterHandler();
    void moveAway(const QPoint _cursorPos, const QRect _widgetRect, const QRect _btnRect, QPoint* res);

private:
    QPoint cursorPos;
    QRect btnRect;
    QRect widgetRect;

    void chooseDirSimple(direction* resDir2d);
    void chooseDestination(const direction* resDir2d, direction *finalDir);
    void moveToDir(const direction finalDir, QPoint* res);

    void topRight(direction* finalDir);
    void bottomRight(direction* finalDir);
    void bottomLeft(direction* finalDir);
    void topLeft(direction* finalDir);
};

#endif // ENTERHANDLER_H
