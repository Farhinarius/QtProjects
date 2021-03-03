#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QValidator>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextCodec>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QString>

 // MAIN CLASS WIDGET
class Widget : public QWidget
{
    Q_OBJECT

protected:
       QTextCodec * codec;
        QFrame * frame;               // рамка
        QLabel * inputLabel;          // метка ввода
        QLineEdit * inputEdit;        // строчный редактор ввода
        QLabel * outputLabel;         // метка вывода
        QLineEdit * outputEdit;      // строчный редактор вывода
        QPushButton * nextButton;    // кнопка Следующее
        QPushButton * exitButton;    // кнопка Выход

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:

   void begin(); // метод начальной настройки интерфейса
   void calc();  // метод реализцаии вычислений
};

// VALIDATOR CLASS

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject * parent): QValidator(parent) // construtor inheritance
    {}

    virtual State validate(QString &str,int &pos) const
    {
        return Acceptable;  // метод всегда принимает вводимую строку
    }
};

#endif // WIDGET_H
