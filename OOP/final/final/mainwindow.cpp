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
    ui->lineEdit->setText(ui->lineEdit_2->text());
}

void MainWindow::on_actionReverse_Top_Box_triggered()
{
    QString temp = ui->lineEdit->text();
    std::reverse(temp.begin(), temp.end());
    ui->lineEdit->setText(temp);
}

void MainWindow::on_actionReverse_Bottom_Box_triggered()
{
    QString temp = ui->lineEdit_2->text();
    std::reverse(temp.begin(), temp.end());
    ui->lineEdit_2->setText(temp);
}

void MainWindow::on_actionReverse_All_triggered()
{
    MainWindow::on_actionReverse_Top_Box_triggered();
    MainWindow::on_actionReverse_Bottom_Box_triggered();
}

void MainWindow::on_actionConcat_Top_With_Bottom_triggered()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ui->lineEdit_2->text());
}

void MainWindow::on_actionConcat_Bottom_With_Top_triggered()
{
    ui->lineEdit_2->setText(ui->lineEdit_2->text() + ui->lineEdit->text());
}
