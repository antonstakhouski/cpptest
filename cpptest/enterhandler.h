#ifndef ENTERHANDLER_H
#define ENTERHANDLER_H

#include <QPoint>
#include <QRect>

enum direction { STAY, LEFT, RIGHT, UP, DOWN, BOTTOMLEFT, BOTTOMRIGHT, TOPLEFT, TOPRIGHT};

class EnterHandler
{
public:
    EnterHandler();
    void moveAway(const QRect& _widgetRect, const QRect& _btnRect, QPoint* res);

private:
    QRect btnRect;
    QRect widgetRect;

    void chooseDirSimple(direction* resDir2d);
    void chooseDestination(const direction* resDir2d, direction *finalDir);
    void moveToDir(const direction& finalDir, QPoint* res);
};

#endif // ENTERHANDLER_H
