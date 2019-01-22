#include <QImage>

#include "readthread.h"
#include "imagebuffer.h"

ReadThread::ReadThread(QObject *parent) :
    QThread(parent)
{
    m_pImage = new QImage("C:/Users/zhaohr/Desktop/1.bmp");
}

void ReadThread::run()
{
    while(1)
    {
        g_pImageBuffer->push(m_pImage);
        msleep(100);
    }
}
