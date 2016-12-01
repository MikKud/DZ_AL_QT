#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T14:31:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DZ_AL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Acceptor.cpp \
    Factor.cpp \
    server.cpp \
    Service.cpp \
    calchistory.cpp \
    binom.cpp

HEADERS  += mainwindow.h \
    Acceptor.h \
    Factor.h \
    server.h \
    Service.h \
    calchistory.h \
    binom.h

LIBS += -L"/usr/local/lib" -lgmp -lgmpxx -lboost_system


INCLUDEPATH += /usr/local/include


FORMS    += mainwindow.ui \
    calchistory.ui

DISTFILES += \
    DZ_AL.pro.user
