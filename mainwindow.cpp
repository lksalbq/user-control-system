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
#include "config/json.hpp"
#include "util/util.hpp"

using namespace std;

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
        QString message = "O campo tipo de usuário obrigatório";
        this->alertMessage(message);
        return;
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
        QString message = "O campo nome é obrigatório";
        this->alertMessage(message);
        return;
    }else if(ui->lastNameEdit->text().isEmpty()){
        QString message = "O campo sobrenome é obrigatório";
        this->alertMessage(message);
        return;
    }else if(ui->cpfLineEdit->text().isEmpty()){
        QString message = "O campo cpf é obrigatório";
        this->alertMessage(message);
        return;
    }else if(userType.isEmpty()){
        QString message = "O campo tipo de usuário obrigatório";
        this->alertMessage(message);
        return;
    }

    string firstName = ui->firstNameLineEdit->text().toUtf8().constData();
    string lastName = ui->lastNameEdit->text().toUtf8().constData();
    string cpf = ui->cpfLineEdit->text().toUtf8().constData();

    if(userType == "Professor"){
        //save professor
    }else if(userType == "Estudante"){
        this->saveStudent(firstName,lastName,cpf);

    }else if(userType == "Funcionário"){
        //save employee
    }


}

void MainWindow::saveStudent(string firstName, string lastName, string cpf){
    //save student

    //first set all attributes
    Student s;
    s.setFirstName(firstName);
    s.setLastName(lastName);
    s.setCpf(cpf);
    s.setFacePicturesPath(util::getexepath()+"/json_db/Estudante/faces-path/"+s.getCpf());

    if(ui->registryLineEdit->text().isEmpty()){
        QString message = "O campo cpf é obrigatório";
        this->alertMessage(message);
        return;
    }else if(!boost::filesystem::is_directory(s.getFacePicturesPath())){
        QString message = "O usuário deve ter fotos da face!";
        this->alertMessage(message);
        return;
    }

    s.setRegistry(ui->registryLineEdit->text().toUtf8().constData());

    //and finally save on json db
    util::saveJson("Estudante",s.getCpf(),s.to_json());
    QString msg = "Estudante Salvo com sucesso!";
    this->alertMessage(msg);
    this->on_cleanForm_clicked();
}

void MainWindow::alertMessage(QString message){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Alerta!");
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::saveFacePictures(string facePicturesPath){

    CamInterface cam;
    cam.setFilePath(facePicturesPath);
    cam.setWindowName("Tirar fotos da face");
    cam.openVideoCapture(false);
}

void MainWindow::on_saveFaces_clicked(){
    string fullFacePath;

    if(ui->cpfLineEdit->text().isEmpty()){
        QString msg = "Informe o cpf do usuario!";
        this->alertMessage(msg);
        return;
    }else if(ui->userTypeComboBox->currentText().isEmpty()){
        QString msg = "Informe o tipo do usuario!";
        this->alertMessage(msg);
        return;
     }else{
        string userType = ui->userTypeComboBox->currentText().toUtf8().constData();
        string identifier = ui->cpfLineEdit->text().toUtf8().constData();
        fullFacePath = util::createFacePicturesPath(userType,identifier);

        this->saveFacePictures(fullFacePath);
        QString message = "Imagens capturadas com sucesso!";
        this->alertMessage(message);
    }


}

void MainWindow::on_cleanForm_clicked(){
   this->cleanUserRegisterForm();
}

void MainWindow::cleanUserRegisterForm(){
    ui->registryLineEdit->clear();
    ui->functionalRegistryLineEdit->clear();
    ui->employeeTypeLineEdit->clear();
    ui->companyComboBox->setCurrentIndex(0);
    ui->firstNameLineEdit->clear();
    ui->lastNameEdit->clear();
    ui->cpfLineEdit->clear();
}
