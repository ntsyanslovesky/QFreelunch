#pragma once
#include "qfl_designer_plugin_general.h"
#include "qfl_designer_plugin_combination.h"

#include <QDesignerCustomWidgetInterface>
#include <QtDesigner/QDesignerTaskMenuExtension>
#include <QtDesigner/QExtensionFactory>

using namespace QflDesignerPlugin;

class MeterInterface : public CustomWidgetInterface {
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    MeterInterface(QObject *parent);
    virtual QWidget *createWidget(QWidget *parent);
};
