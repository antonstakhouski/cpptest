#include "SmartResizer.h"
#include <cstdlib>

SmartResizer::SmartResizer(QObject *parent) : QObject(parent), m_handleWidget(Q_NULLPTR), m_lock(false), m_startResize(0,0), eventBlocked(false)
{

}

void SmartResizer::installWidget(QWidget *widg)
{
    widg->installEventFilter(this);
    m_handleWidget = widg;
//    m_handleWidget->setMouseTracking(true);
}

void SmartResizer::lockResolution(bool lock)
{
    if(!m_handleWidget)
        return;

    m_lock = lock;

    m_startResize = m_handleWidget->size();
    m_handleWidget->setFixedSize(m_handleWidget->size());
}

bool SmartResizer::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == m_handleWidget)
    {
        if((event->type() == QEvent::Resize) && m_lock) {

            QResizeEvent* e = reinterpret_cast<QResizeEvent*>(event);

            float ratio = (float) m_startResize.width() / m_startResize.height();

            QSize maxToW(e->size().width(), e->size().width() / ratio);
            QSize maxToH(e->size().height() * ratio, e->size().height());

            qDebug() << e->oldSize();
            qDebug() << e->size();

            eventBlocked = true;
            if (abs(e->size().width() - e->oldSize().width()) >= abs(e->size().height() - e->oldSize().height()))
                qDebug() << "To W" << maxToW << (float)maxToW.width() / maxToW.height();
            else
                qDebug() << "To H" << maxToH << (float)maxToH.width() / maxToH.height();

            eventBlocked = false;
        }
    }

//    if (event->type() == QEvent::MouseButtonPress) {
//        qDebug() << "Btn pressed";
//    }

//    if (event->type() == QEvent::MouseMove) {
//        QMouseEvent* e = reinterpret_cast<QMouseEvent*>(event);
//        qDebug() << "Hello";
//        qDebug() << e->pos();
//    }
    return QObject::eventFilter(watched,event);
}
