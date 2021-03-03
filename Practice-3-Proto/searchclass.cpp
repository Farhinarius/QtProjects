#include "searchclass.h"
#include "ui_searchclass.h"
#include <QMessageBox>
SearchClass::SearchClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchClass)
{


    ui->setupUi(this);


}



SearchClass::~SearchClass()
{
    delete ui;
}

void SearchClass::on_pushButton_clicked()
{
    FileClass file;
    ui->textEdit->clear();
    file.reSetFile();
    ui->textEdit->setReadOnly(true);
    QString  search_name("") , tmp("");
            while (file.searchmemory(ui->lineEdit->text(), search_name))  // cool move
            {
                if (tmp != search_name)
                {
                ui->textEdit->append(search_name);
               // tmp = date;
                }
            }
            if (search_name == "")  // Error-Message
            {
              ui->textEdit->append("Information doesn't exist");
            }
}

void SearchClass::on_pushButton_2_clicked()
{
    FileClass file;
    ui->textEdit_2->clear();
    file.reSetFile();
    ui->textEdit_2->setReadOnly(true);
    QString developer,tmp;
            while (file.searchname(ui->lineEdit_2->text(), ui->lineEdit_3->text(),
                                   ui->lineEdit_4->text(), developer)){
               if (tmp != developer){
                ui->textEdit_2->append(developer);
                }
                // tmp = developer;
            }
            if (developer == "")  // Error-Message
            {
              ui->textEdit_2->append("Information doesn't exist");
            }
}

void SearchClass::on_pushButton_3_clicked()
{
    FileClass file;
    ui->textEdit_3->clear();
    file.reSetFile();
    ui->textEdit_3->setReadOnly(true);
    QStringList s("");
    QString tmpS,tmp;
  while (file.searchitem(ui->lineEdit_5->text(),s))
  {
   if (ui->lineEdit_5->text() == s[0])
   {
       if (tmp != s[0])
       {
       tmpS+="Название: ";
       tmpS+=s[0];
       ui->textEdit_3->append(tmpS);
       tmpS="";
       tmpS+="Компания: ";
       tmpS+=s[1];
       ui->textEdit_3->append(tmpS);
       tmpS="";
       tmpS+="Дата: ";
       tmpS+=s[2];
       ui->textEdit_3->append(tmpS);
       tmpS="";
       tmpS+="Объем памяти: ";
       tmpS+=s[3];
       ui->textEdit_3->append(tmpS);
       tmpS="";
       tmp=s[0];
       }
    }
   }
  if (s[0] == "Information doesn't exist")  // Error-Message
  {
    ui->textEdit_3->append("Information doesn't exist");
  }
}


void SearchClass::on_pushButton_4_clicked()
{
    close();
}
