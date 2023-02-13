TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += \
	"../../Basic_Geometry/Build/libBasic_Geometry.a" \
	"../../../Utility/Build/libUtility.a" \
	"../../../L_Variable/Build/libL_Variable.a" \

SOURCES += \
	main.cpp

INCLUDEPATH += \
	"../Basic_Geometry/" \
	"../../L_Variable/include" \
	"../../Utility/include"

