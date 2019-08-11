HEADERS += \
    qfl_analog_clock.h \
    qfl_global.h \
    qfl_meter.h

SOURCES += \
    qfl_analog_clock.cpp \
    qfl_meter.cpp \
    qfl_meter_draw_functions.cpp

greaterThan(QT_MAJOR_VERSION, 4) {

    QT += printsupport
    QT += concurrent
} 
