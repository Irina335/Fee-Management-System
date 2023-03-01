#-------------------------------------------------
#
# Project created by QtCreator 2022-10-17T21:01:40
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ges_ecolage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    student.cpp \
    menu.cpp \
    paiement.cpp \
    fee.cpp

HEADERS  += mainwindow.h \
    student.h \
    menu.h \
    conn.h \
    paiement.h \
    fee.h

FORMS    += mainwindow.ui \
    student.ui \
    menu.ui \
    paiement.ui \
    fee.ui

RESOURCES += \
    ../icon/img.qrc
