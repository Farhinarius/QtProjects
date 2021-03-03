#include "fileclass.h"
#include "additems.h"

/************************************************************************************
 CREATE FILE PROPERTIES AND FUNCTIONS, THAT CAN ALLOW TO WORK WITH FILE
*************************************************************************************/


// CREATE FILE STARTING LOCATION, CREATE AND OPEN FILE
FileClass::FileClass()
{
    QString location =         // set name of starting location of file (string)
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    location.append("/file.feds"); // add name

f = new QFile(location);   // create file in choosen directory
                           // create on desktop in current case
f->open(QFile::ReadWrite); // open file
}

// DESTRUCTOR OF FILE (delete file)
FileClass::~FileClass()   // деструктор
{
    f->close();         // close file
    delete f;           // free memory
}


// ADD RECORD IN FILE
bool FileClass::addRec(recType r)
{
    f->seek(f->size());                        // переходим на конец файла
    QDataStream out(f);                        // связываем с файлом поток вывода
    out<<r.name<<r.company<<r.year<<r.memory;  // выводим данные в файл
        return true;
}

// RESET FILE FUNCTION
bool FileClass::reSetFile()
{
    f->reset();
    return true;
}

// SEARCH MEMORY < 64
bool FileClass::searchmemory(QString current_year, QString &search_name)
{

    QDataStream input(f); // связываем с файлом поток ввода

    if (input.atEnd())
        return false;
    else
    {
        input>>r.name>>r.company>>r.year>>r.memory; // read all data in file
        if (r.year.toInt() == current_year.toInt())  // if "year in file" = "entered year" than
        {
          if (r.memory.toInt()<64)                   // if memory < 64
            {
               search_name = r.name;                 // find file what we are looking for
            }
        }
    return true;
    }
}

// SEARCH SOFTWARE BY DEVELOPER AND PERIOD OF DEVELOPMENT
bool FileClass::searchname(QString entered_developer,QString start_dev,QString end_dev, QString &search_name)
{
    QDataStream in(f); // связываем с файлом поток ввода

    if (in.atEnd())
        return false;
    else
    {
        in>>r.name>>r.company>>r.year>>r.memory; // read all data in file
        if (r.company == entered_developer)
            {
            if (r.year.toInt() >= start_dev.toInt() and r.year.toInt() <= end_dev.toInt())
            {
                search_name = r.name;
            }

            }
        return true;
    }
}

// GET INFO ABOUT PROGRAMM
bool FileClass::searchitem(QString name_of_prog, QStringList &product_info)
{

    QDataStream in(f); // связываем с файлом поток ввода
    //*s = new QString[3];
    if (in.atEnd())
        return false;
    else
    {
        in>>r.name>>r.company>>r.year>>r.memory; // read all data in file
        if (r.name == name_of_prog)
        {
            product_info.clear();
         product_info << r.name;
         product_info <<  r.company;
         product_info <<  r.year;
         product_info <<  r.memory;
        }
        else
        {
         product_info[0] = "Information doesn't exist";
        }
        return true;
    }



}

// DELETE FILE
bool FileClass::deleteline(QString entered_name)
{
    QFile *ftmp;
    QString location =
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
 location.append("/file1.feds");

 ftmp = new QFile(location);// создаем объект-файл

 ftmp->open(QFile::ReadWrite); // prepare file for reading and writing
 QDataStream in(f);         // Input Stream file f
 ftmp->seek(ftmp->size()); // переходим на конец файла
 QDataStream out(ftmp); // связываем с файлом поток вывода file ftmp

 while (!in.atEnd())      // while Input stream of file not in END OF FILE
 {
     in >> r.name >> r.company >> r.year >> r.memory; // read all data in file
     if (r.name == entered_name)
     {

     }
     else {
        out<<r.name<<r.company<<r.year<<r.memory;
     }

 }
   f->resize(0);
   ftmp->seek(0);

 while (!out.atEnd())
 {
     out>>r.name>>r.company>>r.year>>r.memory;
     in<<r.name<<r.company<<r.year<<r.memory;
 }
 ftmp->remove();
 delete ftmp;
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////
/// \brief FileClass::getMinMaxAndUnicItem
/// \param a
/// \param b
/// \param c
/// \param d
/// \return
///
bool FileClass::getMinMaxAndUnicItem(int &a, int &b, QStringList &c, QStringList &d){
    f->seek(0);
    QDataStream in(f);
    QDataStream in1(f);// связываем с файлом поток ввода
    int maxDate=0;
    int minDate=1000000;


    while (!in.atEnd())
    {
     in>>r.name>>r.company>>r.year>>r.memory;
        if(r.year.toInt()<=minDate){
            minDate=r.year.toInt();
        }
        if(r.year.toInt()>=maxDate){
            maxDate=r.year.toInt();
        }


    }

    int *count=new int [maxDate-minDate];
    int *count2= new int [maxDate-minDate];
    int j=0;
    for (int i = minDate;i<=maxDate;i++) {
        count[j]=i;
        c<<QString::number(i);
        j++;
    }
    f->seek(0);
    int contint(0);
    for (int i=0;i<=maxDate-minDate;i++) {

f->seek(0);
contint=0;
    while (!in.atEnd()){
         in>>r.name>>r.company>>r.year>>r.memory;
        if(r.year.toInt()==c[i].toInt()){
            contint++;
            }

    }
    count2[i]=contint;
    d<<QString::number(contint);
    }
    a=minDate;
    b=maxDate;


      return true;
}
