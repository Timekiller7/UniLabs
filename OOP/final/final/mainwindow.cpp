#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCopy_To_Upper_triggered()
{
    erase();
    ui->lineEdit->setText(ui->lineEdit_2->text());
    ui->lineEdit->setStyleSheet(QString("background-color: #b1bdfc;"));
}

void MainWindow::on_actionReverse_Upper_triggered()
{
    erase();
    QString temp = ui->lineEdit->text();
    std::reverse(temp.begin(), temp.end());
    ui->lineEdit->setText(temp);
    ui->lineEdit->setStyleSheet(QString("background-color: #b1bdfc;"));
}

void MainWindow::on_actionReverse_Lower_triggered()
{
    erase();
    QString temp = ui->lineEdit_2->text();
    std::reverse(temp.begin(), temp.end());
    ui->lineEdit_2->setText(temp);
    ui->lineEdit_2->setStyleSheet(QString("background-color: #b1bdfc;"));
}

void MainWindow::on_actionReverse_All_triggered()
{
    MainWindow::on_actionReverse_Upper_triggered();
    MainWindow::on_actionReverse_Lower_triggered();
    both();
}

void MainWindow::on_actionConcat_Up_And_Low_triggered()
{
    both();
    ui->lineEdit->setText(ui->lineEdit->text() + ui->lineEdit_2->text());
}

void MainWindow::on_actionConcat_Low_And_Up_triggered()
{
    both();
    ui->lineEdit_2->setText(ui->lineEdit_2->text() + ui->lineEdit->text());
}


void MainWindow::erase() {
    ui->lineEdit->setStyleSheet(QString("background-color: #FFFFFF;"));
    ui->lineEdit_2->setStyleSheet(QString("background-color: #FFFFFF;"));
}

void MainWindow::both() {
    ui->lineEdit->setStyleSheet(QString("background-color: #74e3fc;"));
    ui->lineEdit_2->setStyleSheet(QString("background-color: #74e3fc;"));
}