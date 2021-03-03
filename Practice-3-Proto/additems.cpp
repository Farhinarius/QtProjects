#include "additems.h"
#include "ui_additems.h"
#include "fileclass.h"
#include "stdio.h"
AddItems::AddItems(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::AddItems)
{
    ui->setupUi(this);
    QFont font = ui->label->font();
    font.setPointSize(9);
    font.setBold(true);
    ui->label->setFont(font);
}


// DELETE FORM "ADD_ITEMS"
AddItems::~AddItems()
{
    delete ui;
}


void AddItems::on_pushButton_2_clicked()
{
    ui->textEdit->clear();             // clear fields
    if( ui->lineEdit->text() != ""     // we can't add empty record
            and ui->lineEdit_2->text() != ""
            and ui->lineEdit_3->text() != ""
            and ui->memory_textfield->text() != "")
    {
       FileClass book; // = FileClass();
       recType record;
       record.name = ui->lineEdit->text();
       record.company=ui->lineEdit_2->text();
       record.year= ui->lineEdit_3->text();
       record.memory= ui->memory_textfield->text();

       ui->lineEdit->clear();
       ui->lineEdit_2->clear();
       ui->lineEdit_3->clear();
       ui->memory_textfield->clear();
       book.addRec(record);
    }
}

void AddItems::on_pushButton_clicked()
{
    ui->textEdit->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->memory_textfield->clear();
    close();
}
