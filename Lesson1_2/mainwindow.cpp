#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

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
    QString res = "";
    double a = 0;
    double b = 0;
    double angle = 0;
    double C = 0;

    if(ui->aLine->text() == "" ||
           ui->bLine->text() == "" ||
            ui->angleLine->text() == ""){
        ui->resLine->setText("Empty fields");
        return;
    }
    try {
        a = ui->aLine->text().toDouble();
        b = ui->bLine->text().toDouble();
        angle = ui->angleLine->text().toDouble();
    }  catch (...) {
        ui->resLine->setText("Incorrect fields");
        return;
    }


    if( a <= 0 || b <= 0){
        ui->resLine->setText("Incorrect fields");
        return;
    }

    if(ui->degreesRadio->isChecked()){
        angle = qDegreesToRadians(angle);
        C = qSqrt(a * a + b * b - 2 * a * b * qCos(angle));
        res = QString::number(C);
        ui->resLine->setText(res);
        return;
    }
    else{
        C = qSqrt(a * a + b * b - 2 * a * b * qCos(angle));
        res = QString::number(C);
        ui->resLine->setText(res);
        return;
    }


}

