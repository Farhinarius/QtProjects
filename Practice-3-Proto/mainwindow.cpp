#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font = ui->label->font();
    font.setPointSize(18);
    font.setBold(true);
    ui->label->setFont(font);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{

   addItems.show();

}

void MainWindow::on_pushButton_2_clicked()
{
    searchClass.show();
}

void MainWindow::on_pushButton_3_clicked()
{
    deleteClass.show();
}

void MainWindow::on_pushButton_5_clicked()
{
     graphicClass.show();
}
