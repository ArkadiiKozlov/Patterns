TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Logger.cpp \
    LoggerImpl.cpp \
    Composite1.cpp

DISTFILES += \
    Bridge \
    Makefile

HEADERS += \
    LoggerImpl.h \
    Logger.h \
    Composite1.h \
    Warriorfactory.h

