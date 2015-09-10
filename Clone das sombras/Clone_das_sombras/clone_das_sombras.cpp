#include "clone_das_sombras.h"
#include "ui_clone_das_sombras.h"
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include<QThread>

Clone_das_Sombras::Clone_das_Sombras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clone_das_Sombras)
{
    ui->setupUi(this);

    pidPai = getppid();
    pid = getpid();

    pthread_attr_t *atributo;
    pthread_attr_init(atributo);

    pthread_t *atualizar;


    pthread_create(atualizar, atributo, atualizarPIDS, NULL);

    //atualizarPIDS();
}

Clone_das_Sombras::~Clone_das_Sombras()
{
    delete ui;
}

void Clone_das_Sombras::on_buttonClonar_clicked()
{
    fork();
//    atualizarPIDS();
}

void Clone_das_Sombras::on_buttonMorrer_clicked()
{
    kill(getpid(), SIGKILL);
}

void *Clone_das_Sombras::atualizarPIDS(void *param){

    while(1){
        ui->labelPai->setText(QString("PID (Pai): %1").arg((int) pidPai));
        ui->labelPid->setText(QString("PID: %1").arg((int) pid));

        sleep(1);
    }
}


