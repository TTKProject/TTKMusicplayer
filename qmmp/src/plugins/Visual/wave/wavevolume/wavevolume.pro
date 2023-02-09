include($$PWD/../../Visual.pri)

DESTDIR = $$PLUGINS_PREFIX/Visual

HEADERS += wavevolume.h \
           visualwavevolumefactory.h
           
SOURCES += wavevolume.cpp \
           visualwavevolumefactory.cpp

unix{
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
}