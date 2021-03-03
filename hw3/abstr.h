#ifndef ABSTR_H
#define ABSTR_H

#include <QObject>
#include<QWidget>
#include<QPainter>

class widg : public QWidget
{
    Q_OBJECT
public:

    float a=0;
    float percent=0;
    QPainter *paint;
    void timerEvent(QTimerEvent *event);
     void paintEvent(QPaintEvent *event);
public slots:
};

/*class abstr : public QObject
{
    Q_OBJECT
protected:
public:


signals:

public slots:
};*/

#endif // ABSTR_H
