#include "clone_das_sombras.h"
#include "ui_clone_das_sombras.h"

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <QTimer>

Clone_das_Sombras::Clone_das_Sombras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clone_das_Sombras)
{
    ui->setupUi(this);

    pidPai = getppid();
    pid = getpid();

    ui->labelPai->setText(QString("PID Pai: %1").arg(getppid()));
    ui->labelPid->setText(QString("PID: %1").arg(getpid()));

    QTimer *t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(atualizar_pid()));
    t->start(1000);
}

Clone_das_Sombras::~Clone_das_Sombras()
{
    delete ui;
}

void Clone_das_Sombras::on_buttonClonar_clicked()
{
    pogama = new QProcess(this);
    pogama->start("./Clone_das_sombras");
}

void Clone_das_Sombras::on_buttonMorrer_clicked()
{
    kill(getpid(), SIGKILL);
}

void Clone_das_Sombras::atualizar_pid()
{
    ui->labelPai->setText(QString("PID Pai: %1").arg(getppid()));
    ui->labelPid->setText(QString("PID: %1").arg(getpid()));
}
