#ifndef FILECLASS_H
#define FILECLASS_H

#include <QFile>
#include <QIODevice>
#include <QArrayData>
#include "QMessageBox"
#include "QStandardPaths"
#include <QTextStream>
#include <map>


struct recType
{
    QString name, company,
            year, memory;
};

class FileClass
{
public:
    QFile * f;

public:
    recType r;
    bool addRec(recType );
    bool searchmemory(QString ,QString &);
    QString findmemory(int m);
    FileClass();
    ~FileClass();
    bool reSetFile();
    bool deleteline(QString );
    bool searchitem(QString , QStringList &);
    bool searchname(QString t,QString t2,QString t3,QString &s);
    bool getMinMaxAndUnicItem(int &a, int &b, QStringList &c, QStringList &d);
};

#endif // FILECLASS_H
