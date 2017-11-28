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
#include <QInputDialog>
#include <QStringData>
#include <QStandardItem>
#include <QListWidget>
#include <QListWidgetItem>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "person/person.hpp"
#include "users/student.hpp"
#include "users/professor.hpp"
#include "users/employee.hpp"
#include "users/employeetype.hpp"
#include "room/room.hpp"
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

//    if(ui->formLayout->rowCount() == 12){
//       ui->formLayout->removeRow(11);
//    }

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

        /* QRadioButton *radio1 = new QRadioButton(tr("&Sim"));
        QRadioButton *radio2 = new QRadioButton(tr("&Não"));
        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(radio1);
        vbox->addWidget(radio2);
        ui->formLayout->addRow("Externo?",vbox);*/
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
        this->saveProfessor(firstName,lastName,cpf);
    }else if(userType == "Estudante"){
        //save student
        this->saveStudent(firstName,lastName,cpf);
    }else if(userType == "Funcionário"){
        //save employee
        this->saveEmployee(firstName,lastName,cpf);
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
        QString message = "O campo matrícula é obrigatório";
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
    QString msg = "Estudante salvo com sucesso!";
    this->alertMessage(msg);
    this->on_cleanForm_clicked();
}


void MainWindow::saveProfessor(string firstName, string lastName, string cpf){
    //save professor

    //first set all attributes
    Professor p;
    p.setFirstName(firstName);
    p.setLastName(lastName);
    p.setCpf(cpf);
    p.setFacePicturesPath(util::getexepath()+"/json_db/Professor/faces-path/"+p.getCpf());

    if(ui->functionalRegistryLineEdit->text().isEmpty()){
        QString message = "O campo registro funcional é obrigatório";
        this->alertMessage(message);
        return;
    }else if(!boost::filesystem::is_directory(p.getFacePicturesPath())){
        QString message = "O usuário deve ter fotos da face!";
        this->alertMessage(message);
        return;
    }

    p.setFunctionalRegistry(ui->functionalRegistryLineEdit->text().toUtf8().constData());

    //and finally save on json db
    util::saveJson("Professor",p.getCpf(),p.to_json());
    QString msg = "Professor salvo com sucesso!";
    this->alertMessage(msg);
    this->on_cleanForm_clicked();
}

void MainWindow::saveEmployee(string firstName, string lastName, string cpf){
    //save employee

    //first set all attributes
    Employee emp;
    emp.setFirstName(firstName);
    emp.setLastName(lastName);
    emp.setCpf(cpf);
    emp.setFacePicturesPath(util::getexepath()+"/json_db/Funcionário/faces-path/"+emp.getCpf());

    EmployeeType et;
    et.setCompany(ui->companyComboBox->currentText().toUtf8().constData());
    et.setType(ui->employeeTypeLineEdit->text().toUtf8().constData());
    et.setInternal(true);

    emp.setEmployeeType(et);

    if(ui->functionalRegistryLineEdit->text().isEmpty()){
        QString message = "O campo registro funcional é obrigatório";
        this->alertMessage(message);
        return;
    }else if(!boost::filesystem::is_directory(emp.getFacePicturesPath())){
        QString message = "O usuário deve ter fotos da face!";
        this->alertMessage(message);
        return;
    }

    emp.setFunctionalRegistry(ui->functionalRegistryLineEdit->text().toUtf8().constData());

    //and finally save on json db
    util::saveJson("Funcionário",emp.getCpf(),emp.to_json());
    QString msg = "Funcionário salvo com sucesso!";
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

void MainWindow::alertMessageInformative(QString message, QString informative){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Alerta!");
    msgBox.setText(message);
    msgBox.setInformativeText(informative);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
int MainWindow::openVideoCapture(string facePicturesPath, bool recognize){

    CamInterface cam;
    cam.setFilePath(facePicturesPath);
    cam.setWindowName("Identificar Face");
    int recognized = cam.openVideoCapture(recognize);

    return recognized;
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

        this->openVideoCapture(fullFacePath,false);
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

void MainWindow::on_identifyUserButton_clicked(){
    bool ok;
    QString cpf = QInputDialog::getText(this, tr("Identificar Usuário:"),
                                             tr("CPF:"), QLineEdit::Normal,"", &ok);
    if (ok && !cpf.isEmpty()){
        string userFullPath = util::getUser(cpf.toUtf8().constData());
        if(userFullPath.length() == 0){
            QString msg = "Usuário não encontrado no sistema! Por favor faça o cadastro";
            this->alertMessage(msg);
            return;
        }

        json j = util::readJson(userFullPath);
        Person p(j);

        int recognized = this->openVideoCapture(p.getFacePicturesPath(),true);

        if(recognized >= 1){
            QString msg = "Usuário reconhecido! Nome: "+QString::fromUtf8(p.getFirstName().c_str());
            QString informative = " ads";
            this->alertMessage(msg);
        }else{
            QString msg = "Usuário não reconhecido! Tente novamente, ou tire mais fotos da face.";
            this->alertMessage(msg);
        }

    }
}


void MainWindow::on_takeMorePictures_clicked(){
    bool ok;
    QString cpf = QInputDialog::getText(this, tr("Identificar Usuário:"),
                                             tr("CPF:"), QLineEdit::Normal,"", &ok);
    if (ok && !cpf.isEmpty()){
        string userFullPath = util::getUser(cpf.toUtf8().constData());
        if(userFullPath.length() == 0){
            QString msg = "Usuário não encontrado no sistema! Por favor faça o cadastro";
            this->alertMessage(msg);
            return;
        }

        json j = util::readJson(userFullPath);
        Person p(j);

        this->openVideoCapture(p.getFacePicturesPath(),false);

        QString msg = "Fotos adicionadas com sucesso!";
        this->alertMessage(msg);
    }
}

void MainWindow::getRooms(){
    string p = util::getexepath()+"/json_db/rooms";
    int i = 0;

    for(int j = 0; j <ui->roomLineEdit->count();++j ){
        ui->roomLineEdit->removeItem(j);
    }

    ui->reservePersons->setHidden(true);

    //equalize schedule
    ui->initScheduleLineEdit->setMinimumDateTime(QDateTime::currentDateTime());
    ui->endScheduleEdit->setMinimumDateTime(ui->initScheduleLineEdit->dateTime().addSecs(3600));

    //fill rooms combo box
    if (boost::filesystem::is_directory(p)){
        boost::filesystem::directory_iterator end_iter;
        for (boost::filesystem::directory_iterator dir_itr(p);dir_itr != end_iter;++dir_itr){
            i++;
            string roomName = dir_itr->path().filename().string();
            util::removeJsonFormat(roomName);
            ui->roomLineEdit->addItem(QString::fromUtf8(roomName.c_str()));
        }
    }
}

void MainWindow::on_saveReserve_clicked(){

    if(ui->initScheduleLineEdit->dateTime().toString().isEmpty()){
        QString message = "O campo inicio é obrigatório";
        this->alertMessage(message);
        return;
    }else if(ui->endScheduleEdit->dateTime().toString().isEmpty()){
        QString message = "O campo fim é obrigatório";
        this->alertMessage(message);
        return;
    }else if(ui->reservePersons->count() < 1){
        QString message = "É necessário adicionar pelo menos uma pessoa!";
        this->alertMessage(message);
        return;
    }else if(util::getUser(ui->autorLineEdit->text().toUtf8().constData()).length() == 0){
        QString message = "Autor da reserva não cadastrado!";
        QString informative = "Para fazer a reserva é necessário estar cadastrado!";
        this->alertMessageInformative(message, informative);
        return;
    }else if(ui->purposeComboBox->currentText().isEmpty()){
        QString message = "O campo propósito é obrigatório!";
        this->alertMessage(message);
        return;
    }

    saveReserve();

}

void MainWindow::saveReserve(){

    Reserve r;

    r.setId(r.getNextId());

    r.setInitSchedule(ui->initScheduleLineEdit->dateTime().toString().toUtf8().constData());
    r.setEndSchedule(ui->endScheduleEdit->dateTime().toString().toUtf8().constData());
    r.setRoom(ui->roomLineEdit->currentText().toUtf8().constData());
    r.setRecurrent(ui->recurrentCheckBox->isChecked());

    string userPath = util::getUser(ui->autorLineEdit->text().toUtf8().constData());
    json j = util::readJson(userPath);
    Person author(j);
    r.setAuthor(author);

    r.setPurpose(ui->purposeComboBox->currentText().toUtf8().constData());
    vector<Person> persons;

    for(int i=0;i<ui->reservePersons->count();i++){
        string userPath = util::getUser(ui->reservePersons->itemText(i).toUtf8().constData());
        json j = util::readJson(userPath);
        Person p(j);
        persons.push_back(p);
    }
    r.setPersons(persons);
    util::saveJson(r.getPathName(),to_string(r.getId()),r.to_json());

    this->addReserveToRoom(r);

}

void MainWindow::addReserveToRoom(Reserve reserve){
    //getting room
    json j = util::readJson(util::getexepath()+"/json_db/rooms/"+reserve.getRoom()+".json");
    Room room(j);
    vector<Reserve> reservations = room.getReservationsVec();
    reservations.push_back(reserve);
    room.setReservations(reservations);
    util::saveJson(room.getPathName(),room.getRoomNumber(),room.to_json());
    cleanReserveForm();

    QString message = "Reserva realizada com sucesso!";
    this->alertMessage(message);
     ui->reserveList->clear();
     this->reserveListFill();
}


void MainWindow::on_addPersonsToReserve_clicked(){
    bool ok;
    QString cpf = QInputDialog::getText(this, tr("Identificar Usuário:"),
                                             tr("CPF:"), QLineEdit::Normal,"", &ok);
    if (ok && !cpf.isEmpty()){
        string userFullPath = util::getUser(cpf.toUtf8().constData());
        if(userFullPath.length() == 0){
            QString msg = "Usuário não encontrado no sistema! Por favor faça o cadastro";
            this->alertMessage(msg);
            return;
        }

        json j = util::readJson(userFullPath);
        Person p(j);

        ui->reservePersons->addItem(QString::fromUtf8(p.getCpf().c_str()));

        QString msg = "Usuário adicionado com sucesso!";
        this->alertMessage(msg);
    }
}

void MainWindow::on_cleanReserveForm_clicked(){
    cleanReserveForm();
}

void MainWindow::cleanReserveForm(){
    ui->initScheduleLineEdit->clear();
    ui->endScheduleEdit->clear();
    ui->recurrentCheckBox->setChecked(false);
    ui->autorLineEdit->clear();
    ui->reservePersons->clear();
}

void MainWindow::reserveListFill(){
    Reserve r;
    vector<Reserve> reservations;
    for(int i = 0; i < r.getNextId();i++){
       string p = util::getexepath()+"/json_db/reservations";
       if(boost::filesystem::is_directory(p) && !boost::filesystem::is_empty(p)){
           json j = util::readJson(p+"/"+to_string(i)+".json");
           Reserve r(j);
           reservations.push_back(r);
        }
    }
    if(reservations.size() > 0){
        for(int j=0; j<reservations.size();j++){
            ui->reserveList->addItem(QString::fromUtf8(to_string(reservations[j].getId()).c_str())+"-"
                                     +QString::fromUtf8(reservations[j].getRoom().c_str())+"-"
                                     +QString::fromUtf8(reservations[j].getInitSchedule().c_str()));
        }
    }else{
        ui->reserveList->addItem("Nenhuma reserva efetuada!");
    }

}

QString MainWindow::informUserRoom(QString cpf){
    Reserve r;
    vector<Reserve> reservations;
    for(int i = 0; i < r.getNextId()-1;i++){
       string p = util::getexepath()+"/json_db/reservations";
       if(boost::filesystem::is_directory(p) && !boost::filesystem::is_empty(p)){
           json j = util::readJson(p+"/"+to_string(i)+".json");
           Reserve r(j);
           reservations.push_back(r);
        }
    }
    vector<Person> persons;
    QString roomNumberDestination;
    if(reservations.size() > 0){
        for(int j=0; j<reservations.size();j++){
            persons.push_back(reservations[j].getPersons());
            for(int i=0;i < persons.size();i++){
                if(QString::fromUtf8(persons[i].getCpf().c_str()) == cpf){
                    cout<<persons[i].getCpf()<<endl;
                    roomNumberDestination = QString::fromUtf8(reservations[j].getRoom().c_str());
                    QDateTime dt = QDateTime::fromString(QString::fromUtf8(reservations[j].getInitSchedule().c_str()),"dd/MM/yyy HH:hh");
                    if(dt <= dt.currentDateTime()){
                       roomNumberDestination += " - No horario!";
                    }
                    break;
                }
            }
            persons.clear();
        }

    }else{
        roomNumberDestination = "Usuario sem sala reservada, encaminhe-o para o laboratorio aberto!";
    }

    return roomNumberDestination;

}

void MainWindow::on_saveRoom_clicked(){
    Room room;
    string p = util::getexepath()+"/json_db/rooms";
    string name;

    if(ui->roomNumberRegisterLineEdit->text().isEmpty()){
        QString msg = "Informe o nome da sala!";
        this->alertMessage(msg);
        return;
    }
    room.setRoomNumber(ui->roomNumberRegisterLineEdit->text().toUtf8().constData());
    if (boost::filesystem::is_directory(p) && !boost::filesystem::is_empty(p)){
        boost::filesystem::directory_iterator end_iter;

        for (boost::filesystem::directory_iterator dir_itr(p);dir_itr != end_iter;++dir_itr){
            name = dir_itr->path().filename().string();
            util::removeJsonFormat(name);
            if(room.getRoomNumber() == name){
                QString msg = "Sala já cadastrada!";
                this->alertMessage(msg);
                return;
            }
        }
        util::saveJson(room.getPathName(),room.getRoomNumber(),room.to_json());
        QString msg = "Sala cadastrada com sucesso!";
        this->alertMessage(msg);
        ui->roomNumberRegisterLineEdit->clear();
        ui->roomLineEdit->clear();
        this->getRooms();
    }

}
