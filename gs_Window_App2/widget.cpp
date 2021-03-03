#include "widget.h"




Widget::Widget(QWidget *parent) : QWidget(parent)
{
  setWindowTitle(tr("Hello"));

  QLabel * helloLabel=new QLabel(tr("Hello!"),this);
  QPushButton * exitButton=new QPushButton(tr("Exit"),this);
  QHBoxLayout * layout = new QHBoxLayout(this); // создание элемента

  // компоновки для управления размещением метки и кнопки в окне win
       layout->addWidget(helloLabel);  // добавление метки к компоновщику
       layout->addWidget(exitButton);  // добавление кнопки к компоновщику

  // связь сигнала нажатия кнопки и слота закрытия окна
          connect(exitButton,SIGNAL(clicked(bool)),
                  this,SLOT(close()));
}

Widget::~Widget()
{
}
