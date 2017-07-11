#-------------------------------------------------
#
# Project created by QtCreator 2017-07-08T13:40:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game1
TEMPLATE = app


SOURCES += main.cpp \
    gamewindow.cpp \
    gobject.cpp \
    gprojectile.cpp \
    gturret.cpp \
    genemy.cpp

HEADERS  += \
    gamewindow.h \
    gobject.h \
    gprojectile.h \
    gturret.h \
    genemy.h

FORMS    +=

# CONFIG += console

RESOURCES += \
    resource.qrc
