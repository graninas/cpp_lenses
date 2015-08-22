#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T22:49:24
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_lenstesttest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += \
    tst_lens.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    person.h \
    address.h \
    common.h \
    struct_lenses.h \
    car.h \
    account.h

OTHER_FILES += \
    conf_materials.txt
