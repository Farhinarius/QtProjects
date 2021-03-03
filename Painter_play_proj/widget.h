#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

class Widget : public QWidget
{
    Q_OBJECT
    int x,y,halflen,dx,dy,r;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPainter * Painter);
};

#endif // WIDGET_H
