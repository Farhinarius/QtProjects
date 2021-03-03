//
//

#include <person_file.h>
#include <char_all.h>

AllChar::AllChar()
{
 setWindowTitle("All member of num INFO");
  createWin1FormInterier();
  fillBox();
}

void AllChar::createWin1FormInterier()
{

 // ОПИСАНИЕ ВСЕХ ОБЪЕКТОВ ОКНА, ИХ ХАРАКТЕРИСТИКИ
    // метка, показывающая что нужно выбрать в combobox
    phone_number = new QLabel("Choose number:",this);

    // combobox с оператором выбора типографии
    phone_number_box = new QComboBox(this);

    // метка, показывающая вывод всех ежедневных изданий типографии
    all_characteristic =
    new QLabel("All Characteristic of subcriber with choosen number:",this);

    // вывод всех ежедневных изданий типографии в текстовом окне
    QStringList strlist;
    strlist << "Sub. Name" << "Owner type" << "Year of Install";  // заголовок для таблицы
    table = new QTableWidget(10,3,this);        //
    table->setHorizontalHeaderLabels(strlist);


    // описаник кнопок
    exit_button = new QPushButton("Close",this);
    show_info = new QPushButton("Show Info",this);
    refresh_button = new QPushButton("Refresh Data in Box",this);

    resize(400,250);
 // ОПИСАНИЕ МЕНЕДЖЕРА КОМПОНОВКИ, ДЛЯ СОЗДАНИЯ ГЕОМЕТРИИ ВИДЖЕТОВ НА ФОРМЕ

 QGridLayout * grid = new QGridLayout(this);
  grid->addWidget(phone_number,0,0);
  grid->addWidget(phone_number_box,0,1,1,2);
  grid->addWidget(all_characteristic,1,0,1,2);
  grid->addWidget(table,2,0,3,3);
  grid->addWidget(exit_button,5,2);
  grid->addWidget(refresh_button,5,1);
  grid->addWidget(show_info,5,0);

 // ОПИСАНИЕ СИГНАЛОВ ДЛЯ ФОРМЫ

  connect(exit_button,SIGNAL(clicked()),this,SLOT(close()));
  connect(show_info,SIGNAL(clicked()),this,SLOT(showAll()));
  connect(refresh_button,SIGNAL(clicked()),this,SLOT(fillBox()));
}


void AllChar::showRowOf(int i,recType zap)
{

        QTableWidgetItem * item;
       // item name;
       item = new QTableWidgetItem(); // создаем ячейку
       item->setFlags(Qt::NoItemFlags); //запрещаем веделение
       item->setText(zap.subscriber_name);  // присваиваем ячейке текст
       table->setItem(i,0,item); // заносим в таблицу

       item = new QTableWidgetItem();
       item->setFlags(Qt::NoItemFlags);
       item->setText(zap.owner_type);
       table->setItem(i,1,item);

       item = new QTableWidgetItem();
       item->setFlags(Qt::NoItemFlags);
       item->setText(zap.year_of_installation);
       table->setItem(i,2,item);
}

void AllChar::showAll()
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
             {   // иначе - выводим таблицу по строкам
                showRowOf(0,book.record); // заполняем одну строку
                int i=0;
                while (book.readRecord())// пока читаем запись
                {
                    if (phone_number_box->currentText() == book.record.phone_number)
                 {
                  showRowOf(i++,book.record); // запишем строку записи,
                  // записи теперь индексуются с помощью этой функции
                 }
                }
               // table->setRowCount(i+1);
                //show();
             }
}


void AllChar::fillBox()
{
    personFile book;
    phone_number_box->clear();
    while (book.readRecord())
    {
      if (phone_number_box->currentText() != book.record.phone_number)
        phone_number_box->addItem(book.record.phone_number);
    }
}
