#include "SmartResizer.h"

SmartResizer::SmartResizer(QObject *parent) : QObject(parent), m_handleWidget(Q_NULLPTR), m_lock(false), m_startResize(0,0), eventBlocked(false)
{

}

void SmartResizer::installWidget(QWidget *widg)
{
    widg->installEventFilter(this);
    m_handleWidget = widg;
}

void SmartResizer::lockResolution(bool lock)
{
    if(!m_handleWidget)
        return;

    m_lock = lock;
    m_startResize = m_handleWidget->size();
}

bool SmartResizer::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_handleWidget)
    {
        if((event->type() == QEvent::Resize) && m_lock) {

//            if (eventBlocked) {
//                event->ignore();
//                return QObject::eventFilter(watched,event);
//            }

            QResizeEvent * e = reinterpret_cast<QResizeEvent*>(event);

            int oldHeight = m_startResize.height();
            int oldWidth= m_startResize.width();

            int newHeight = e->size().height();
            int newWidth= e->size().width();

            qDebug() << "OldRatio: " << (float)oldWidth / oldHeight;
            qDebug() << "NewRatio: " << (float)newWidth / newHeight;

            eventBlocked = true;
            if ((oldWidth * newHeight) > (newWidth * oldHeight))
                qDebug()<< QSize(newWidth, (newWidth * oldHeight) / oldWidth);
            else
                 qDebug()<< QSize((newHeight * oldWidth) / oldHeight, newHeight);
            qDebug() << "SmartResizeRatio: " << (float)e->size().width() / e->size().height();

            eventBlocked = false;
        }
    }
    return QObject::eventFilter(watched,event);
}
