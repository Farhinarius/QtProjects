#include "triel.h"
#include<math.h>
void triel::paintEvent(QPaintEvent *event)
{
    paint = new QPainter(this);
    a+=0.15;
    paint->scale(0.2+a,0.2+a);

     int x1,x2,x3,y1,y2,y3,x4,yc;
     x1=360;
     y1=450;
     y2=y1;
     x2=440;
     x3=(x2-x1)/2;
     x4=x1+x3;
     y3=y2-(round((sqrt((x2-x1)*(x2-x1)-x3*x3))));

 yc=y1-round((y1-y3)/3);

 paint->translate(x4/(1+a),yc/(1+a));
 paint->drawEllipse(0-x3-7.25,-2*round((y1-y3)/3),x2-x1+12.75,x2-x1+12.75);
 paint->drawLine(0-x3,round((y1-y3)/3),x3,round((y1-y3)/3));
 paint->drawLine(0-x3,round((y1-y3)/3),0,-2*round((y1-y3)/3));
 paint->drawLine(0,-2*round((y1-y3)/3),x3,round((y1-y3)/3));
 this->update();
}

void triel::timerEvent(QTimerEvent *event)
{
    paintEvent(nullptr);
    this->update();
}
