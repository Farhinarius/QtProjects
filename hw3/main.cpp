
#include <QApplication>
#include<QPainter>
#include<abstr.h>
#include<QPushButton>
#include<triel.h>
#include<elli.h>
#include<QHBoxLayout>
#include <QTimer>
#include<QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widg haha;
    QWidget base;
    base.setGeometry(0,0,9999,9999);
    haha.startTimer(700);

    triel hoho;
     hoho.startTimer(800);
     hoho.killTimer();
     elli gg;
     gg.startTimer(500);
     QTimer *t = new QTimer(&hoho);
      t->setInterval(1);
     QObject::connect(t,SIGNAL(timeout()),&hoho,SLOT(timerEvent()));

     t->start(1);
     t->stop();
     QHBoxLayout *lay = new QHBoxLayout;
     lay->addWidget(&haha);
     lay->addWidget(&hoho);
     lay->addWidget(&gg);
     base.setLayout(lay);
     base.show();
    return a.exec();
}
