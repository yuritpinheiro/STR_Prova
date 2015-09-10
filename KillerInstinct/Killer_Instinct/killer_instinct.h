#ifndef KILLER_INSTINCT_H
#define KILLER_INSTINCT_H

#include <QMainWindow>

namespace Ui {
class Killer_Instinct;
}

class Killer_Instinct : public QMainWindow
{
    Q_OBJECT

public:
    explicit Killer_Instinct(QWidget *parent = 0);
    ~Killer_Instinct();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::Killer_Instinct *ui;
};

#endif // KILLER_INSTINCT_H
