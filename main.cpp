#include "qfly.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFly w;
    w.show();

    return a.exec();
}
