#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "additems.h"
#include "searchclass.h"
#include "deleteclass.h"
#include "graphicclass.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    AddItems addItems;         // Create form "Add new program software"
    SearchClass searchClass;   // Create form "Search program software"
    DeleteClass deleteClass;   // Create form "Delete Program Software in file"
    GraphicClass graphicClass; // Create form "Graphic of program software"
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked(); // Close Main Window

    void on_pushButton_clicked();   // Add new program software

    void on_pushButton_2_clicked(); // Search program software

    void on_pushButton_3_clicked(); // Delete Program Software in file

    void on_pushButton_5_clicked(); // Show Graphic of program software


private:
    Ui::MainWindow * ui; // pointer of designer
};

#endif // MAINWINDOW_H
