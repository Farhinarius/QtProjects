#include "mainform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window win;
    win.show();
    return app.exec();
}
