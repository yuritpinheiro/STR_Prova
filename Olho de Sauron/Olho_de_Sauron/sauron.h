#ifndef SAURON_H
#define SAURON_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class Sauron;
}

class Sauron : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sauron(QWidget *parent = 0);
    ~Sauron();
private slots:
    void atualizar_cpu_sched();

private:
    Ui::Sauron *ui;
    QTimer* t;
    int total_passado[4];
    int work_passado[4];
};

#endif // SAURON_H
