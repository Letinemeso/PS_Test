TEMPLATE = lib
CONFIG += staticlib
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Basic_Geometry.cpp \
	Basic_Shapes.cpp

HEADERS += \
	Basic_Geometry.h \
	Basic_Shapes.h
