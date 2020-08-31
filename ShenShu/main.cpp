#include "ShenShu.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShenShu w;
    w.show();
    return a.exec();
}
