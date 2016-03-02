# lenses targets

win32:       CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/release/ -lcpp_lenses
else:win32:  CONFIG(debug, debug|release):   LIBS += -L$$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/debug/   -lcpp_lenses
else:unix:                                   LIBS += -L$$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/         -lcpp_lenses

INCLUDEPATH += $$PWD/../../lib/cpp_lenses/cpp_lenses
DEPENDPATH  += $$PWD/../../lib/cpp_lenses/cpp_lenses

win32-g++:             CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/release/libcpp_lenses.a
else:win32-g++:        CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/debug/libcpp_lenses.a
else:win32:!win32-g++: CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/release/cpp_lenses.lib
else:win32:!win32-g++: CONFIG(debug, debug|release):   PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/debug/cpp_lenses.lib
else:unix:                                             PRE_TARGETDEPS += $$OUT_PWD/../../lib/cpp_lenses/cpp_lenses/libcpp_lenses.a
