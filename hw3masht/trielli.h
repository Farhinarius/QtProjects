#ifndef TRIELLI_H
#define TRIELLI_H

#include <QWidget>
#include<QPainter>

class trielli : public QWidget
{
    Q_OBJECT
public:
    float a=0;
    QPainter *paint;
    bool flag=true;
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

signals:

public slots:
    void stopping();
};

#endif // TRIELLI_H
