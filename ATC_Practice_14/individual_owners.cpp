//
//

#include <person_file.h>
#include <individual_owners.h>

IndividualOwners::IndividualOwners()
{
 setWindowTitle("Individual owners in selected year");
  createWin2Interier();
  fillBox();

}

void IndividualOwners::createWin2Interier()
{

 // ОПИСАНИЕ ВСЕХ ОБЪЕКТОВ ОКНА, ИХ ХАРАКТЕРИСТИКИ
    // метка, показывающая что нужно выбрать в combobox
    year_of_installation = new QLabel("Choose year of installation:",this);

    // combobox с оператором выбора типографии
    install_year_box = new QComboBox(this);

    // метка, показывающая вывод всех ежедневных изданий типографии
    all_member_in_year =
    new QLabel("All individual owners connected in a given year:",this);

    // вывод всех ежедневных изданий типографии в текстовом окне
    QStringList strlist;
    strlist << "Sub. Name" << "Individual owner" << "Phone Number";  // заголовок для таблицы
    table = new QTableWidget(10,3,this);        //
    table->setHorizontalHeaderLabels(strlist);


    // описание кнопок окна
    exit_button = new QPushButton("Close",this);
    show_info = new QPushButton("Show Info",this);
    refresh_button = new QPushButton("Refresh",this);

    resize(400,250);
    setMinimumSize(400,220);
    // ОПИСАНИЕ МЕНЕДЖЕРА КОМПОНОВКИ, ДЛЯ СОЗДАНИЯ ГЕОМЕТРИИ ВИДЖЕТОВ НА ФОРМЕ

 QGridLayout * grid = new QGridLayout(this);
  grid->addWidget(year_of_installation,0,0);
  grid->addWidget(install_year_box,0,1,1,2);
  grid->addWidget(all_member_in_year,1,0,1,2);
  grid->addWidget(table,2,0,3,3);
  grid->addWidget(exit_button,5,2);
  grid->addWidget(show_info,5,0);
  grid->addWidget(refresh_button,5,1);


 // ОПИСАНИЕ СИГНАЛОВ ДЛЯ ФОРМЫ

  connect(exit_button,SIGNAL(clicked()),this,SLOT(close()));
  connect(show_info,SIGNAL(clicked()),this,SLOT(showAll()));
  connect(refresh_button,SIGNAL(clicked()),this,SLOT(fillBox()));
}
/////////////////////////////////////////////////////////////////////////////
//// ЗАПОЛНЯЕМ fillbox, его поля будут применяться в функциях ниже, содержит поля файля
void IndividualOwners::fillBox()
{
    personFile book; // назовём это вызов существующего файла
    install_year_box->clear();
    while (book.readRecord())  // ?
    {
       if (install_year_box->currentText() != book.record.year_of_installation)
        install_year_box->addItem(book.record.year_of_installation);


    }
}
/////////////////////////////////////////////////////////////////////////////
//// ВСТАВЛЯЕМ ПОДХОДЯЩИЕ ДАННЫЕ В ТАБЛИЦУ, (эта функция будет вызываться в других функциях)
void IndividualOwners::showRowOf(int i,recType zap)
{

        QTableWidgetItem * item;

       // item name;
       item = new QTableWidgetItem(); // создаем ячейку
       item->setFlags(Qt::NoItemFlags); //запрещаем выделение
       item->setText(zap.subscriber_name);  // присваиваем ячейке текст
       table->setItem(i,0,item); // заносим в таблицу

       item = new QTableWidgetItem();
       item->setFlags(Qt::NoItemFlags);
       item->setText("ok");
       table->setItem(i,1,item);

       item = new QTableWidgetItem();
       item->setFlags(Qt::NoItemFlags);
       item->setText(zap.phone_number);
       table->setItem(i,2,item);
}
/////////////////////////////////////////////////////////////////////////////
/////// ИЩЕМ МАКСИМАЛЬНЫЙ ТИРАЖ, СРЕДИ ВСЕХ КНИГ В СТРУКТУРЕ КНИГ
/*int IndividualOwners::searchIndividualOwners()
{
   personFile book;
   int i = 0;  // counter
   recType printing_line[100]; // создаю массив структур(вместе с остальными данными),
   // который содержит продажность книг
   int num_printing_line[100]; // та же самая продажность, конвертированная в цифры

   // записываем количество печатей для каждкой книги в массив(статический) - по идее НЕправильно
   while (book.readRecord())  // ?
   {
       printing_line[i].printing = book.record.printing; // переписываем тиражи для каждой книги в другой
       // массив структур
       num_printing_line[i] = printing_line[i].printing.toInt(); // конвертируем в числа, записываем
       // в целочисленным массив
       i++;
   }

   // ищем максимальный элемент "количество печатей", для того, чтобы записать в таблицу
   int j = i; // запоминаем кол-во записей, количество элементов в массиве
   int max = 0; i = 0; // создаем нулевые переменные
   for (i = 0;i<j;i++) // создаем счётчик для поиска максимального тиража книги
   {
       if (num_printing_line[i]>num_printing_line[i+1]) // условие
            max = num_printing_line[i]; // нашли максимальный тираж, среди всех тиражей с помощью цикла
   }
   return max;
} */
/////////////////////////////////////////////////////////////////////////////////
///// ИЩЕМ ИНДИВИДУАЛЬНЫЙ ВЛАДЕЛЬЦЕВ НОМЕРОВ ДЛЯ ЗАДАННОГО ГОДА
void IndividualOwners::showAll()
{


  personFile book;
   if (!book.readRecord())
   {    // если файл пустой , то создаем сообщение
       QMessageBox msg(QMessageBox::Critical,
               "error info",
               "information don't exist",
               QMessageBox::Ok,0);
       msg.exec(); // выводим сообщение
   }
   else
   {
       showRowOf(0,book.record); // заполняем одну строку
       int k = 0;
       while (book.readRecord())
       {
        if (install_year_box->currentText() == book.record.year_of_installation and
                book.record.owner_type == "individual")
        {
           showRowOf(++k,book.record);
        }
       }
   }

}
////////////////////////////////////////////////////////////////////////////////////////////




















