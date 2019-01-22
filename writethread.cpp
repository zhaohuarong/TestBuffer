#include <QImage>
#include "imagebuffer.h"
#include "writethread.h"

WriteThread::WriteThread(QObject *parent) :
    QThread(parent)
{
}

void WriteThread::run()
{
    uint i = 0;
    while(1)
    {
        QImage *pImg = new QImage(1000, 1400, QImage::Format_RGB32);
        if(g_pImageBuffer->pull(&pImg))
        {
            pImg->save(QString("D:/sss/%1.bmp").arg(i ++));
        }
        msleep(150);
        delete pImg;
    }
}
