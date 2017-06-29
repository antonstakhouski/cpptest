#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H

#include <QRect>

void moveLeft(const QRect btnRect, QPoint* res);
void moveRight(const QRect btnRect, QPoint* res);
void moveUp(const QRect btnRect, QPoint* res);
void moveDown(const QRect btnRect, QPoint* res);
void moveTopRight(const QRect btnRect, QPoint* res);
void moveTopLeft(const QRect btnRect, QPoint* res);
void moveBottomRight(const QRect btnRect, QPoint* res);
void moveBottomLeft(const QRect btnRect, QPoint* res);
void moveNull(const QRect btnRect, QPoint* res);

#endif // MOVEWIDGET_H
