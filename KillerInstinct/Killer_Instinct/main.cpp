#include "killer_instinct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Killer_Instinct w;
    w.show();

    return a.exec();
}
