#include "widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent)
{
  // описание параметров
/////////////////////////////////////////////////////////////////////////////////////////////////////////
  // ХАРАКТЕРИСТИКИ ВСЕХ ВИДЖЕТОВ part 1

  codec = QTextCodec::codecForName("Windows-1251");
  setWindowTitle("Square Degree");

  // создаем рамку (Frame) и выставляем её характеристики
  frame = new QFrame(this);
  frame->setFrameShadow(QFrame::Raised);
  frame->setFrameShape(QFrame::Panel);

  // характеристики inputLabel
  inputLabel = new QLabel("Input num:",this); // создаем метку "Введите число"


  // характеристика inputEdit
  inputEdit = new QLineEdit(this);   // создание поля ввода  // inputEdit = new QLineEdit("",this);
  StrValidator * V = new StrValidator(inputEdit); // создаем указзатель на объект класса,
                                                  // который привязан к inputEdit
  inputEdit->setValidator(V); // установить проверку ввода


  // харатеристики OutputLabel
  outputLabel = new QLabel("Result:", this); // создаем метку "Результат:"

  // харатеристики OutputEdit
  outputEdit = new QLineEdit(this); // создание поля вывода

  // характеристики двух кнопок
  nextButton = new QPushButton("Next", this);
  exitButton = new QPushButton("Exit", this);

////////////////////////////////////////////////////////////////////////////////////////////////////////
  // КОМПОНОВКА ВИДЖЕТОВ ПРИЛОЖЕНИЯ part 2

  // работа с левым сектором ввода и вывода
  QVBoxLayout * vLayout1 = new QVBoxLayout(frame); // создаем 1-ую вертикальную привязку к рамке
      vLayout1->addWidget(inputLabel);  // добавляем виджет inputLabel к вертиальной привязке
      vLayout1->addWidget(inputEdit);	// добавляем виджет inputEdit к вертикальной привязке
      vLayout1->addWidget(outputLabel); // добавляем виджет outputLabel к вертикальной привязке
      vLayout1->addWidget(outputEdit);  // добавляем виджет outputEdit к вертикальной привязке
      vLayout1->addStretch();   // создаем пружину которая привязывает раскладку к рамке окна

  // работа с правым сектором, кнопки и воспроизведение операций происходящих с левым сектором
  QVBoxLayout *vLayout2 = new QVBoxLayout(); // создание 2 вертикальной привязки для кнопок правого сектора окна
      vLayout2->addWidget(nextButton); // добавляем кнопку "следующее" к вертикальной привязке 2
      vLayout2->addWidget(exitButton); // добавляем кнопку "выйти" к вертикальной привязке 2
      vLayout2->addStretch();          // создаем пружину которая привязывает раскладку к рамке окна

  // Создание всего сектора ОКНА, привязка левой раскладки с правой, общая конструкция
  QHBoxLayout *hLayout = new QHBoxLayout(this);  // создание указателя горизонтальной привязки для всего окна
      hLayout->addWidget(frame); // добавляем виджет (рамку) к горизонтальной привязке
      hLayout->addLayout(vLayout2); // добавляем виджет (вертикальный привязка 2) к горизонтальной привязке

      begin(); // установка начальной раскладки для событий

//////////////////////////////////////////////////////////////////////////////////////////////////////////
  // СОЗДАНИЕ СОБЫТИЙ ДЛЯ ВСЕХ ОБЪЕКТОВ ГЛАВНОГО ОКНА part 3 (программирование слотов)

      //1. если нажата кнопка "выход", вызовем метод главного окна close() (наследуется из библиотеки)
      connect(exitButton,SIGNAL(clicked(bool)),
                  this,SLOT(close()));

      //2. если нажата кнопка "следующее", вызовем метод для главного окна begin(), который обновялет конфигурацию
      connect(nextButton,SIGNAL(clicked(bool)),
                  this,SLOT(begin()));

      //3. если после ввода в поле inputEdit нажата клавиша Enter, то вызовется метод calc() который возводит число в квадрат
      connect(inputEdit,SIGNAL(returnPressed()),
                  this,SLOT(calc()));

/////////////////////////////////////////////////////////////////////////////////////////////////////////
}

 // описание метода начальной раскладки приложения
 // будет использоваться каждый раз, после вычисления квадрата числа
void Widget::begin()
{
    inputEdit->clear();            // очищаем поле ввода inputLabel
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true); // приложение предложит работать с вводом поля inputEdit
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////


void Widget::calc()
{
    bool Ok=true;      double r,a;
    QString str=inputEdit->text(); // создаем объект - переменную str типа QString в которую запишем
    // число из поля inputEdit, которое в свою очередь передастя как символ, а не как числовой тип

    a=str.toDouble(&Ok); // конвертируем символьное представление числа в вещественный тип (чтобы работать с числом)
    if (Ok)  // если "правда" для булевской переменной OK
    {
        r=a*a;  // возводим число из поля inputEdit в квадрат
        str.setNum(r);           // запоминаем его в str (конвертируем обратно в строковой тип)
        outputEdit->setText(str); // число выведется у нас на экране в области outputEdit
        inputEdit->setEnabled(false); // в поле невозможно ничего ввести
        outputLabel->setVisible(true); // включена видимость
        outputEdit->setVisible(true); // включена видимость
        nextButton->setDefault(true); // возможность работы с кнопками
        nextButton->setEnabled(true);
        nextButton->setFocus();  // предлагает пользователю произвести операцию возведения в квадрат повторно
    }
    else
        if (!str.isEmpty()) // случай ошибки ввода
        {
            QMessageBox msgBox(QMessageBox::Information,
                codec->toUnicode("Error"),
                codec->toUnicode(" You input invalid value, please try again."),
                QMessageBox::Ok);
            msgBox.exec();
        }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
Widget::~Widget()
{

}
