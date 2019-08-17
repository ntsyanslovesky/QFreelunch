#include "qfl_designer_needle_indicator_interface.h"

#include "../src/qfl_needle_indicator.h"

NeedleIndicatorInterface::NeedleIndicatorInterface(QObject *parent)
    : CustomWidgetInterface(parent) {
  d_name = "QflNeedleIndicator";
  d_include = "qfl_needle_indicator.h";

  // d_icon = QPixmap(":/pixmaps/qwtwidget.png");
  d_domXml =
      "<widget class=\"QflNeedleIndicator\" name=\"qflNeedleIndicator\">\n"
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

QWidget *NeedleIndicatorInterface::createWidget(QWidget *parent) {
  return new QflNeedleIndicator(parent);
}
