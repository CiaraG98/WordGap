#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD
=======

void MainWindow::on_pushButton_clicked()
{

}
>>>>>>> 962a4f464dc4e061e20c60242296c72ed0ceb421
