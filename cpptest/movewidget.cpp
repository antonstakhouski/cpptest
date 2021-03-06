#include "movewidget.h"

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
    res->setY(btnRect.y() + (2 * btnRect.height()));
}

void moveNull(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y());
}
