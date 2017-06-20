#include "movewidget.h"

void moveLeft(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x() - (2 * btnRect.width()));
    res->setY(btnRect.y());
}

void moveRight(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x() + (2 * btnRect.width()));
    res->setY(btnRect.y());
}

void moveUp(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y() - (2 * btnRect.height()));
}

void moveDown(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y() + (2 * btnRect.height()));
}

void moveTopRight(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x() + (2 * btnRect.width()));
    res->setY(btnRect.y() - (2 * btnRect.height()));
}

void moveTopLeft(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x() - (2 * btnRect.width()));
    res->setY(btnRect.y() - (2 * btnRect.height()));
}

void moveBottomRight(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x() + (2 * btnRect.width()));
    res->setY(btnRect.y() + (2 * btnRect.height()));
}

void moveBottomLeft(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x() - (2 * btnRect.width()));
    res->setY(btnRect.y() - (2 * btnRect.height()));
}

void moveNull(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y());
}
