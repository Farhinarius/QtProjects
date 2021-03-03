#ifndef SEARCHCLASS_H
#define SEARCHCLASS_H

#include <QMainWindow>
#include "fileclass.h"
#include <QtGui>

namespace Ui {
class SearchClass;
}

class SearchClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchClass(QWidget *parent = nullptr);
    ~SearchClass();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SearchClass *ui;
};

#endif // SEARCHCLASS_H
