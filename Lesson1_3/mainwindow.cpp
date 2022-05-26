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


void MainWindow::on_htmlButton_clicked()
{
    ui->Text2->document()->setHtml("<font color='red'>Hello</font>");
}


void MainWindow::on_replaceButton_clicked()
{
    ui->Text2->setPlainText(ui->Text1->toPlainText());
}


void MainWindow::on_addButton_clicked()
{


    ui->Text2->appendPlainText(ui->Text1->toPlainText());
}

