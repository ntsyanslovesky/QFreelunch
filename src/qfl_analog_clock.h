#pragma once

#include "qfl_global.h"
#include <QWidget>

class QFL_EXPORT QflAnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit QflAnalogClock(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};