#include <QImage>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readthread.h"
#include "writethread.h"

#include "imagebuffer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QImage *pImage = new QImage("C:/Users/zhaohr/Desktop/1.bmp");
//    for(int i = 0; i < 1000; i ++)
//    {
//        g_pImageBuffer->push(pImage);
//    }
    ReadThread *pReader = new ReadThread();
    WriteThread *pWriter = new WriteThread();

    pReader->start();
    pWriter->start();

//    pReader->set

    /*
    for(int i = 0; i < 1000; i ++)
    {
        pBuffer->push(pImage);
    }
    */
/*
    for(int i = 0; i < 100; i ++)
    {
        QImage *pImg = new QImage(*pImage);

        pBuffer->pull(&pImg);

        delete pImg;
    }
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}
