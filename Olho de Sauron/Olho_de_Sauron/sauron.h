#ifndef SAURON_H
#define SAURON_H

#include <QMainWindow>

namespace Ui {
class Sauron;
}

class Sauron : public QMainWindow
{
    Q_OBJECT

public:
    explicit Sauron(QWidget *parent = 0);
    ~Sauron();

private:
    Ui::Sauron *ui;
};

#endif // SAURON_H
