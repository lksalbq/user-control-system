#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "person/person.hpp"
#include "users/student.hpp"
#include "users/professor.hpp"
#include "users/employee.hpp"
#include "users/employeetype.hpp"
#include "util/util.hpp"
#include "cam-interface/camInterface.hpp"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void populateUserList();
private slots:
    void on_userTypeComboBox_activated(const QString &arg1);

    void on_saveUser_clicked();

    void on_saveFaces_clicked();

    void on_cleanForm_clicked();

    void on_identifyUserButton_clicked();

    void on_takeMorePictures_clicked();

private:
    Ui::MainWindow *ui;
    void alertMessage(QString message);
    int openVideoCapture(string facePicturesPath,bool recognize);
    void saveStudent(string firstName, string lastName, string cpf);
    void saveProfessor(string firstName, string lastName, string cpf);
    void saveEmployee(string firstName, string lastName, string cpf);
    void cleanUserRegisterForm();

};

#endif // MAINWINDOW_H
