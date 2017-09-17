#include "nwt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Nwt w;
    w.show();

    return a.exec();
}
