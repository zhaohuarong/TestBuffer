#include <QImage>
#include <QDebug>

#include "imagebuffer.h"

ImageBuffer *ImageBuffer::m_pInstance = NULL;

ImageBuffer::ImageBuffer() :
    QObject()
{
}

ImageBuffer *ImageBuffer::instance()
{
    if(m_pInstance == NULL)
        m_pInstance = new ImageBuffer();
    return m_pInstance;
}

void ImageBuffer::push(const QImage *pImg)
{
    if(m_lstBuffer.count() > IMAGE_BUFF_MAX_COUNT)
    {
        qDebug() << "IMAGE_BUFF_MAX_COUNT";
        return;
    }

    m_lock.lock();
    char *p = (char *)malloc(pImg->byteCount());
    if(p != NULL)
    {
        memcpy(p, pImg->bits(), pImg->byteCount());
        m_lstBuffer.append(p);
    }
    m_lock.unlock();

    qDebug() << "+++++" << m_lstBuffer.count();
}

bool ImageBuffer::pull(QImage **pImg)
{
    if(*pImg == NULL)
    {
        qDebug() << "NULL Image";
        return false;
    }

    if(m_lstBuffer.count() <= 0)
    {
        qDebug() << "Buffer is empty";
        return false;
    }

//    if((*pImg)->byteCount() != m_lstBuffer[0]->byteCount())
//    {
//        qDebug() << "size is not same";
//        return false;
//    }

    m_lock.lock();
    memcpy((*pImg)->bits(), m_lstBuffer[0], (*pImg)->byteCount());
    free(m_lstBuffer[0]);
    m_lstBuffer.removeAt(0);
    m_lock.unlock();
    qDebug() << "-----" << m_lstBuffer.count();
    return true;
}
