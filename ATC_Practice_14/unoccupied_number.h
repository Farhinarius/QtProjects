#ifndef UNOCCUPIED_NUMBER_H
#define UNOCCUPIED_NUMBER_H

#include <add_person.h>
#include <person_file.h>

#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QComboBox>
#include <QTableWidget>
#include <QMessageBox>
#include <QString>


class UnNum: public QWidget
{
    Q_OBJECT
    // Mark for ComboBox
    QLabel * all_free_numbers;

    // Таблица
    QTableWidget * table;

    // exit
    QPushButton * exit_button, * show_info;
public:
    UnNum();

public slots:
    void createWin3Interier();
    void showRowOf(int i,recType zap);
    void showAll();
};


#endif // UNOCCUPIED_NUMBER_H
