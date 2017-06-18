#include "movewidget.h"


void moveLeft(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() - btnRect.width() - trickyOffset);
    res->setY(btnRect.y());
}

void moveRight(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() + btnRect.width() + trickyOffset);
    res->setY(btnRect.y());
}

void moveUp(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y() - btnRect.height() - trickyOffset);
}

void moveDown(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y() + btnRect.height() + trickyOffset);
}

void moveTopRight(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() + btnRect.width() + trickyOffset);
    res->setY(btnRect.y() - btnRect.height() - trickyOffset);
}

void moveTopLeft(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() - btnRect.width() - trickyOffset);
    res->setY(btnRect.y() - btnRect.height() - trickyOffset);
}

void moveBottomRight(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() + btnRect.width() + trickyOffset);
    res->setY(btnRect.y() + btnRect.height() + trickyOffset);
}

void moveBottomLeft(const QRect btnRect, QPoint* res, int trickyOffset)
{
    res->setX(btnRect.x() - btnRect.width() - trickyOffset);
    res->setY(btnRect.y() + btnRect.height() + trickyOffset);
}

void moveNull(const QRect btnRect, QPoint* res)
{
    res->setX(btnRect.x());
    res->setY(btnRect.y());
}
