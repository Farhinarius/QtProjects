#ifndef GRAPHICCLASS_H
#define GRAPHICCLASS_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFile>
#include <fileclass.h>

// #include <QtCharts/QLineSeries>
// #include <QtCharts/QChart>
// #include <QtCharts/QChartView>


namespace Ui
{
  class GraphicClass;
}

class GraphicClass : public QMainWindow
{
    Q_OBJECT
public:
    explicit GraphicClass(QWidget *parent = nullptr);
    ~GraphicClass();

    QPushButton * button_build;
    QPushButton *button_back;
    QLineEdit *button_edit;
    QLabel *button_label;
    // QFile * file;
    QMainWindow * window;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::GraphicClass * ui;
};

#endif // GRAPHICCLASS_H
