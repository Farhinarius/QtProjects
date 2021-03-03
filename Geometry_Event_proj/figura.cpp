#include <math.h>
#include "figura.h"

// abstract cpp file, we don't call any functions here
//////////////////////////////////////////////////////////////////////////////////////////////////////
// ОПИСАНИЕ МЕТОДА КЛАССА ФИГУРЫ, КОТОРЫЙ ОСУЩЕСТВЛЯЕТ ВРАЩАТЕЛЬНОЕ ДВИЖЕНИЕ
void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha);
    dy=halflen*sin(Alpha);
    draw(Painter);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
// ОПИСАНИЕ МЕТОДА КЛАССА ОТРЕЗКА, КОТОРЫЙ ОСУЩЕСТВЛЯЕТ  РИСОВАНИЕ ОТРЕЗКА
void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// ОПИСАНИЕ МЕТОДА КЛАССА ПРЯМОУГОЛЬНИК, КОТОРЫЙ ОСУЩЕСТВЛЯЕТ РИСОВАНИЕ ПРЯМОУГОЛЬНИКА
void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
