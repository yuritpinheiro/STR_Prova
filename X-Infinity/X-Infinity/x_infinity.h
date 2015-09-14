#ifndef X_INFINITY_H
#define X_INFINITY_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class X_Infinity;
}

class X_Infinity : public QMainWindow
{
    Q_OBJECT

public:
    explicit X_Infinity(QWidget *parent = 0);
    ~X_Infinity();

private slots:
    void on_btnTime_clicked();
    void atualizarProcessos();


    void on_btnFiltro_clicked();

private:
    Ui::X_Infinity *ui;
    QTimer *intervalo;
    QString filtro;
};

#endif // X_INFINITY_H
