#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
 createMainWindowInterier();
}

Widget::~Widget()
{

}

void Widget::createMainWindowInterier()
{
    // СОЗДАНИЕ ВИДЖЕТОВ ГЛАВНОГО ОКНА
    addButton   = new QPushButton("Add Person/Add Number",this);
    info1Button = new QPushButton("Identify all subscriber features by phone number",this);
    info2Button = new QPushButton("Identify all individual owners connected in a given year",this);
    info3Button = new QPushButton("Identify unoccupied phone numbers",this);
    info4Button = new QPushButton("Build Graphic",this);
    exitButton  = new QPushButton("Exit",this);


    // КОМПАНОВКА ВИДЖЕТОВ НА ГЛАВНОМ ОКНЕ С ПОМОЩЬЮ ВЕРТИКАЛЬНОГО МЕНЕДЖЕРА КОМПАНОВКИ
    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(addButton);
    layout->addWidget(info1Button);
    layout->addWidget(info2Button);
    layout->addWidget(info3Button);
    layout->addWidget(info4Button);
    layout->addWidget(exitButton);


    // устанавливаем размеры окна и его характеристики
    setMinimumSize(320,200);
    resize(320,200);

    // УСТАНАВЛИВАЕМ СОБЫТИЯ ДЛЯ КНОПОК С ПОМОЩЬЮ СИГНАЛОВ И СЛОТОВ
    connect(exitButton, SIGNAL(clicked(bool)),
                 this,SLOT(close()));
    connect(addButton,SIGNAL(clicked(bool)),
                 this,SLOT(showWidgetAdd()));
    connect(info1Button,SIGNAL(clicked(bool)),
                   this,SLOT(showWidgetChar()));
    connect(info2Button, SIGNAL(clicked(bool)),
                   this,SLOT(showWidgetIO()));
    connect(info3Button, SIGNAL(clicked(bool)),
                   this,SLOT(showWidgetUnPhones()));
    connect(info4Button, SIGNAL(clicked(bool)),
                   this,SLOT(show_graphic()));

}

void Widget::showWidgetAdd()
{
 widgetAdd.show();
}

void Widget::showWidgetChar()
{
    widgetChar.show();
}

void Widget::showWidgetIO()
{
    widgetIO.show();
}

void Widget::showWidgetUnPhones()
{
    widgetUnPhones.show();
}

void Widget::show_graphic()
{
    widgetGraphic.show();
}














