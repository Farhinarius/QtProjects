#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>

////////////////////////////////////////////////////////////////////////////////////
// COUNTER CLASS
class CounterEdit : public QLineEdit
{
    Q_OBJECT
public:
    CounterEdit(const QString & contents, QWidget * parent =    0):
        QLineEdit(contents,parent){}
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str=text(); // объекту класса QString str присваивается поле ввода в главном окне приложения
        int r=str.toInt(); // преобразуем символное представление числа в целочисленный тип
        if ((r!=0) && (r%5 == 0)) emit tick_signal(); // ?
        r++; // инкрементируем R
        str.setNum(r); // записываем число r в строку str, теперь r опять строкового типа
        setText(str); // покажем на экране инкрементацию числа, находящегося в строке str
    }
};
///////////////////////////////////////////////////////////////////////////////////
// WIDGET CLASS
class Widget : public QWidget
{
    Q_OBJECT
protected:
    QLabel * leftlabel,* rightlabel;
    CounterEdit * edit1,* edit2;
    QPushButton * calcbutton;
    QPushButton * exitbutton;
    QFrame * leftframe, * rightframe;
public:
    Widget(QWidget * parent = 0);
    ~Widget();
    void createFormInterier();
    void Events();
};
/////////////////////////////////////////////////////////////////////////////////////

#endif // WIDGET_H
