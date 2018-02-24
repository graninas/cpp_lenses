#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T22:56:58
#
#-------------------------------------------------

QT -= core gui

TARGET = cpp_lenses
TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++1z
QMAKE_CXXFLAGS += -nostdinc++

INCLUDEPATH += /usr/include/x86_64-linux-gnu/c++/7
INCLUDEPATH += /usr/include/c++/7

SOURCES +=

HEADERS += \
    lenses.h \
    autolens.h \
    fold.h \
    setter.h \
    getter.h \
    lens_stack.h \
    lens.h \
    bind_combinator.h \
    to_combinator.h \
    traversed.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
