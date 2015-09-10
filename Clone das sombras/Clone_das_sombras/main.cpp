#include "clone_das_sombras.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clone_das_Sombras w;
    w.show();

    return a.exec();
}
