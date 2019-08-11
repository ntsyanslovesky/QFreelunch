#pragma once

#include <QDesignerCustomWidgetInterface>
#include <QtDesigner/QDesignerTaskMenuExtension>
#include <QtDesigner/QExtensionFactory>

namespace QflDesignerPlugin
{
class TaskMenuFactory : public QExtensionFactory {
    Q_OBJECT

public:
    TaskMenuFactory(QExtensionManager *parent = 0);

protected:
    QObject *createExtension(QObject *object, const QString &iid,
                             QObject *parent) const;
};

class TaskMenuExtension : public QObject, public QDesignerTaskMenuExtension {
    Q_OBJECT
    Q_INTERFACES(QDesignerTaskMenuExtension)

public:
    TaskMenuExtension(QWidget *widget, QObject *parent);

    QAction *preferredEditAction() const;
    QList<QAction *> taskActions() const;

private Q_SLOTS:
    void editProperties();
    void applyProperties(const QString &);

private:
    QAction *d_editAction;
    QWidget *d_widget;
};

    // 作为父类，被子类(自定义控件的接口类)继承
    class CustomWidgetInterface : public QObject, public QDesignerCustomWidgetInterface
    {
        Q_OBJECT
        Q_INTERFACES(QDesignerCustomWidgetInterface)
    public:
        CustomWidgetInterface(QObject *parent);

        virtual bool isContainer() const;
        virtual bool isInitialized() const;
        virtual QIcon icon() const;
        virtual QString codeTemplate() const;
        virtual QString domXml() const;
        virtual QString group() const;
        virtual QString includeFile() const;
        virtual QString name() const;
        virtual QString toolTip() const;
        virtual QString whatsThis() const;
        virtual void initialize(QDesignerFormEditorInterface *);

    protected:
        QString d_name;
        QString d_include;
        QString d_toolTip;
        QString d_whatsThis;
        QString d_domXml;
        QString d_codeTemplate;
        QIcon d_icon;

        private:
            bool d_isInitialized;
    };
}



 
