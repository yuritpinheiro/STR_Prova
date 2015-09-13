#include "x_infinity.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    X_Infinity w;
    w.show();

    return a.exec();
}
