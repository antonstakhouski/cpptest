#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H

#include <QRect>

void moveLeft(const QRect btnRect, QPoint* res, int trickyOffset);
void moveRight(const QRect btnRect, QPoint* res, int trickyOffset);
void moveUp(const QRect btnRect, QPoint* res, int trickyOffset);
void moveDown(const QRect btnRect, QPoint* res, int trickyOffset);
void moveTopRight(const QRect btnRect, QPoint* res, int trickyOffset);
void moveTopLeft(const QRect btnRect, QPoint* res, int trickyOffset);
void moveBottomRight(const QRect btnRect, QPoint* res, int trickyOffset);
void moveBottomLeft(const QRect btnRect, QPoint* res, int trickyOffset);
void moveNull(const QRect btnRect, QPoint* res);

#endif // MOVEWIDGET_H
