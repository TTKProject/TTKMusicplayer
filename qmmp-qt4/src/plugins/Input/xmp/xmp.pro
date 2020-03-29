include($$PWD/../../plugins.pri)

HEADERS += decoderxmpfactory.h \
           decoder_xmp.h \
           xmpmetadatamodel.h

SOURCES += decoder_xmp.cpp \
           decoderxmpfactory.cpp \
           xmpmetadatamodel.cpp

DESTDIR = $$PLUGINS_PREFIX/Input
TARGET = xmp

INCLUDEPATH += $$EXTRA_PREFIX/libxmp/include

unix:{
    QMAKE_CLEAN = $$DESTDIR/libxmp.so
    LIBS += -L$$EXTRA_PREFIX/libxmp/lib -lxmp$$STATIC_LIBRARY_SUFFIX
}

win32:{
    LIBS += -L$$EXTRA_PREFIX/libxmp/lib -lxmp_dll
}