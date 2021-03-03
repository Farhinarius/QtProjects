#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :  QWidget(parent)
{
    // создаём заголовок для окна формы
    setWindowTitle(tr("New Title"));

    // Вызов приватного метода создания интерьер
    createFormInterior(); //------------------------------|
}

Widget::~Widget()
{

}

void Widget::createFormInterior()   // описание метода класса Widget, в котором происходят следующие операции
{
   // реализованы примеры создания интерьера формы

   QGridLayout * grid = new QGridLayout(this); // неявно смотри коментарии ниже

   // QGridLayout * grid = new QGridLayout();  // выделяем указатель типа "раскладка сетки"
   // setLayout(grid);                         // создаём раскладку типа "сетка"

   {
     QLabel * plb = new QLabel(tr("Enter: "),this);
     grid->addWidget(plb,0,0);
   }

   {
     QLineEdit * ple = new QLineEdit(this);
     grid->addWidget(ple,0,1);
   }

   {
     QLineEdit * ple = new QLineEdit(this);
     grid->addWidget(ple, 1,0, 1,2);
   }

   {
     QPushButton * ppb = new QPushButton(tr("Up"),this);
     grid->addWidget(ppb,2,0);
   }

   {
     QTextEdit * pte = new QTextEdit(this);
     grid->addWidget(pte,2,1,3,1);
   }

   {
     QPushButton * ppb = new QPushButton(tr("Down"),this);
     grid->addWidget(ppb,4,0);
   }
}
