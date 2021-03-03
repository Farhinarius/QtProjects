#ifndef DELETECLASS_H
#define DELETECLASS_H

#include <QMainWindow>
#include "fileclass.h"
namespace Ui {
class DeleteClass;
}

class DeleteClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteClass(QWidget *parent = nullptr);
    ~DeleteClass();

private slots:
    void on_pushButton_2_clicked();
     void on_pushButton_clicked();

private:
    Ui::DeleteClass *ui;
};

#endif // DELETECLASS_H
