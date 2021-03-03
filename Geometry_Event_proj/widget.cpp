#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{

        this->setWindowTitle(tr("Geometry Event"));
        area = new Area( this );
        btn = new QPushButton(tr("Stop and Close"),this);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(area);
        layout->addWidget(btn);
        connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));

}

Widget::~Widget()
{

}
