#ifndef READTHREAD_H
#define READTHREAD_H

#include <QThread>

class QImage;

class ReadThread : public QThread
{
    Q_OBJECT
public:
    explicit ReadThread(QObject *parent = 0);

protected:
    void run();

private:
    QImage *m_pImage;
};

#endif // READTHREAD_H
