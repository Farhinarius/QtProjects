#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>


class Widget : public QWidget
{
    Q_OBJECT

public:
     Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
