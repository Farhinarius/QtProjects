#ifndef FIGURA_H
#define FIGURA_H
#include <QtGui>
#include <QPainter>

//////////////////////////////////////////////////////////////////////////////////////
// CLASS FIGURE
class Figura // abtract class
{
protected:

    int x,y,halflen,dx,dy,r;
    virtual void draw(QPainter *Painter)=0;

public:

    Figura(int X,int Y,int Halflen): x(X),y(Y),halflen(Halflen){} // constructor
    void move(float Alpha,QPainter *Painter); // движение фигуры
    // virtual ~Figura();               // virtual destructor
};

//////////////////////////////////////////////////////////////////////////////////////
// CLASS LINE
class MyLine : public Figura
{
protected:

    void draw(QPainter *Painter);

public:

    MyLine(int x,int y,int halflen) : Figura(x,y,halflen){}
};

///////////////////////////////////////////////////////////////////////////////////////
// CLASS RECTANGLE
class MyRect : public Figura
{
protected:

    void draw(QPainter *Painter);

public:

    MyRect(int x,int y,int halflen) : Figura(x,y,halflen){}
};

///////////////////////////////////////////////////////////////////////////////////////
#endif // FIGURA_H
