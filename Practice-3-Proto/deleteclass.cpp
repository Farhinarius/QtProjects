#include "deleteclass.h"
#include "ui_deleteclass.h"

DeleteClass::DeleteClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeleteClass)
{
    ui->setupUi(this);
    QFont font = ui->label->font();
    font.setPointSize(18);
    font.setBold(true);
    ui->label->setFont(font);
}

DeleteClass::~DeleteClass()
{
    delete ui;
}

void DeleteClass::on_pushButton_2_clicked()
{
    FileClass file;
    file.reSetFile();
    file.deleteline(ui->lineEdit->text());
    ui->lineEdit->clear();
}
void DeleteClass::on_pushButton_clicked()
{
    close();
};
