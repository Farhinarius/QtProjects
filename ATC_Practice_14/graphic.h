#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <person_file.h>
#include <add_person.h>

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include <QMessageBox>
#include <QPoint>



class Graphic : public QWidget
{
    QPushButton * createGraphic, *exitButton;
    QPainter * painter;
    // QLabel * printing, * printing_house;

    public:

    Graphic();
    void createWin4Interier();


    public slots:
   // void BuildGraphic();
    void paintEvent(QPaintEvent *e);
  //  void timerEvent(QTimerEvent *event);
  //  void showEvent(QShowEvent *event);
  //  void hideEvent(QHideEvent *event);
};

#endif // GRAPHIC_H
