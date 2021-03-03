#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget window;

    window.setWindowTitle("Application Window");
    window.setObjectName("window");

    QLineEdit *edit1_field = new QLineEdit("Edit1",&window); // create EDIT 1
    QLineEdit *edit2_field = new QLineEdit("Edit2",&window); // create EDIT 2
    QLineEdit *edit3_field = new QLineEdit("Edit3",&window); // create EDIT 3

    QGridLayout * layout = new QGridLayout; // create GRID LAYOUT for window

    layout->setContentsMargins(5,5,5,5);
    layout->setSpacing(5);
    window.setLayout(layout);

    // создаем геометрию в окне, размещая каждый виджет в таблцу(матрицу),
    // получаем в итоге окошко с сеткой 2 на 2
    // НУМЕРАЦИЯ ИДЁТ С 0 ЭЛЕМЕНТА В МАТРИЦЕ
    layout->addWidget(edit1_field,0,0,1,2); // виджет размещается по горизонтали в первых двух клетках, то есть 0,0 и 0,1
    layout->addWidget(edit2_field,1,0,1,1); // виджет размещается в одной клетке, вторкая строка(1), первый столбец(0)
    layout->addWidget(edit3_field,1,1,1,1); // виджет размещается в одной клетке, вторая строка(1), второй столбец(1)

    window.show();
    return a.exec();
}
