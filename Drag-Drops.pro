#-------------------------------------------------
#
# Project created by QtCreator 2012-09-14T20:27:29
#
#-------------------------------------------------

QT       += core gui
QT += declarative

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drag-Drops
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    TreeWidgetComponent.cpp \
    WidgetEdit.cpp

HEADERS  += Widget.h \
    TreeWidgetComponent.h \
    WidgetEdit.h

FORMS    += Widget.ui

OTHER_FILES += \
    QML_Edit.qml \
    QML_Item.qml
