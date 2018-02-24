#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T22:49:24
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET = tst_lenstest
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += c++1z
QMAKE_CXXFLAGS += -nostdinc++

INCLUDEPATH += /usr/include/x86_64-linux-gnu/c++/7
INCLUDEPATH += /usr/include/c++/7

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
    account.h \
    presentation.h


# lenses targets

win32:      CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cpp_lenses/release/ -lcpp_lenses
else:win32: CONFIG(debug, debug|release):   LIBS += -L$$OUT_PWD/../cpp_lenses/debug/   -lcpp_lenses
else:unix:                                  LIBS += -L$$OUT_PWD/../cpp_lenses/         -lcpp_lenses

INCLUDEPATH += $$PWD/../cpp_lenses
DEPENDPATH  += $$PWD/../cpp_lenses

win32-g++:              CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cpp_lenses/release/libcpp_lenses.a
else:win32-g++:         CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../cpp_lenses/debug/libcpp_lenses.a
else:win32:!win32-g++:  CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cpp_lenses/release/cpp_lenses.lib
else:win32:!win32-g++:  CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../cpp_lenses/debug/cpp_lenses.lib
else:unix:                                              PRE_TARGETDEPS += $$OUT_PWD/../cpp_lenses/libcpp_lenses.a

# functional core targets

win32:      CONFIG(release, debug|release):    LIBS += -L$$OUT_PWD/../../cpp_functional_core/cpp_functional_core/release/ -lcpp_functional_core
else:win32: CONFIG(debug, debug|release):      LIBS += -L$$OUT_PWD/../../cpp_functional_core/cpp_functional_core/debug/   -lcpp_functional_core
else:unix:                                     LIBS += -L$$OUT_PWD/../../cpp_functional_core/cpp_functional_core/         -lcpp_functional_core

INCLUDEPATH += $$PWD/../../cpp_functional_core/cpp_functional_core
DEPENDPATH  += $$PWD/../../cpp_functional_core/cpp_functional_core

win32-g++:             CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../cpp_functional_core/cpp_functional_core/release/libcpp_functional_core.a
else:win32-g++:        CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../../cpp_functional_core/cpp_functional_core/debug/libcpp_functional_core.a
else:win32:!win32-g++: CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../cpp_functional_core/cpp_functional_core/release/cpp_functional_core.lib
else:win32:!win32-g++: CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../../cpp_functional_core/cpp_functional_core/debug/cpp_functional_core.lib
else:unix:                                             PRE_TARGETDEPS += $$OUT_PWD/../../cpp_functional_core/cpp_functional_core/libcpp_functional_core.a
