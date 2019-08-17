
# 项目配置
CONFIG      += plugin qt
TEMPLATE    =  lib
QT          += widgets uiplugin  designer core gui
TARGET      =  qfl_designer_plugin
DESTDIR     =  plugins/designer

QMAKE_CXXFLAGS_WARN_ON += -wd4819

# 路径设置
YFLY_ROOT = $${PWD}/..
YFLY_OUT_ROOT = $${OUT_PWD}/..

# 二进制文件输出路径

# 表示只会编译出release版本
CONFIG( debug_and_release ) {
    message("Info: building the FLY designer plugin in release mode only")

    CONFIG -= debug_and_release
    CONFIG += release
}

# 组件实现源文件所在路径
#INCLUDEPATH    += $${YFLY_ROOT}/src 
#DEPENDPATH     += $${YFLY_ROOT}/src 

# 编译实现源文件
include ( $${YFLY_ROOT}/src/src.pri )

for( header, HEADERS) {
    YFLY_HEADERS += $${YFLY_ROOT}/src/$${header}
}

for( source, SOURCES ) {
    YFLY_SOURCES += $${YFLY_ROOT}/src/$${source}
}

HEADERS = $${YFLY_HEADERS}
SOURCES = $${YFLY_SOURCES}

HEADERS +=qfl_designer_plugin_combination.h \
           qfl_designer_plugin_general.h  \
           qfl_designer_analog_clock_interface.h \
           qfl_designer_meter_interface.h \
           qfl_designer_pot_interface.h \
           qfl_designer_needle_indicator_interface.h


SOURCES += qfl_designer_plugin_combination.cpp \
           qfl_designer_plugin_general.cpp   \
           qfl_designer_analog_clock_interface.cpp \
           qfl_designer_meter_interface.cpp \
           qfl_designer_pot_interface.cpp \
           qfl_designer_needle_indicator_interface.cpp
