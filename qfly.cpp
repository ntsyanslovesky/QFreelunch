#include "qfly.h"
#include "ui_qfly.h"

QFly::QFly(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFly)
{
    ui->setupUi(this);

    m_cstSpeedPanel = new CstmSpeedPanel(this);
    m_cstSpeedPanel->move(10,30);
}

QFly::~QFly()
{
    delete ui;
}
