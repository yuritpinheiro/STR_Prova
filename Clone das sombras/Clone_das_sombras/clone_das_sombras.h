#ifndef CLONE_DAS_SOMBRAS_H
#define CLONE_DAS_SOMBRAS_H

#include <QMainWindow>

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

private:
    Ui::Clone_das_Sombras *ui;
    void *atualizarPIDS(void *param);
    pid_t pidPai;
    pid_t pid;
};

#endif // CLONE_DAS_SOMBRAS_H
