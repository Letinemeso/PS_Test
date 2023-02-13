TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
	"../Basic_Geometry/Build/libPS_Test.a"

SOURCES += \
	main.cpp

INCLUDEPATH += \
	"../Basic_Geometry/"

