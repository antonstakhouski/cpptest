#include "movewidget.h"


void moveLeft(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() - btnRect.width() - trickyOffset);
    res->setY(btnRect.y() - btnRect.height());
}

void moveRight(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() + btnRect.width() + trickyOffset);
    res->setY(btnRect.y() - btnRect.height());
}

void moveUp(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y() - 2 * btnRect.height() - trickyOffset);
}

void moveDown(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y() + btnRect.height() + trickyOffset);
}

void moveTopRight(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() + btnRect.width() + trickyOffset);
    res->setY(btnRect.y() - 2 * btnRect.height());
}

void moveTopLeft(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() - btnRect.width() - trickyOffset);
    res->setY(btnRect.y() - 2 * btnRect.height());
}

void moveBottomRight(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() + btnRect.width() + trickyOffset);
    res->setY(btnRect.y());
}

void moveBottomLeft(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() - btnRect.width() + trickyOffset);
    res->setY(btnRect.y());
}

void moveNull(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y());
}
