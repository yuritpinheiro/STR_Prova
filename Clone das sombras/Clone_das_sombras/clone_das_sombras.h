#ifndef CLONE_DAS_SOMBRAS_H
#define CLONE_DAS_SOMBRAS_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class Clone_das_Sombras;
}

class Clone_das_Sombras : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clone_das_Sombras(QWidget *parent = 0);
    ~Clone_das_Sombras();

private slots:
    void on_buttonClonar_clicked();

    void on_buttonMorrer_clicked();

    void atualizar_pid();

private:
    Ui::Clone_das_Sombras *ui;
    pid_t pidPai;
    pid_t pid;
    QProcess *pogama;
};

#endif // CLONE_DAS_SOMBRAS_H
