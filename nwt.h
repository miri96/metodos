#ifndef NWT_H
#define NWT_H

#include <QMainWindow>
#include<cmath>

namespace Ui {
class Nwt;
}

class Nwt : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nwt(QWidget *parent = 0);
    ~Nwt();
    double x; // this variable saves the data that the user has entered for "x"
    double xr;// this variable saves the next point by evaluating (x + 1) temporarily
    double ei;// variable with start error
    double ea;// this variable saves the accepted error entered by the user
    int i;// interaction counter
    double g(double d);//Original function
    double dg(double c);//Derived function
    int max;//this variable stores the number of interactions entered by the user
public slots:
    void ejecutar();// slot to start the method
    void reanudar();// slot to restart method
    void activar();// slot to activate push button when conditions are met

private:
    Ui::Nwt *ui;
};

#endif // NWT_H
