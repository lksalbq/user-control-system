#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.getRooms();
    w.reserveListFill();
    w.setWindowTitle("Sistem de Controle de Usuários");
    w.show();

    return a.exec();
}
