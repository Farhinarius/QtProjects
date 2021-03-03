#ifndef CHAR_ALL_H
#define CHAR_ALL_H

#include "add_person.h"
#include "person_file.h"
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>

class AllChar : public QWidget
{
    Q_OBJECT
    // Mark for ComboBox
    QLabel * phone_number, * all_characteristic;

    // ComboBox
    QComboBox * phone_number_box;

    // Таблица
    QTableWidget * table;

    // exit
    QPushButton * exit_button,
                * show_info,
                * refresh_button;

public:
    AllChar();
public slots:
     // реализация combobox c файлом
     // заполнение в combobox
     void createWin1FormInterier();
     void fillBox();
    // void BoxOperation();
     void showRowOf(int i,recType zap);
     void showAll();
    // void showResults(recType r1); // показать результаты поиска
};

#endif // CHAR_ALL_H
