#include "SmartResizer.h"

SmartResizer::SmartResizer(QObject *parent) : QObject(parent), m_handleWidget(Q_NULLPTR), m_lock(false), m_startResize(0,0)
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
        if(event->type()==QEvent::Resize) {

            QResizeEvent * e = reinterpret_cast<QResizeEvent*>(event);

            int oldHeight = e->oldSize().height();
            int oldWidth= e->oldSize().width();

            int newHeight = e->size().height();
            int newWidth= e->size().width();

            qDebug() << "OldRatio: " << (float)oldWidth / oldHeight;
            qDebug() << "NewRatio: " << (float)newWidth / newHeight;

            if (oldWidth * newHeight > newWidth * oldHeight)
                const_cast<QSize&>(e->size()) = QSize(newWidth, (newWidth * oldHeight) / oldWidth);
            else
                const_cast<QSize&>(e->size()) = QSize((newHeight * oldWidth) / oldHeight, newHeight);
            qDebug() << "SmartResizeRatio: " << (float)e->size().width() / e->size().height();
        }
    }
    return QObject::eventFilter(watched,event);
}
