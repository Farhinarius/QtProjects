#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
Window::Window()
{
    codec = QTextCodec::codecForName("Windows-1251");
    this->setWindowTitle(codec->toUnicode("Rotate pictures"));
    area = new Area( this );
    btn = new QPushButton(codec->toUnicode("Close"),this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()),this,SLOT(close()));
};
