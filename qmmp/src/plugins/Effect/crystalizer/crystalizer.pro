include($$PWD/../../plugins.pri)

DESTDIR = $$PLUGINS_PREFIX/Effect

HEADERS += crystalizerplugin.h \
           effectcrystalizerfactory.h \
           settingsdialog.h

SOURCES += crystalizerplugin.cpp \
           effectcrystalizerfactory.cpp \
           settingsdialog.cpp

FORMS += settingsdialog.ui

unix{
    QMAKE_CLEAN = $$DESTDIR/lib$${TARGET}.so
}