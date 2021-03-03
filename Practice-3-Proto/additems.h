#ifndef ADDITEMS_H
#define ADDITEMS_H

#include <QMainWindow>
#include <QLineEdit>
namespace Ui {
class AddItems;
}

class AddItems : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddItems(QWidget *parent = nullptr);
    ~AddItems();

private slots:
    void on_pushButton_2_clicked(); // add record

    void on_pushButton_clicked(); // close window

private:
    Ui::AddItems *ui;
};

#endif // ADDITEMS_H
