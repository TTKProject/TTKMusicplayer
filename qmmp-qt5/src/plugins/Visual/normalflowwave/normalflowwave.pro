include($$PWD/../../plugins.pri)
include($$PWD/../common/common.pri)

DESTDIR = $$PLUGINS_PREFIX/Visual
TARGET = normalflowwave

HEADERS += normalflowwave.h \
           visualnormalflowwavefactory.h

SOURCES += normalflowwave.cpp \
           visualnormalflowwavefactory.cpp

unix{
    QMAKE_CLEAN = libnormalflowwave.so
    target.path = $$LIB_DIR/qmmp/Visual
    INSTALLS += target
}
