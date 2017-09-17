#include "nwt.h"
#include "ui_nwt.h"
#include <cmath>

Nwt::Nwt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nwt)
{
    ui->setupUi(this);// connection of the signals with the slots
    connect(ui->Iniciar,SIGNAL(clicked()),this,SLOT(ejecutar()));
    connect(ui->Reiniciar,SIGNAL(clicked()),this,SLOT(reanudar()));
    connect(ui->vx,SIGNAL(valueChanged(double)),this,SLOT(activar()));// connection of the spin box signal with the activate slot
    connect(ui->erroa,SIGNAL(valueChanged(double)),this,SLOT(activar()));
    connect(ui->intmin,SIGNAL(valueChanged(int)),this,SLOT(activar()));
    ui->Iniciar->setDisabled(true);// condition to deactivate the push button "Start"
    ui->Reiniciar->setDisabled(true);// condition to deactivate the push button "Restart"
    ei=100;// the initial error is executed with 100
}
double Nwt::dg(double c){ // original function to evaluate
    return(sin(5*c));
}
double Nwt::g(double d){// function derived from the original to be evaluated
    return(5*cos(5*d));
}
void Nwt::activar(){ //slot to activate the buttons when you change the value of the spin box
    x=0; xr=0; ea=0; i=0;//All variables goes to 0, for start over
    ui->Reiniciar->setDisabled(false); //here the Restart button was activated
    x=ui->vx->value();// picks up the initial value that the user enters and stores them in "x"
    ea=ui->erroa->value();//collects the initial error entered by the user and saves it in "ea"
    max=ui->intmin->value();//picks up the initial value of interactions and saves it in "i"
    if((x!=0)&&(ea!=0)&&(max!=0)){ // this condition activates the button to start always all spinboxes are different from zero
        ui->Iniciar->setDisabled(false);// activate the home button
    }
    else{//if the condition is not set, the start button is not activated
         ui->Iniciar->setDisabled(true);
    }
}
void Nwt::ejecutar(){// slot to execute the method when the button is clicked
    ei=100;//The initial error back to 100 percent, to start over the method
    while((ei>ea)&(max>i)){//we compare the initial error with the initiate and compare the iterations with those introduced by the user
         xr=(x)-(dg(x)/g(x));//Calculates the next point to evaluate (with the initial value, the original and derivative function), and saves it on "xr"
         ei=100*std::abs(xr-x)/xr;//Calculates the new error, and saves it on "ei"
         i++;// sum of the interactions
         x=xr;// collects the value of xr, saves it and reassesses it
     }
    ui->Pantalla->display(x);// here are on-screen variables
    ui->errormos->display(ei);
    ui->Interac->display(i);
    ui->Reiniciar->setDisabled(false);// here the Restart button was activated
}
void Nwt::reanudar(){//slot that will restart the method to enter a new value of "x", "accepted error" and "number of interactions" deleting everything previously entered
     ui->vx->setValue(0.0);//the value of "x", the "error accepted" "the number of interactions", the root found and other things displayed on the screen are deleted
     ui->erroa->setValue(0.0);
     ui->Pantalla->display(0.0);
     ui->Interac->display(0.0);
     ui->errormos->display(0.0);
     ui->Interac->display(0.0);
     ui->Iniciar->setDisabled(true);// condition to deactivate the push button
     ui->Reiniciar->setDisabled(true);
}

Nwt::~Nwt()
{
    delete ui;
}
