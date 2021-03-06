#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


#include "widget.h"
#include "ui_widget.h"
//  программа описывает модель цепи владения,в которой при удалении базового класса(закрытии главного окна), удаляются все производные классы(очищаются)
// при вызове конструктора создаются все элементы интерфейса(на них выделяется память)
// конструктор класса, вызывающийся при создании объекта
Widget::Widget(QWidget *parent) : // при создании объекта widget будут появляться остальные виджеты встроенные внутри этого конструктора
    QWidget(parent)    // такой конструктор показывает что существует цепь владения, начинающаяся с базового класса QWidget(виджет-владелец),
                       // которому подчиняются остальные классы(виджеты-подчиненные)
                       // чтобы очистить память выделенную на указатели классов ниже, нужно удалить "виджет-владелец", что происходит с помощью декстркутора в конце программы
{
    setWindowTitle(tr("Hello world!!!")); // установка заголовка окна
    setMinimumSize(200,80);  // установка минимальных размеров окна(мы его можем растягивать)

    QLabel * plb = new QLabel(tr("Test"),this);  // 1.создание указателя на виджет(класс), для работы с методами через память(неявное)
    plb->setGeometry(20,20,80,24); // 2.метод, позволяющий установить виджет лейбл, где параметры: (x,y,ширинавиджета,высотавиджета), x,y - координаты левого верхнего угла виджета

    QLineEdit * ple = new QLineEdit(this);  // аналогично для поля введения текста
    ple->setGeometry(100,20,90,24);

    QPushButton * ppb = new QPushButton(tr("Ok"),this); // аналогично для установки кнопки
    ppb->setGeometry(20,50,80,24);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget window;
    window.show();

    return a.exec();
}



Widget::~Widget()  // деструктор, очищающий память от объектов, начинает работать при |закрытии| главного окна - то есть базового класса.
{

}
