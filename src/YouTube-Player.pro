#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T11:50:11
#
#-------------------------------------------------



QT       += core gui
QT       += webenginewidgets
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YouTube-Player
TEMPLATE = app


SOURCES += main.cpp\
    webview.cpp \
    dialog.cpp \
    playlist.cpp

HEADERS  += \
    webview.h \
    dialog.h \
    playlist.h

FORMS    += \
    dialog.ui \
    playlist.ui

RESOURCES += \
    myresources.qrc
