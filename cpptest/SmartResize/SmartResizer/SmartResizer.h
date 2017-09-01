#ifndef SMARTRESIZER_H
#define SMARTRESIZER_H

#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QEvent>
#include <QSize>
#include <QResizeEvent>
#include <QDebug>

class SmartResizer : public QObject
{
    Q_OBJECT
public:
    explicit SmartResizer(QObject *parent = 0);
    void installWidget(QWidget *widg);
public slots:
    void lockResolution(bool lock);
protected:
    bool eventFilter(QObject *watched, QEvent *event);
private:
    QWidget* m_handleWidget;
    bool m_lock;
    QSize m_startResize;
};

#endif // SMARTRESIZER_H
