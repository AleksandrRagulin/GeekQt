#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calcButton_clicked()
{
    double a = 0;
    double b = 0;
    double c = 0;
    double D = 0;
    double y1 = 0;
    double y2 = 0;
    QString res = "";
    QString tmp = "";

    if(ui->aLine->text() == "" ||
            ui->bLine->text() == "" ||
            ui->bLine->text() == "")
    {
        res = "Empty fields";
        ui->resLine->setText(res);
        return;
    }


    try {
        a = ui->aLine->text().toDouble();
        b = ui->bLine->text().toDouble();
        c = ui->cLine->text().toDouble();

    }  catch (...) {
        res = "Incorrect fields";
        ui->resLine->setText(res);
        return;
    }


    D = pow(b,2) - 4 * a * c;




    if (a == 0 && b != 0){
            y1 = c / b;
            res = "y1 = ";

            tmp = QString::number(y1);
            res.append(tmp);
            ui->resLine->setText(res);

        return;
    }


    if ( D == 0 ){
        y1 = -b / ( 2 * a );
        res = "y1 = ";

        tmp = QString::number(y1);
        res.append(tmp);
        ui->resLine->setText(res);

        return;
    }

    if (D > 0) {
        y1 = (-b + sqrt(D)) / ( 2 * a );
        y2 = (-b - sqrt(D)) / ( 2 * a );

        res = "y1 = ";
        tmp = QString::number(y1);
        res.append(tmp);
        res.append("  y2 = ");
        tmp = QString::number(y2);
        res.append(tmp);
    ui->resLine->setText(res);
        return;
    }

     res = "D<0";
      ui->resLine->setText(res);
     return;

}

