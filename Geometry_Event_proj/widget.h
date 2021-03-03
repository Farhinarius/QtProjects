#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <area.h>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    Area * area;         // область отображения рисунка
    QPushButton * btn;

public:

    Widget(QWidget *parent = 0); // ?
    ~Widget();
};

#endif // WIDGET_H
