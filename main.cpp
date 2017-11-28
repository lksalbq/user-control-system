#include "mainwindow.h"
#include "users/student.hpp"
#include "users/professor.hpp"
#include "users/employee.hpp"
#include "discipline/discipline.hpp"
#include "room/room.hpp"
#include "cam-interface/camInterface.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "config/json.hpp"
#include "util/util.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.getRooms();
    w.reserveListFill();
    //w.userListFill();
    w.setWindowTitle("Sistem de Controle de Usuários");
    w.show();

    return a.exec();
}
