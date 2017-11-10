#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T19:48:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeometriaComputacional
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    poligonos.cpp \
    arcos.cpp \
    cubo.cpp \
    prismarec.cpp \
    prismatri.cpp \
    cono.cpp \
    transformaciones.cpp

HEADERS  += dialog.h \
    poligonos.h \
    arcos.h \
    cubo.h \
    prismarec.h \
    prismatri.h \
    cono.h \
    transformaciones.h

FORMS    += dialog.ui \
    poligonos.ui \
    arcos.ui \
    cubo.ui \
    prismarec.ui \
    prismatri.ui \
    cono.ui

CONFIG-=app_bundle
