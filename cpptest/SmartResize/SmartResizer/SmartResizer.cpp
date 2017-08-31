#include "SmartResizer.h"

SmartResizer::SmartResizer(QObject *parent) : QObject(parent), m_lock(false), m_handleWidget(Q_NULLPTR), m_startResize(0,0)
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
        }
    }
    return QObject::eventFilter(watched,event);
}
