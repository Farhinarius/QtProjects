// grid_layout_using.proj
// options;

#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
     setWindowTitle("Window Application1");
     createFormInterier();
}

Widget::~Widget()
{

}

void Widget::createFormInterier()
{
    QGridLayout * grid = new QGridLayout(this);

    {
        QPushButton * button = new QPushButton(tr("Save text"),this);
        grid->addWidget(button,0,0);
    }
    {
        QLineEdit * edit1 = new QLineEdit(this);
        grid->addWidget(edit1,0,1,1,2);
    }
}

