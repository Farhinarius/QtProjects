#ifndef WIDGET_H
#define WIDGET_H

#include <add_person.h>
#include "char_all.h"
#include <unoccupied_number.h>
#include <individual_owners.h>
#include <graphic.h>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
        QPushButton * addButton,
                    * info1Button,
                    * info2Button,
                    * info3Button,
                    * info4Button,
                    * exitButton;
        addPerson widgetAdd;      // форма Добавления
        AllChar widgetChar;       // форма Отображение всех
        IndividualOwners widgetIO;
        UnNum widgetUnPhones;          // форма Поиска
        Graphic widgetGraphic;
public slots:
       void showWidgetAdd();   // показать форму Добавления
       void showWidgetChar(); // показать форму Отображения всех
       void showWidgetIO();  // показать форму Поиска
       void showWidgetUnPhones();
       void show_graphic();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void createMainWindowInterier();
};

#endif // WIDGET_H
