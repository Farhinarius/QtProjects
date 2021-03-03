#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget window;

    window.setWindowTitle("Window Application");
    window.setObjectName("window");

    // create EDIT FIELD1
    QLineEdit * edit_field1 = new QLineEdit("Edit1",&window);

    // create EDIT FIELD2
    QLineEdit * edit_field2 = new QLineEdit("Edit2",&window);

    // create HORIZOTNAL LAYOUT
    QHBoxLayout * layout = new QHBoxLayout;

    // create VERTICAL LAYOUT
  //-- QVBoxLayout * layout = new QVBoxLayout;


    layout->setContentsMargins(5,5,5,5);  // внешние поля окна
    layout->setSpacing(5);                // расстояние между виждетами
    window.setLayout(layout);             // привязка раскладки виджетов к окну приложения

    // Задание порядка следование элементов
    layout->addWidget(edit_field1);
    layout->addWidget(edit_field2);
   // layout->addStretch();

    window.show();
    return a.exec();
}
