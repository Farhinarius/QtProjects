#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<QPainter>
#include <QWidget>

class triangle : public QWidget
{
    Q_OBJECT
public:
    float a=0;
    QPainter *paint;
    bool flag=true;
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void stopping();
};

#endif // TRIANGLE_H
