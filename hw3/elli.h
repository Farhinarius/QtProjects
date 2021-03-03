#ifndef ELLI_H
#define ELLI_H

#include <QWidget>
#include<QPainter>
#include<math.h>
class elli : public QWidget
{
    Q_OBJECT
public:
    float a=0;
    QPainter *paint;
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

signals:

public slots:
};

#endif // ELLI_H
