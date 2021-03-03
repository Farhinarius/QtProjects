#ifndef INDIVIDUAL_OWNERS_H
#define INDIVIDUAL_OWNERS_H


#include <add_person.h>
#include <char_all.h>

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QMessageBox>

class IndividualOwners : public QWidget
{
    Q_OBJECT
    //////////////////////////
    // Mark for ComboBox
    QLabel * year_of_installation, * all_member_in_year;

    // ComboBox
    QComboBox * install_year_box;

    // Таблица
    QTableWidget * table;

    // exit
    QPushButton * exit_button, * show_info, * refresh_button ; // * refresh_button;

public:
    IndividualOwners();
    void createWin2Interier();
public slots:
    void fillBox();
   // int  searchIndividualOwners();
    void showRowOf(int i,recType r);
    void showAll();

};

#endif // INDIVIDUAL_OWNERS_H
