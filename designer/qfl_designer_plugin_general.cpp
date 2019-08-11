#if defined(_MSC_VER) /* MSVC Compiler */
#pragma warning(disable : 4786)
#endif

#include <qaction.h>
#include <qglobal.h>
#include <QDesignerFormEditorInterface>
#include <QDesignerFormWindowCursorInterface>
#include <QDesignerFormWindowInterface>
#include <QErrorMessage>
#include <QExtensionManager>
#include <QtPlugin>

#include "qfl_designer_plugin_general.h"

using namespace QflDesignerPlugin;

TaskMenuFactory::TaskMenuFactory(QExtensionManager *parent)
    : QExtensionFactory(parent) {}

QObject *TaskMenuFactory::createExtension(QObject *object, const QString &iid,
                                          QObject *parent) const {
    if (iid == Q_TYPEID(QDesignerTaskMenuExtension)) {
    }

    return QExtensionFactory::createExtension(object, iid, parent);
}

TaskMenuExtension::TaskMenuExtension(QWidget *widget, QObject *parent)
    : QObject(parent), d_widget(widget) {
    d_editAction = new QAction(tr("Edit YFly Attributes ..."), this);
    connect(d_editAction, SIGNAL(triggered()), this, SLOT(editProperties()));
}

QList<QAction *> TaskMenuExtension::taskActions() const {
    QList<QAction *> list;
    list.append(d_editAction);
    return list;
}

QAction *TaskMenuExtension::preferredEditAction() const { return d_editAction; }

void TaskMenuExtension::editProperties() {
    const QVariant v = d_widget->property("propertiesDocument");
    if (v.type() != QVariant::String) return;

    static QErrorMessage *errorMessage = NULL;
    if (errorMessage == NULL) errorMessage = new QErrorMessage();
    errorMessage->showMessage("Not implemented yet.");
}

void TaskMenuExtension::applyProperties(const QString &properties) {
    QDesignerFormWindowInterface *formWindow =
        QDesignerFormWindowInterface::findFormWindow(d_widget);
    if (formWindow && formWindow->cursor())
        formWindow->cursor()->setProperty("propertiesDocument", properties);
}


CustomWidgetInterface::CustomWidgetInterface(QObject *parent)
    : QObject(parent), d_isInitialized(false) {}

bool CustomWidgetInterface::isContainer() const { return false; }

bool CustomWidgetInterface::isInitialized() const { return d_isInitialized; }

QIcon CustomWidgetInterface::icon() const { return d_icon; }

QString CustomWidgetInterface::codeTemplate() const { return d_codeTemplate; }

QString CustomWidgetInterface::domXml() const { return d_domXml; }

QString CustomWidgetInterface::group() const { return "QFreeLunch Widgets"; }

QString CustomWidgetInterface::includeFile() const { return d_include; }

QString CustomWidgetInterface::name() const { return d_name; }

QString CustomWidgetInterface::toolTip() const { return d_toolTip; }

QString CustomWidgetInterface::whatsThis() const { return d_whatsThis; }

void CustomWidgetInterface::initialize(
    QDesignerFormEditorInterface *formEditor) {
  if (d_isInitialized) return;

  QExtensionManager *manager = formEditor->extensionManager();
  if (manager) {
    manager->registerExtensions(new TaskMenuFactory(manager),
                                Q_TYPEID(QDesignerTaskMenuExtension));
  }

  d_isInitialized = true;
}
