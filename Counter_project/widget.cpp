// Counter workspace
// options;


#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
 this->createFormInterier();
 this->Events();
}

Widget::~Widget()
{

}

void Widget::createFormInterier()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ОПИСАНИЕ ХАРАКТЕРИСТИКИ ВИДЖЕТОВ part 1
 // создание рамки Frame class и её характеристики
    leftframe = new QFrame(this); // выделение памяти для leftframe, которая освободиться при срабатывании деструктора ~Widget
    rightframe = new QFrame(this); // выделение памяти для rightframe, которая освободиться при срабатывании деструктора ~Widget

    // leftframe описание
    leftframe->setFrameShape(QFrame::Panel);
    leftframe->setFrameShadow(QFrame::Raised);

    // rightframe описание
    rightframe->setFrameShape(QFrame::Panel);
    rightframe->setFrameShadow(QFrame::Raised);

 // создание и описание calcbutton and exitbutton
    calcbutton = new QPushButton(tr("Inc +1"),this);
    exitbutton = new QPushButton(tr("Exit"),this);

 // создание и описание edit1, edit 2
    edit1 = new CounterEdit("",this);
    edit2 = new CounterEdit("",this);

 // создание и описание leftlabel, rightlabel
    leftlabel = new QLabel("Counter for +1",this);
    rightlabel = new QLabel("Counter for +5",this);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // КОМПАНОВКА ВИДЖЕТОВ: СОЗДАНИЕ РАСКЛАДКИ ДЛЯ ГЛАВНОГО ОКНА part 2: LAYOUT
  // создание вертикальной раскладки 1
    QVBoxLayout * vLayout1 = new QVBoxLayout(leftframe);
    vLayout1->addWidget(leftlabel);
    vLayout1->addWidget(edit1);
    vLayout1->addStretch();

  // создание вертикальной раскладки 2
    QVBoxLayout * vLayout2 = new QVBoxLayout(rightframe);
    vLayout2->addWidget(rightlabel);
    vLayout2->addWidget(edit2);
    vLayout2->addStretch();

  // создание вертикальной раскладки 3 для кнопок
    QVBoxLayout * vLayout3 = new QVBoxLayout();
    vLayout3->addWidget(calcbutton);
    vLayout3->addWidget(exitbutton);

  // создание горизонтальной раскладки для главного окна
    QHBoxLayout * hLayout = new QHBoxLayout(this);
    hLayout->addWidget(leftframe);
    hLayout->addWidget(rightframe);
    hLayout->addLayout(vLayout3);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // ПРОГРАММИРОВАНИЕ СОБЫТИЙ ГЛАВНОГО ОКНА И ЕГО ОБЪЕКТОВ part 3: SIGNAL AND SLOTS
void Widget::Events()
{


      // создание события закрытия окна
      connect(exitbutton,SIGNAL(clicked()),this,SLOT(close()));

      // создание события инкрементации счетка по 1
      connect(calcbutton,SIGNAL(clicked()),edit1,SLOT(add_one()));

      // создание события инкрементации счетка по 5
      connect(edit1,SIGNAL(tick_signal()),edit2,SLOT(add_one()));

}
