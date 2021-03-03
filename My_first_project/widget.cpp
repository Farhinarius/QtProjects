// constructor_form;
  //-- include create form interface
// destructor_form;

#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
   // QRect rect=geometry();

    setWindowTitle("Window Application1");
    setGeometry(700,340,100,100);
    resize(500,250);
    //
    createFormInterier();
}

Widget::~Widget()
{

}

void Widget::createFormInterier()
{
    // LABEL
    QLabel * panel_label = new QLabel(tr("Enter some information:"),this);
    panel_label->setGeometry(20,20,130,20);

    // TEXT_EDIT
    QLineEdit * panel_line_edit = new QLineEdit(this);
    panel_line_edit->setGeometry(150,20,330,20);

    // SAVE_BUTTON
    QPushButton * panel_savebutton = new QPushButton(tr("Save info"),this);
    panel_savebutton->setGeometry(20,50,80,25); //y - 210

    // BIG_TEXT_EDIT
    QTextEdit * panel_text_edit = new QTextEdit(tr("-Enter text-"),this);
    panel_text_edit->setGeometry(150,50,330,185);

    // CLOSE_BUTTON
    QPushButton * panel_exit_button = new QPushButton(tr("Close App"),this);
    panel_exit_button->setGeometry(20,210,80,25);

    QObject::connect(panel_exit_button,SIGNAL(clicked()),this,SLOT(close()));
}










