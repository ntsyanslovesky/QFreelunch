#include "qfl_designer_pot_interface.h"

#include "../src/qfl_pot.h"

PotInterface::PotInterface(QObject *parent) : CustomWidgetInterface(parent) {
  d_name = "QflPot";
  d_include = "qfl_pot.h";

  // d_icon = QPixmap(":/pixmaps/qwtwidget.png");
  d_domXml =
      "<widget class=\"QflPot\" name=\"qflPot\">\n"
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

QWidget *PotInterface::createWidget(QWidget *parent) {
  return new QflPot(parent);
}
