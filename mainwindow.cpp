#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRadioButton>
#include <QLayout>
#include <QWidget>
#include <QGroupBox>
#include <QtDebug>
#include <QFormLayout>

#include <QtWidgets/QLayout>

#include "person/person.hpp"
#include "users/student.hpp"
#include "users/professor.hpp"
#include "users/employee.hpp"
#include "users/employeetype.hpp"
#include "util/util.hpp"
#include "config/json.hpp"
#include "util/util.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_userTypeComboBox_activated(const QString &arg1){
    if(arg1.isEmpty()){

    }

    ui->registryLineEdit->setEnabled(false);
    ui->functionalRegistryLineEdit->setEnabled(false);
    ui->employeeTypeLineEdit->setEnabled(false);
    ui->companyComboBox->setEnabled(false);

    if(ui->formLayout->rowCount() == 12){
       ui->formLayout->removeRow(11);
    }

    if(arg1 == "Professor"){
        //do professor thing
        ui->functionalRegistryLineEdit->setEnabled(true);
    }else if(arg1 == "Estudante"){
        //do student thing
        ui->registryLineEdit->setEnabled(true);

    }else if (arg1 == "Funcionário"){
        //do employee thing
        ui->functionalRegistryLineEdit->setEnabled(true);
        ui->companyComboBox->setEnabled(true);
        ui->employeeTypeLineEdit->setEnabled(true);
        QRadioButton *radio1 = new QRadioButton(tr("&Sim"));
        QRadioButton *radio2 = new QRadioButton(tr("&Não"));
        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(radio1);
        vbox->addWidget(radio2);

        ui->formLayout->addRow("Externo?",vbox);
    }
}

void MainWindow::on_saveUser_clicked(){
    QString userType = ui->userTypeComboBox->currentText();

    if(ui->firstNameLineEdit->text().isEmpty()){
        this->alertMessage();
        return;
    }else if(ui->lastNameEdit->text().isEmpty()){
        this->alertMessage();
        return;
    }else if(ui->cpfLineEdit->text().isEmpty()){
        this->alertMessage();
        return;
    }

    string firstName = ui->firstNameLineEdit->text().toUtf8().constData();
    string lastName = ui->lastNameEdit->text().toUtf8().constData();
    string cpf = ui->cpfLineEdit->text().toUtf8().constData();

    if(userType == "Professor"){
        //save professor
    }else if(userType == "Estudante"){
        //save student

        //first set all attributes
        Student s;
        s.setFirstName(firstName);
        s.setLastName(lastName);
        s.setCpf(cpf);
        s.setRegistry(ui->registryLineEdit->text().toUtf8().constData());
        string facePicturesPath = util::createFacePicturesPath(s.getPathName(),s.getRegistry());
        s.setFacePicturesPath(facePicturesPath);

        //and finally save on json db
        util::saveJson(s.getPathName(),s.getRegistry(),s.to_json());

    }else if(userType == "Funcionário"){
        //save employee
    }


}

void MainWindow::alertMessage(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Alerta!");
    msgBox.setText("Preencha todos os campos!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
