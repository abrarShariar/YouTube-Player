#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T11:50:11
#
#-------------------------------------------------



QT       += core gui
QT       += webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YouTube-Player
TEMPLATE = app


SOURCES += main.cpp\
    webview.cpp \
    dialog.cpp

HEADERS  += \
    webview.h \
    dialog.h

FORMS    += \
    dialog.ui

RESOURCES += \
    myresources.qrc
