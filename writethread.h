#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QThread>

class WriteThread : public QThread
{
    Q_OBJECT
public:
    explicit WriteThread(QObject *parent = 0);

protected:
    void run();
};

#endif // WRITETHREAD_H
