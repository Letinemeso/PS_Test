TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
	"../../Basic_Geometry/Build/libBasic_Geometry.a" \
	"../../Utility/Build/libUtility.a" \
	"../../L_Variable/Build/libL_Variable.a" \
	"../../googletest/Build/lib/libgtest.a" \

LIBS += -pthread

SOURCES += \
	main.cpp
/home/develop/Desktop/PST/PS_Test/
INCLUDEPATH += \
	"../Basic_Geometry/" \
	"../L_Variable/include" \
	"../Utility/include" \
	"../googletest/googletest/include/" \

