#-------------------------------------------------
#
# Project created by QtCreator 2017-05-06T17:19:23
#
#-------------------------------------------------

QT       += core gui
CONFIG   += debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpptest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += *.cpp \
    containers/arrayTest.cpp \
    containers/containerTest.cpp \
    containers/dequeTest.cpp \
    containers/forward_listTest.cpp \
    containers/listTest.cpp \
    containers/mapTest.cpp \
    containers/queueTest.cpp \
    containers/setTest.cpp \
    containers/stackTest.cpp \
    containers/unordered_mapTest.cpp \
    containers/unordered_setTest.cpp \
    containers/vectorTest.cpp

HEADERS  += *.h \
    containers/arrayTest.h \
    containers/containerTest.h \
    containers/dequeTest.h \
    containers/forward_listTest.h \
    containers/listTest.h \
    containers/mapTest.h \
    containers/queueTest.h \
    containers/setTest.h \
    containers/stackTest.h \
    containers/testResults.h \
    containers/unordered_mapTest.h \
    containers/unordered_setTest.h \
    containers/vectorTest.h

FORMS    += \
    WidgetWithButton.ui \
    containerform.ui
