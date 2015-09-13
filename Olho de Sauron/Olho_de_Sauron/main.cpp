#include "sauron.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sauron w;
    w.show();

    return a.exec();
}
