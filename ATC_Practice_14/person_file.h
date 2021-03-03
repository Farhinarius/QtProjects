#ifndef PERSON_FILE_H
#define PERSON_FILE_H

#include <QFile>
#include <QMessageBox>
#include <QDataStream>
#include <QString>

//////////////////////////////////////////////////////////////////////
struct recType   // структура записи для одного абонента
{
    QString subscriber_name, // ФИО абонента
            owner_type,      // тип владельца (индивидуальный, коллективный),
            phone_number,       // номер телефона
            year_of_installation; // год установки

};

//////////////////////////////////////////////////////////////////////
// СОЗДАЕМ КЛАСС В КОТРОМ ХРАНИТСЯ ОБЪЕКТ ФАЙЛ, И ПРИВЯЗЫВАЕМ К НЕМУ МЕТОДЫ

class personFile // создание класса с объявлением поля-объекта файла
               // (указатель) на который нужно выделить память
 {
    QFile * f;    // указатель на объект класса QFile
    bool k1,k2,k3,k4,ff; // ключи поиска
 public:
    recType record;  // структура записи, все информационные поля для ввода
    int i; // индексация файла
    personFile();  // конструктор
    ~personFile(); // деструктор
    bool addRec(recType r); // добавление записи в файл
    bool readRecord();	    // чтение записи из файла
    bool findFirst(const recType r1); // поиск первой
                                      // записи, удовлетворяющей условию
    bool findNext(const recType r1);
                       // поиск следующей записи
public slots:
     void free_mem();  // освобождает память
};

/////////////////////////////////////////////////////////////////////////


#endif // PERSON_FILE_H
