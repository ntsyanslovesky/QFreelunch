#pragma once
#include "qfl_designer_plugin_combination.h"


#include <QDesignerCustomWidgetInterface>
#include <QtDesigner/QDesignerTaskMenuExtension>
#include <QtDesigner/QExtensionFactory>

namespace QflDesignerPlugin {
class CustomWidgetCollectionInterface
            : public QObject,
            public QDesignerCustomWidgetCollectionInterface 
    {
        Q_OBJECT
        Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

        #if QT_VERSION >= 0x050000
        Q_PLUGIN_METADATA(
            IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
        #endif

        public:
            CustomWidgetCollectionInterface(QObject *parent = NULL);

        virtual QList<QDesignerCustomWidgetInterface *> customWidgets() const;

        private:
        QList<QDesignerCustomWidgetInterface *> d_plugins;
    };
}
