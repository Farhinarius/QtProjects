#include "graphicclass.h"
#include "ui_graphicclass.h"

#include<QtCharts/qlineseries.h>
#include<QtCharts/qchart.h>
#include<QtCharts/qchartview.h>
#include<QVector>
#include<QDataStream>
#include<iostream>
#include <QDebug>
#include <QtCharts/QLegend>
#include <QtCharts/QBarSet>

QT_CHARTS_USE_NAMESPACE

GraphicClass::GraphicClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicClass)
{
    ui->setupUi(this);
}

GraphicClass::~GraphicClass()
{
    delete ui;
}

void GraphicClass::on_pushButton_2_clicked()
{
    // ---------- DECLARE VARIABLES
           FileClass file;
           QVector<QString> vec;     // create vector 1
           QVector<QString> vecsort; // create vector 2
           QVector<QString> masvec[100]; // create vector 3
           QDataStream stream(file.f);  // create stream for file
           int i=0;
           QLineSeries * series = new QLineSeries;


/************************************************TRANSFER DATA TO NEW VECTOR*****************************************************/

           file.f->open(QFile::ReadWrite); // prepare file for read and write
           while(!file.f->atEnd()) // if file isn't ending work with all stream consistently,
            {
            stream >> vecsort; // add file data to vector
            if (vecsort[0] == ui->lineEdit->text()) // if entered name exist in file
            {
                masvec[i] = vecsort;
                i++;     // eventually "masvec" contain /entered name/ file data
            }
        }
/***************************************************SORTING VECTOR ELEMENTS*****************************************************/
        for (int j = 0; j < i - 1; j++)
        {
            for (int var = 0; var < i - j - 1; ++var)
            {
                if (masvec[var][2].toInt() > masvec[var+1][2].toInt())
                {
                    swap(masvec[var][0], masvec[var+1][0]);   // NAME OF PRODUCT
                    swap(masvec[var][1], masvec[var+1][1]);   // ! DATE SORTING
                    swap(masvec[var][2], masvec[var+1][2]);   // NAME OF DEVELOPER
                    swap(masvec[var][3], masvec[var+1][3]);   // ! MEMORY SORTING
                }
            }
        }
/*******************************************************************************************************************************/
        // add all elements in vector inLine Series
        for (int j=0; j < i; j++)
        {
            series->append(masvec[j][1].toInt(), masvec[j][3].toInt());  // xAxis - date; yAxis - Memory;
        }

        // Set Graphic Parametrs
        QChart * chart = new QChart(); // create new chart
        chart->addSeries(series);      // add Series to chart
        chart->createDefaultAxes();    // create axis


                    //QBarSet *leg = new QBarSet ("apple");


        QChartView * chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);


        chart -> legend()->setVisible(true);
        // QLabel *leg = new QLabel(button_edit -> text(), &window);
            //    QLabel leg("Apple", &window);
        //leg->setGeometry(350, 30, 50, 30);
        button_edit -> clear();
        // window.show();
        file.f->close();
}

void GraphicClass::on_pushButton_clicked()
{
    close();
}
