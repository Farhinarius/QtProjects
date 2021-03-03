#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget win;
    win.setWindowTitle("Hello");

    QLabel * helloLabel = new QLabel("Hello",&win);
    QPushButton * exitButton = new QPushButton("Close",&win);

    QHBoxLayout *layout = new QHBoxLayout(&win);
    // установка раскладки метки и кнопки с помощью метода layout в окне win
    layout->addWidget(helloLabel);
    layout->addWidget(exitButton);
    // сигнал передающий кнопке команду закрытия окна win
    QObject::connect(exitButton,SIGNAL(clicked(bool))),
            &win,SLOT(close()));
    win.show();
    return app.exec();
}
