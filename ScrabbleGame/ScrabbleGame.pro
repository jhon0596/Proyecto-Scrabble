#-------------------------------------------------
#
# Project created by QtCreator 2019-03-23T16:05:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScrabbleGame
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
    button.cpp \
    board.cpp \
    game.cpp \
    BoxScrabble.cpp \
    listafichas.cpp \
    node.cpp

HEADERS  += \
    button.h \
    board.h \
    game.h \
    BoxScrabble.h \
    listafichas.h \
    node.h

FORMS    +=

INCLUDEPATH += /usr/include/boost

LIBS += -L/usr/include/boost-lboost_system

DISTFILES +=

RESOURCES += \
    imagenes.qrc
