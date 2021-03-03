#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QWidget>
#include<QPainter>
class ellipse : public QWidget
{
    Q_OBJECT
public:
    float a=0;
    QPainter *paint;
    bool flag=true;

    void paintEvent(QPaintEvent * event);
    void timerEvent(QTimerEvent *event);

signals:

public slots:
    void stopping();
};

#endif // ELLIPSE_H
