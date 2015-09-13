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


private:
    Ui::X_Infinity *ui;
    QTimer *intervalo;
};

#endif // X_INFINITY_H
