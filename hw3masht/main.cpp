#include "mainwindow.h"
#include <QApplication>
#include"triangle.h"
#include"ellipse.h"
#include"trielli.h"
#include<QHBoxLayout>

#include<QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QWidget b;
    b.setGeometry(600,500,100,100);
    w.setGeometry(0,0,9999,9999);
    QPushButton *button = new QPushButton("STOP",&b);
  //  button->setGeometry(600,900,100,20);
    triangle tri;
    tri.startTimer(500);
    ellipse elli;
    elli.startTimer(300);
    trielli triel;
    triel.startTimer(700);
     QObject::connect(button,SIGNAL(clicked()),&elli,SLOT(stopping()));
     QObject::connect(button,SIGNAL(clicked()),&tri,SLOT(stopping()));
     QObject::connect(button,SIGNAL(clicked()),&triel,SLOT(stopping()));
    QHBoxLayout *hor = new QHBoxLayout;


    hor->addWidget(&tri);
    hor->addWidget(&elli);
    hor->addWidget(&triel);
    w.setLayout(hor);
    w.show();
    b.show();


    return a.exec();
}
