#ifndef TRIEL_H
#define TRIEL_H

#include <QWidget>
#include<QPainter>
class triel : public QWidget
{
    Q_OBJECT
public:
    QPainter  *paint;
   float a=0;
   void paintEvent(QPaintEvent *event);
void timerEvent(QTimerEvent *event);
signals:

public slots:
};

#endif // TRIEL_H
