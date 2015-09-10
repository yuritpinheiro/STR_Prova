#include "killer_instinct.h"
#include "ui_killer_instinct.h"
#include <signal.h>
#include <unistd.h>
#include <QIntValidator>

Killer_Instinct::Killer_Instinct(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Killer_Instinct)
{
    ui->setupUi(this);
    QIntValidator *int_validator = new QIntValidator(this);
    ui->lineEdit->setValidator(int_validator);
}

Killer_Instinct::~Killer_Instinct()
{
    delete ui;
}

void Killer_Instinct::on_buttonOK_clicked()
{
    if(ui->radioParar->isChecked())
        kill(ui->lineEdit->text().toInt(), SIGSTOP);
    if(ui->radioContinuar->isChecked())
        kill(ui->lineEdit->text().toInt(), SIGCONT);
    if(ui->radioMatar->isChecked())
        kill(ui->lineEdit->text().toInt(), SIGKILL);
}
