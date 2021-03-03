#include "person_file.h"
#include "widget.h"

// работа с объявлениями в заголовочном фалйе bookFile.h

personFile::personFile()  // конструктор
{
///////////////////////////////////////////////////////////
// выделяем память на поле класса book_file, поле которого является файлом объектом
    f = new QFile("person_info.txt");// создаем объект-файл

// ОТКРЫВАЕМ ФАЙЛ ДЛЯ ВВОДА-ВЫВОДА В КОНСТРУКТОРЕ
    f->open(QFile::ReadWrite);

    // Условие, если файл не создался
    if(!f->exists()) // если файл не существует, то
    {      // формирмируем сообщение
        QMessageBox msg(QMessageBox::Critical,
               "Can't find file",
               "File book.txt has not been created",
               QMessageBox::Ok,0);
        msg.exec();// выводим сообщение на экран
    }
}
/////////////////////////////////////////////////////////
// destructor
personFile::~personFile()   // деструктор
{
    f->close();        // закрываем файл
    delete f;                        // освобождаем память
}
////////////////////////////////////////////////////////
// ФУНКЦИЯ ДОБАВЛЕНИЯ ЗАПИСИ В ФАЙЛ
bool personFile::addRec(recType record) // передаем файл как аргумент
{

    f->seek(f->size()); // переходим на конец файла
    QDataStream out(f); // связываем с файлом f поток вывода out
    out<<record.subscriber_name<<record.owner_type<<record.phone_number<<record.year_of_installation;
    // выводим данные в файл
    return true; // данные ввелись успешно
}

///////////////////////////////////////////////////////
// ФУНКЦИЯ CЧИТЫВАНИЯ ФАЙЛА
bool personFile::readRecord()
{
    QDataStream in(f);           // связываем с файлом поток ввода
    if (in.atEnd())return false; // если указатель ввода в конце,
                                 // то приостанавливаем ввод файла
    else // иначе, (если указатель ввода не в конце)
    {
        // осуществим поток ввода
        in >> record.subscriber_name >> record.owner_type >> record.phone_number >> record.year_of_installation;
        return true; // поток ввода прошёл успешно
    }
}

void personFile::free_mem()
{
    f->remove("person_info.txt");
}

/////////////////////////////////////////////////////////
// ФУНКЦИЯ ПОИСКА ПЕРВОЙ ЗАПИСИ
/*bool bookFile::findFirst(const recType r1) // передаем файл как аргумент
{
     k1=(r1.fam=="");   // устанавливаем два ключа поиска
     k2=(r1.name=="");
     ff=false;   // устанавливаем ключ поиска «запись не найдена»
    f->reset();
    bool fff = readRecord();
    while(fff &&(!ff)) // пока читается запись и запись найдена,то
    {
        k3=(r1.fam==r.fam);  //строим еще два ключа поиска
          k4=(r1.name==r.name);
          if ((!k1 && !k2 && k3 && k4)||
             (!k1 && k2 && k3)||
             (k1 && !k2 && k4))
            ff=true; // ключ поиска «запись найдена»
        else fff=readRecord();
    }
    return ff; // возвращаем ключ поиска
} */

////////////////////////////////////////////////////////////
// ПОИСК ВТОРОЙ ЗАПИСИ В ФАЙЛЕ
/*bool bookFile::findNext(const recType r1) // передаем файл как аргумент
{
    ff=false;   // ключ поиска «запись не найдена»
    bool fff = readRecord();
    while((!ff) && fff)  // пока запись найдена и файл считывается, то
    {
        k3=(r1.fam==r.fam);//строим еще два ключа поиска
          k4=(r1.name==r.name);
          if ((!k1 && !k2 && k3 && k4)||
              (!k1 && k2 && k3)||
              (k1 && !k2 && k4))
            ff=true;     // ключ поиска «запись найдена»
        else fff=readRecord();
    }
    return ff; // возвращаем ключ поиска
} */

/////////////////////////////////////////////////
