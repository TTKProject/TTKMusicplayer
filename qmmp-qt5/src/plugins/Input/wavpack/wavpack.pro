include($$PWD/../../plugins.pri)

HEADERS += decoderwavpackfactory.h \
           decoder_wavpack.h \
           cueparser.h \
           wavpackmetadatamodel.h
    
SOURCES += decoder_wavpack.cpp \
           decoderwavpackfactory.cpp \
           cueparser.cpp \
           wavpackmetadatamodel.cpp

DESTDIR = $$PLUGINS_PREFIX/Input
TARGET = wavpack

INCLUDEPATH += $$EXTRA_PREFIX/libwavpack/include

unix {
    unix:android {
        TARGET = plugin_input_wavpack
        QMAKE_CLEAN = libplugin_input_wavpack.so
        target.path = $$LIB_DIR
    }else{
        QMAKE_CLEAN = libwavpack.so
        target.path = $$LIB_DIR/qmmp/Input
    }
    INSTALLS += target
    LIBS += -L$$EXTRA_PREFIX/libwavpack/lib -lwavpack$$STATIC_LIBRARY_SUFFIX
}

win32 {
    LIBS += -L$$EXTRA_PREFIX/libwavpack/lib -lwavpack
}
