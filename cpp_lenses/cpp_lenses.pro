#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T22:56:58
#
#-------------------------------------------------

QT -= core gui

TARGET = cpp_lenses
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

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
