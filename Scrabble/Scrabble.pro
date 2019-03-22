#-------------------------------------------------
#
# Project created by QtCreator 2019-03-20T16:44:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scrabble
TEMPLATE = app

SOURCES += main.cpp\
        scrabble.cpp \
    listafichas.cpp \
    node.cpp

HEADERS  += scrabble.h \
    listafichas.h \
    node.h

FORMS    += scrabble.ui
