include($$PWD/../../plugins.pri)
include($$PWD/../common/common.pri)

DESTDIR = $$PLUGINS_PREFIX/Visual
TARGET = normalanalyzer

HEADERS += normalanalyzer.h \
           visualnormalanalyzerfactory.h
           
SOURCES += normalanalyzer.cpp \
           visualnormalanalyzerfactory.cpp

unix{
    QMAKE_CLEAN = libnormalanalyzer.so
    target.path = $$LIB_DIR/qmmp/Visual
    INSTALLS += target
}
