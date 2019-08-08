#ifndef QFLY_H
#define QFLY_H

#include <QWidget>
#include "CstmBattery.h"
#include "CstmSpeedPanel.h"

namespace Ui {
class QFly;
}

class QFly : public QWidget
{
    Q_OBJECT

public:
    explicit QFly(QWidget *parent = nullptr);
    ~QFly();

private:
    Ui::QFly *ui;
    CstmBattery * m_cstmBattery;
    CstmSpeedPanel * m_cstSpeedPanel;
};

#endif // QFLY_H
