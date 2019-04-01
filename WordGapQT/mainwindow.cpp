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

void MainWindow::on_wordButton_clicked()
{
  ui->textBrowser->setText("Welcome to Word Gap!");
}

void MainWindow::on_verbButton_clicked()
{
    ui->textBrowser->setText("Welcome to the verb game!");

}

void MainWindow::on_submitButton_clicked()
{

}
