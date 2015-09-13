#include "sauron.h"
#include "ui_sauron.h"
#include "QFile"
#include "QTextStream"

Sauron::Sauron(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Sauron)
{
    ui->setupUi(this);

    //Set do tempo 0
    int a, b, c, d, e, f, g, h, i, j;
    QString cpuname;
    QFile file("/proc/stat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    QString line =in.readLine();

    QTextStream str(&line);

    //cpu1

        line = in.readLine();

        str >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
        total_passado[0] = a + b + c + d + e + f + g + i + j;
        work_passado[0] = a + b + c;



   //cpu2


        line = in.readLine();

        str >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
        total_passado[1] = a + b + c + d + e + f + g + i + j;
        work_passado[1] = a + b + c;




    //cpu3


         line = in.readLine();

         str >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
         total_passado[2] = a + b + c + d + e + f + g + i + j;
         work_passado[2] = a + b + c;


     //cpu4


          line = in.readLine();

          str >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
          total_passado[3] = a + b + c + d + e + f + g + i + j;
          work_passado[3] = a + b + c;


    //Setup do timer

    t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(atualizar_cpu_sched()));
    t->start(1000);

    ui->pbar1->setValue(0);
    ui->pbar2->setValue(0);
    ui->pbar3->setValue(0);
    ui->pbar4->setValue(0);

}

Sauron::~Sauron()
{
    delete ui;
}

void Sauron::atualizar_cpu_sched(){


    int total_tempo[4];
    int work_tempo[4];

    int a, b, c, d, e, f, g, h, i, j;
    QString cpuname;
    QFile file("/proc/stat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    QString line =in.readLine();



     QTextStream str(&line);
    //cpu1

        line = in.readLine();
        //str >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
        str >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
        total_tempo[0] = a + b + c + d + e + f + g + i + j;
        work_tempo[0] = a + b + c;

        ui->pbar1->setValue(((float)(work_tempo[0] - work_passado[0])/(total_tempo[0] - total_passado[0]))*100);
        work_passado[0] = work_tempo[0];
        total_passado[0] = total_tempo[0];

   //cpu2


        line = in.readLine();


        QTextStream str1(&line);

        str1 >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
        total_tempo[1] = a + b + c + d + e + f + g + i + j;
        work_tempo[1] = a + b + c;

        ui->pbar2->setValue((float)(work_tempo[1] - work_passado[1])/(total_tempo[1] - total_passado[1])*100);
        work_passado[1] = work_tempo[1];
        total_passado[1] = total_tempo[1];


    //cpu3


         line = in.readLine();

         QTextStream str2(&line);
         str2 >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
         total_tempo[2] = a + b + c + d + e + f + g + i + j;
         work_tempo[2] = a + b + c;

         ui->pbar3->setValue((float)(work_tempo[2] - work_passado[2])/(total_tempo[2] - total_passado[2])*100);
         work_passado[2] = work_tempo[2];
         total_passado[2] = total_tempo[2];

     //cpu4


          line = in.readLine();

          QTextStream str3(&line);

          str3 >> cpuname >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
          total_tempo[3] = a + b + c + d + e + f + g + i + j;
          work_tempo[3] = a + b + c;

          ui->pbar4->setValue((float)(work_tempo[3] - work_passado[3])/(total_tempo[3] - total_passado[3])*100);
          work_passado[3] = work_tempo[3];
          total_passado[3] = total_tempo[3];

}
