HEADERS += \
    qfl_analog_clock.h \
    qfl_global.h \
    qfl_meter.h \
    qfl_pot.h  \
    qfl_needle_indicator.h

SOURCES += \
    qfl_analog_clock.cpp \
    qfl_meter.cpp \
    qfl_meter_draw_functions.cpp \
    qfl_pot.cpp \
    qfl_needle_indicator.cpp

greaterThan(QT_MAJOR_VERSION, 4) {

    QT += printsupport
    QT += concurrent
} 
