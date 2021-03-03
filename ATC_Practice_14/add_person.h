#ifndef ADD_PERSON_H
#define ADD_PERSON_H

#include <QtGui>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>

class addPerson : public QWidget
{
    Q_OBJECT
    // Marks for zap structure;
    QLabel * subscriber_name, // ФИО абонента
           * owner_type,   // тип владельца (индивидуальный, коллективный),
           * phone_number,     // номер телефона
           * year_of_installation; // год установки

    // Edit for zap structure;
    QLineEdit * edit_name,
              * edit_phone_number,
              * edit_year_of_install;

    // ComboBox for definite selection
    QComboBox * owner_type_box;

    // create button Add Person and button exit
    QPushButton * buttonAddPerson, * buttonExitWindow;
public:
    addPerson();
public slots:
    void addRecord();
    void createAddPersonInterier();
};



#endif // ADD_PERSON_H
