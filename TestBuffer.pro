QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestBuffer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        mainwindow.cpp \
    imagebuffer.cpp \
    readthread.cpp \
    writethread.cpp

HEADERS  += mainwindow.h \
    imagebuffer.h \
    readthread.h \
    writethread.h

FORMS    += mainwindow.ui
