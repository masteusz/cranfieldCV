#-------------------------------------------------
#
# Project created by QtCreator 2013-05-04T20:54:09
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleFramework
TEMPLATE = app

CONFIG += link_pkgconfig
PKGCONFIG += opencv

SOURCES += main.cpp\
        mainwidget.cpp \
    opencvgl.cpp \
    frameshow.cpp

HEADERS  += mainwidget.h \
    opencvgl.h \
    frameshow.h
