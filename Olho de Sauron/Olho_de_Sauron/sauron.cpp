#include "sauron.h"
#include "ui_sauron.h"

Sauron::Sauron(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sauron)
{
    ui->setupUi(this);
}

Sauron::~Sauron()
{
    delete ui;
}
