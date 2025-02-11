#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QIcon icon(":/images/logo.png");
    a.setWindowIcon(icon);
    MainWindow w;
    w.show();
    return a.exec();
}
