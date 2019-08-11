#include "qfl_designer_meter_interface.h"

#include "../src/qfl_meter.h"

MeterInterface::MeterInterface(QObject *parent)
    : CustomWidgetInterface(parent) {
    d_name = "QMeter";
    d_include = "qfl_meter_clock.h";

    // d_icon = QPixmap(":/pixmaps/qwtwidget.png");
    d_domXml =
        "<widget class=\"QMeter\" name=\"qmeter\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>20</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QWidget *MeterInterface::createWidget(QWidget *parent) {
    return new QMeter(parent);
}
