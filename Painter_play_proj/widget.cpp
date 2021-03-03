#include "widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent)
{
   QPainter * Painter = new QPainter;
    paintEvent(Painter);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPainter * Painter)
{
    // QPainter * Painter = new QPainter;
    Painter->setPen(Qt::black);
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
}
