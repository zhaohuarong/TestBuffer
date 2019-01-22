#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

#include <QObject>
#include <QMutex>
#include <QList>

class QImage;

#define IMAGE_BUFF_MAX_COUNT 250
#define g_pImageBuffer ImageBuffer::instance()

class ImageBuffer : public QObject
{
    Q_OBJECT

public:
    static ImageBuffer *instance();
    void push(const QImage *pImg);
    bool pull(QImage **pImg);

private:
    ImageBuffer();

private:
    static ImageBuffer *m_pInstance;
    QList<char *> m_lstBuffer;
    QMutex m_lock;
};

#endif // IMAGEBUFFER_H
