#include "x_infinity.h"
#include "ui_x_infinity.h"
#include "QDir"
#include "QTextStream"
#include "QDirIterator"
#include "QFile"
#include <iostream>
#include <QDoubleValidator>


X_Infinity::X_Infinity(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::X_Infinity)
{
    ui->setupUi(this);
    intervalo = new QTimer(this);
    connect(intervalo, SIGNAL(timeout()), this, SLOT(atualizarProcessos()));
    intervalo->start(1000);
    atualizarProcessos();

    QDoubleValidator *double_validator = new QDoubleValidator(this);
    ui->lineEdit->setValidator(double_validator);
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


    QString pid, nome, status;

    QDir proc("/proc");

    QStringList processos;
    processos = proc.entryList(QDir::Dirs, QDir::Unsorted);

    int i = processos.indexOf("1");
    int iFiltro = 0;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setRowCount(processos.length() - i);
    while(i < processos.length())
    {
       // qDebug() << processos.at(i);

        QFile file("/proc/"+processos.at(i)+"/status");

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        QString line = in.readLine();
        QTextStream str(&line);
        str >> nome >> nome;

        line = in.readLine();
        QTextStream str1(&line);
        str1 >> status >> status >> status;

        line = in.readLine();
        line = in.readLine();

        line = in.readLine();

        QTextStream str2(&line);

        str2 >> pid >> pid;

        QTableWidgetItem *item = new QTableWidgetItem(pid);

        if(nome.contains(&filtro)){
            ui->tableWidget->setItem(iFiltro, 0, item);
            item = new QTableWidgetItem(nome);
            ui->tableWidget->setItem(iFiltro, 1, item);
            item = new QTableWidgetItem(status);
            ui->tableWidget->setItem(iFiltro, 2, item);
            iFiltro++;
        }
        i++;
    }



}




void X_Infinity::on_btnFiltro_clicked()
{
    filtro = ui->lineEdit_2->text();
}
