//
//

#include <graphic.h>



Graphic::Graphic()
{
 setWindowTitle("Graphic creation");
 resize(900,450);
 setMinimumSize(900,450);
 createWin4Interier();

 // EVENTS IN WIDGET
 connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
 connect(createGraphic,SIGNAL(clicked()),this,SLOT(paintEvent(QPaintEvent *e)));

}

void Graphic::paintEvent(QPaintEvent * e)
{
    painter = new QPainter(this);
   // painter->drawLine(10,10,100,100);

    QPen axisPen(Qt::black);
    axisPen.setWidth(2);


    // СОЗДАНИЕ ОСИ ДЛЯ ПОСТРОЕНИЯ БУДУЩЕЙ МОДЕЛИ
    painter->setPen(axisPen);
    painter->drawLine(120,40,120,400);
    painter->drawLine(120,400,650,400);

    painter->setFont(QFont("Welcome",8));
    painter->drawText(8,36,"Number of released numbers");
    painter->drawText(665,400,"Year");

    // СОЗДАНИЕ РАЗМЕТОК ДЛЯ ВЕРТИКАЛЬНОЙ ОСИ ГРАФИКА
    painter->setPen(axisPen);
    painter->drawLine(115,300,125,300);
    painter->drawLine(115,200,125,200);
    painter->drawLine(115,100,125,100);

    // ИМЕНУЕМ РАЗМЕТКИ ДЛЯ ВЕРТИКАЛЬНОЙ ОСИ
    painter->setFont(QFont("Welcome",8));
    painter->drawText(90,300,"few");
    painter->drawText(72,200,"average");
    painter->drawText(85,100,"many");

    // СОЗДАНИЕ РАЗМЕТОК ДЛЯ ГОРИЗОНТАЛЬНОЙ ОСИ ГРАФИКА
    painter->setPen(axisPen);
    painter->drawLine(120+100,400-5,120+100,400+5);
    painter->drawLine(120+100*2,400-5,120+100*2,400+5);
    painter->drawLine(120+100*3,400-5,120+100*3,400+5);
    painter->drawLine(120+100*4,400-5,120+100*4,400+5);
    painter->drawLine(120+100*5,400-5,120+100*5,400+5);

    // ИМЕНУЕМ РАЗМЕТКИ ДЛЯ ГОРИЗОНТАЛЬНОЙ ОСИ
    painter->setFont(QFont("Welcome",8));
    painter->drawText(150,420,"1970-1980");
    painter->drawText(250,420,"1980-1990");
    painter->drawText(350,420,"1990-2000");
    painter->drawText(450,420,"2000-2010");
    painter->drawText(550,420,"2010-2020");

    // painter->drawText(rect(), Qt::AlignCenter, "Qt");

    // СОЗДАЕМ КАРАНДАШ ДЛЯ ЛЕГЕНДЫ
    QPen legendPen(Qt::black);
    legendPen.setWidth(1);
    painter->setPen(legendPen);

    // СОЗДАЕМ ЛЕГЕНДУ
    painter->drawRect(600,20,10,10);
    painter->fillRect(600,20,10,10,Qt::red);
    painter->drawText(620,30," -  Count of all selled numbers");

    painter->drawRect(600+60,40,10,10);
    painter->fillRect(600+60,40,10,10,Qt::darkMagenta);
    painter->drawText(620+60,50,"  -   1970-1980");

    painter->drawRect(600+60,60,10,10);
    painter->fillRect(600+60,60,10,10,Qt::darkGreen);
    painter->drawText(620+60,70,"  -   1980-1990");

    painter->drawRect(600+60,80,10,10);
    painter->fillRect(600+60,80,10,10,Qt::darkYellow);
    painter->drawText(620+60,90,"  -   1990-2000");

    painter->drawRect(600+60,100,10,10);
    painter->fillRect(600+60,100,10,10,Qt::darkCyan);
    painter->drawText(620+60,110,"  -   2000-2010");

    painter->drawRect(600+60,120,10,10);
    painter->fillRect(600+60,120,10,10,Qt::darkBlue);
    painter->drawText(620+60,130,"  -   2010-2020");


///////////////////////////////////////////////////////////////////////////////////////////////
   // РИСОВАНИЕ ГРАФИКА, ПУТЕМ СЧИТЫВАНИЯ ДАННЫХ ИЗ ФАЙЛА

     personFile book;
     if (!book.readRecord())
     {    // если файл пустой , то создаем сообщение
         QMessageBox msg(QMessageBox::Critical,
                 "error info",
                 "information don't exist",
                 QMessageBox::Ok,0);
         msg.exec(); // выводим сообщение
     }
     else
     {
         int k7080 = 0,
             k8090 = 0,
             k9000 = 0,
             k0010 = 0,
             k1020 = 0;

         while (book.readRecord())
         {
            if (book.record.year_of_installation.toInt()>=1970 and  // 1
                    book.record.year_of_installation.toInt()<1980)
                    k7080++;
            if (book.record.year_of_installation.toInt()>=1980 and  // 2
                    book.record.year_of_installation.toInt()<1990)
                    k8090++;
            if (book.record.year_of_installation.toInt()>=1990 and  // 3
                    book.record.year_of_installation.toInt()<2000)
                    k9000++;
            if (book.record.year_of_installation.toInt()>=2000 and  // 4
                    book.record.year_of_installation.toInt()<2010)
                    k0010++;
            if (book.record.year_of_installation.toInt()>=2010 and  // 5
                    book.record.year_of_installation.toInt()<2020)
                    k1020++;
         }

      ///////////////////////////////////////////////////////////////////////////
       QPoint pref(120,400);  // начало графика
        int k = 100; // смещение ячейки по x

      if (k7080 > 0) // если существует телефонные номера с 70-ых по 80-ые годы
      {
      QPen line1; // создаём карандаш и настраиваем его характеристики
      line1.setColor(Qt::red); // устанавливаем цвет
      line1.setWidth(1); // толщина
       painter->setPen(line1); // устанавливаем объекту, отвечающему за рисование выбранный карандаш

       QPoint next(170,400-k7080*100);
        painter->drawLine(pref,next);
         pref = next;

       QPen explain;
       explain.setColor(Qt::darkMagenta);
       explain.setStyle(Qt::DashLine);
       explain.setWidth(1);
       painter->setPen(explain);
       painter->drawLine(170,400-k7080*100,170,400);

       QPen explaining;
       explain.setColor(Qt::black);
       explain.setStyle(Qt::DashLine);
       explain.setWidth(1);
       painter->setPen(explaining);
       painter->drawLine(120,400-k7080*100,170,400-k7080*100);
      }

      if (k8090 > 0) // если существует телефонные номера с 70-ых по 80-ые годы
      {
      QPen line1; // создаём карандаш и настраиваем его характеристики
      line1.setColor(Qt::red); // устанавливаем цвет
      line1.setWidth(1); // толщина
      painter->setPen(line1); // устанавливаем объекту, отвечающему за рисование выбранный карандаш

      QPoint next(170+k,400-k8090*100);
       painter->drawLine(pref,next);
         pref = next;

         QPen explain;
         explain.setColor(Qt::darkGreen);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explain);
         painter->drawLine(170+k,400-k8090*100,170+k,400);

         QPen explaining;
         explain.setColor(Qt::black);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explaining);
         painter->drawLine(120,400-k8090*100,170+k,400-k8090*100);


      }

      if (k9000 > 0) // если существует телефонные номера с 70-ых по 80-ые годы
      {
      QPen line1; // создаём карандаш и настраиваем его характеристики
      line1.setColor(Qt::red); // устанавливаем цвет
      line1.setWidth(1); // толщина
      painter->setPen(line1); // устанавливаем объекту, отвечающему за рисование выбранный карандаш

      QPoint next(170+2*k,400-k9000*100);
       painter->drawLine(pref,next);
         pref = next;

         QPen explain;
         explain.setColor(Qt::darkYellow);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explain);
         painter->drawLine(170+2*k,400-k9000*100,170+2*k,400);

         QPen explaining;
         explain.setColor(Qt::black);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explaining);
         painter->drawLine(120,400-k9000*100,170+2*k,400-k9000*100);


      }

      if (k0010 > 0) // если существует телефонные номера с 70-ых по 80-ые годы
      {
      QPen line1; // создаём карандаш и настраиваем его характеристики
      line1.setColor(Qt::red); // устанавливаем цвет
      line1.setWidth(1); // толщина
      painter->setPen(line1); // устанавливаем объекту, отвечающему за рисование выбранный карандаш

      QPoint next(170+3*k,400-k0010*100);
       painter->drawLine(pref,next);
         pref = next;

         QPen explain;
         explain.setColor(Qt::darkCyan);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explain);
         painter->drawLine(170+3*k,400-k0010*100,170+3*k,400);

         QPen explaining;
         explain.setColor(Qt::black);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explaining);
         painter->drawLine(120,400-k0010*100,170+3*k,400-k0010*100);

      }

      if (k1020 > 0) // если существует телефонные номера с 70-ых по 80-ые годы
      {
      QPen line1; // создаём карандаш и настраиваем его характеристики
      line1.setColor(Qt::red); // устанавливаем цвет
      line1.setWidth(1); // толщина
      painter->setPen(line1); // устанавливаем объект, отвечающему за рисование выбранный карандаш

      QPoint next(170+4*k,400-k1020*100);
       painter->drawLine(pref,next);
         pref = next;

         QPen explain;
         explain.setColor(Qt::darkBlue);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);
         painter->setPen(explain);
         painter->drawLine(170+4*k,400-k1020*100,170+4*k,400);

         QPen explaining;
         explain.setColor(Qt::black);
         explain.setStyle(Qt::DashLine);
         explain.setWidth(1);

         painter->setPen(explaining);
         painter->drawLine(120,400-k1020*100,170+4*k,400-k1020*100);

      }



  } // end of else for book





} // end of paintEvent

/* void Graphic::BuildGraphic()
{
    bookFile book;

     if (!book.readRecord())
     {    // если файл пустой , то создаем сообщение
         QMessageBox msg(QMessageBox::Critical,
                 "error info",
                 "information don't exist",
                 QMessageBox::Ok,0);
         msg.exec(); // выводим сообщение
     }
     else
     {
         int Kojima_printing_house_best = 0;
         int Blizzard_printing_house_best = 0;
         int CDProjectRed_printing_house_best = 0;
         int a = 0,b = 0,c = 0;
         //  recType zap[100];
         while (book.readRecord())
         {
             if (book.record.printing_house == "Kojima_Production")
             {
                 Kojima_printing_house_best += book.record.printing.toInt();
                 ++a;
             }
             if (book.record.printing_house == "Blizzard")
             {
                 Blizzard_printing_house_best += book.record.printing.toInt();
                 ++b;
             }
             if (book.record.printing_house == "CDProjectRed")
             {
                 CDProjectRed_printing_house_best += book.record.printing.toInt();
                 ++c;
             }
         }

         QPen RectPen(Qt::black);
         RectPen.setWidth(1);
         painter->setPen(RectPen);

         // drawing Kojima Rect //
         painter->drawRect(120,400,175,-Kojima_printing_house_best/(10*a));
         painter->fillRect(120,400,175,-Kojima_printing_house_best/100,Qt::black);

         // drawing Blizzard Entertainment Rect //
         painter->drawRect(120+175,400,175,-Blizzard_printing_house_best/(10*b));
         painter->fillRect(120+175,400,175,-Blizzard_printing_house_best/100,Qt::blue);

         // drawing Blizzard Entertainment Rect //
         painter->drawRect(120+175*2,400,175,-CDProjectRed_printing_house_best/(10*c));
         painter->fillRect(120+175*2,400,175,-CDProjectRed_printing_house_best/100,Qt::red);
}

} */

 void Graphic::createWin4Interier()
 {
     // ОПИСАНИЕ ОБЪЕКТОВ НА ВИДЖЕТЕ
     createGraphic = new QPushButton("Build Graphic",this);
     createGraphic->setGeometry(780,20,105,30);

     exitButton = new QPushButton("Close",this);
     exitButton->setGeometry(780,60,105,30);

 }



















