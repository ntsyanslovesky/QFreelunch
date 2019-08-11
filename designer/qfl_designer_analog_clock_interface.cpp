#include "qfl_designer_analog_clock_interface.h"

#include "../src/qfl_analog_clock.h"

AnalogClockInterface::AnalogClockInterface(QObject *parent)
    : CustomWidgetInterface(parent) {
  d_name = "QflAnalogClock";
  d_include = "qfl_analog_clock.h";

 // d_icon = QPixmap(":/pixmaps/qwtwidget.png");
  d_domXml =
      "<widget class=\"QflAnalogClock\" name=\"qflAnalogClock\">\n"
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

QWidget *AnalogClockInterface::createWidget(QWidget *parent) {
  return new QflAnalogClock(parent);
}
