#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget window;


    QSplitter splitter(Qt::Horizontal);
    splitter.setWindowTitle("Main Window");
    QLineEdit * edit1 = new QLineEdit("Edit1",&splitter);
    QLineEdit * edit2 = new  QLineEdit("Edit2",&splitter);
    splitter.show();


    return a.exec();
}
