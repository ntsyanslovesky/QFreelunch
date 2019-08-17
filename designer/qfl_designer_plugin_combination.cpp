#include "qfl_designer_plugin_combination.h"
#include "qfl_designer_analog_clock_interface.h"

#include "qfl_designer_analog_clock_interface.h"
#include "qfl_designer_meter_interface.h"
#include "qfl_designer_needle_indicator_interface.h"
#include "qfl_designer_pot_interface.h"

namespace QflDesignerPlugin {
CustomWidgetCollectionInterface::CustomWidgetCollectionInterface(
    QObject *parent) {
  Q_UNUSED(parent);
  d_plugins.append(new AnalogClockInterface(this));
  d_plugins.append(new MeterInterface(this));
  d_plugins.append(new PotInterface(this));
  d_plugins.append(new NeedleIndicatorInterface(this));
}

QList<QDesignerCustomWidgetInterface *>
CustomWidgetCollectionInterface::customWidgets() const {
  return d_plugins;
}
}  // namespace QflDesignerPlugin
