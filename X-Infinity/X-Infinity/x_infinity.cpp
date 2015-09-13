#include "x_infinity.h"
#include "ui_x_infinity.h"


X_Infinity::X_Infinity(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::X_Infinity)
{
    ui->setupUi(this);
    intervalo = new QTimer(this);
    connect(intervalo, SIGNAL(timeout()), this, SLOT(atualizarProcessos()));
    intervalo->start(1000);
}

X_Infinity::~X_Infinity()
{
    delete ui;
}

void X_Infinity::on_btnTime_clicked()
{
    intervalo->setInterval(ui->lineEdit->text().toInt()*1000);

}

void X_Infinity::atualizarProcessos(){


}
