//
//

#include <person_file.h>
#include <unoccupied_number.h>

UnNum::UnNum()
{
 setWindowTitle("Free Num:");
  createWin3Interier();
  showAll();
}

void UnNum::createWin3Interier()
{

 // ОПИСАНИЕ ВСЕХ ОБЪЕКТОВ ОКНА, ИХ ХАРАКТЕРИСТИКИ
    // метка, показывающая что нужно выбрать в combobox


    // метка, показывающая вывод всех ежедневных изданий типографии
    all_free_numbers =
    new QLabel("Names of all free phone numbers",this);

    // вывод всех ежедневных изданий типографии в текстовом окне
    QStringList strlist;
    strlist << "Free Number";// заголовок для таблицы
    table = new QTableWidget(10,1,this);        //
    table->setHorizontalHeaderLabels(strlist);


    // описаник кнопок
    exit_button = new QPushButton("Close",this);
    show_info = new QPushButton("Show Info",this);


    resize(230,240);
 // ОПИСАНИЕ МЕНЕДЖЕРА КОМПОНОВКИ, ДЛЯ СОЗДАНИЯ ГЕОМЕТРИИ ВИДЖЕТОВ НА ФОРМЕ

 QGridLayout * grid = new QGridLayout(this);
  grid->addWidget(all_free_numbers,0,0,1,1);
  grid->addWidget(table,2,0,4,1);
  grid->addWidget(show_info,6,0,1,1);
  grid->addWidget(exit_button,7,0,1,1);


 // ОПИСАНИЕ СИГНАЛОВ ДЛЯ ФОРМЫ

  connect(exit_button,SIGNAL(clicked()),this,SLOT(close()));
  connect(show_info,SIGNAL(clicked()),this,SLOT(showAll()));
}

/*void TopHouse::fillBox()
{
    bookFile book;
    casebox->addItem("Kojima_Production");
    casebox->addItem("Blizzard");
    casebox->addItem("CDProjectRed");
}*/
///////////////////////////////////////////////////////////////////////////////////////////
///// ЗАПОЛНЯЕМ ОДНУ СТРОКУ ТАБЛИЦЫ
void UnNum::showRowOf(int i,recType zap)
{

        QTableWidgetItem * item;

       // item name;
       item = new QTableWidgetItem(); // создаем ячейку
       item->setFlags(Qt::NoItemFlags); //запрещаем веделение
       item->setText(zap.phone_number);  // присваиваем ячейке текст
       table->setItem(i,0,item); // заносим в таблицу
}

////////////////////////////////////////////////////////////////////////////////////////////
/// ИЩЕМ НЕ ЗАРЕГЕСТРИРОВАННЫЕ НОМЕРА
///
 void UnNum::showAll()
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
             if (book.record.subscriber_name == "" and book.record.owner_type == "" and
                     book.record.year_of_installation == "")
             {
                showRowOf(k++,book.record);
             }
            }
        }

}





















