#include <person_file.h>
#include <add_person.h>
#include <widget.h>

addPerson::addPerson()
{
createAddPersonInterier();
}

void addPerson::createAddPersonInterier()
{
  setWindowTitle("Add Person/Add Number");
///////////////////////////////////////////////////////////////////////////
// ОПИСАНИЕ ВСЕХ ОБЪЕКТОВ, НАХОДЯЩИХСЯ В addPerson.h в классе addPerson

 // метки для полей ввода, позволяющие пользователю ориентрироваться
 subscriber_name = new QLabel("Name of subscriber:",this);
 owner_type = new QLabel("Owner Type:",this);
 phone_number = new QLabel("Phone Number:",this);
 year_of_installation = new QLabel("Year of installation:",this);

 // описание полей ввода EDIT, осущесвляющие ввод, в основну программу
 edit_name = new QLineEdit(this);
 owner_type_box = new QComboBox(this);
 edit_phone_number = new QLineEdit(this);
 edit_year_of_install = new QLineEdit(this);

 // ComboBox regularity definition
 owner_type_box->addItem("individual");
 owner_type_box->addItem("collective");
 owner_type_box->addItem("");


 // описание кнопок, работающих с окном
 buttonAddPerson = new QPushButton("Add Person/Add Number",this);
 buttonExitWindow = new QPushButton("Exit",this);

 resize(400,120);
//////////////////////////////////////////////////////////////////////////
// СОЗДАНИЕ КОМПОНОВКИ НА ОКНЕ ADD FORM
 // вертикальная раскладка полей ввода
 QVBoxLayout * vlayout = new QVBoxLayout;
 vlayout->addWidget(subscriber_name);
 vlayout->addWidget(edit_name);
 vlayout->addWidget(owner_type);
 vlayout->addWidget(owner_type_box);
 vlayout->addWidget(phone_number);
 vlayout->addWidget(edit_phone_number);
 vlayout->addWidget(year_of_installation);
 vlayout->addWidget(edit_year_of_install);
 // vlayout->addStretch();

 // вертикальная раскладка кнопок
 QVBoxLayout * vbuttonlayout = new QVBoxLayout;
 vbuttonlayout->addWidget(buttonAddPerson);
 vbuttonlayout->addWidget(buttonExitWindow);
 vbuttonlayout->addStretch();

 // горизонтальная раскладка, привязанная в форме
 QHBoxLayout * hlayout = new QHBoxLayout(this);
 hlayout->addLayout(vlayout);
 hlayout->addLayout(vbuttonlayout);
/////////////////////////////////////////////////////////////////////////
// СИГНАЛЫ И СЛОТЫ
   connect(buttonAddPerson, SIGNAL(clicked(bool)), // взаимосвязь между
             this,SLOT(addRecord()));       // кнопкой "добавить" и методом файла-объекта addRecord
   connect(buttonExitWindow, SIGNAL(clicked(bool)), // взаимодействие между кнопкой "выход"
             this,SLOT(close())); // и слотом "закрыть"


}
 void addPerson::addRecord()
 {
     personFile book; // создаем файловую переменную с инициализирующим конструктором
     recType record;  // создаем структуру, которую нужно записать в файл
     record.subscriber_name = edit_name->text(); // присваиваем полям структуры поля окна addForm
     record.owner_type = owner_type_box->currentText(); // аналогично для других полй структуры
     record.phone_number = edit_phone_number->text();
     record.year_of_installation = edit_year_of_install->text();

     edit_name->clear();  // очистка всех полей, при нажатии клавиши
     edit_phone_number->clear();
     edit_year_of_install->clear();
     book.addRec(record);  // метод файла, который мы вызовем, при нажатии на кнопку
     // в файле должны появится записи
 }


