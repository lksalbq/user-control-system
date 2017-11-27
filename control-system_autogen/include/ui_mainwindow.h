/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUserRegister;
    QAction *actionReserveRegister;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *userTableWidget;
    QCommandLinkButton *identifyUserButton;
    QWidget *tab_2;
    QWidget *personForm;
    QFormLayout *formLayout;
    QLabel *firstNameLabel;
    QLineEdit *firstNameLineEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameEdit;
    QLabel *cpfLabel;
    QLineEdit *cpfLineEdit;
    QLabel *userTypeLabel;
    QComboBox *userTypeComboBox;
    QLabel *registryLabel;
    QLineEdit *registryLineEdit;
    QLabel *functionalRegistryLabel;
    QLineEdit *functionalRegistryLineEdit;
    QLabel *employeeTypeLabel;
    QLineEdit *employeeTypeLineEdit;
    QLabel *companyLabel;
    QComboBox *companyComboBox;
    QPushButton *saveUser;
    QPushButton *pushButton_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1159, 703);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionUserRegister = new QAction(MainWindow);
        actionUserRegister->setObjectName(QStringLiteral("actionUserRegister"));
        actionReserveRegister = new QAction(MainWindow);
        actionReserveRegister->setObjectName(QStringLiteral("actionReserveRegister"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(70, 20, 1061, 581));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        userTableWidget = new QTableWidget(tab);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName(QStringLiteral("userTableWidget"));
        userTableWidget->setGeometry(QRect(40, 40, 891, 192));
        userTableWidget->setLayoutDirection(Qt::LeftToRight);
        identifyUserButton = new QCommandLinkButton(tab);
        identifyUserButton->setObjectName(QStringLiteral("identifyUserButton"));
        identifyUserButton->setGeometry(QRect(310, 350, 291, 53));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        personForm = new QWidget(tab_2);
        personForm->setObjectName(QStringLiteral("personForm"));
        personForm->setEnabled(true);
        personForm->setGeometry(QRect(110, 50, 801, 331));
        personForm->setStyleSheet(QLatin1String("\n"
"alternate-background-color: rgb(243, 243, 243);"));
        formLayout = new QFormLayout(personForm);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        firstNameLabel = new QLabel(personForm);
        firstNameLabel->setObjectName(QStringLiteral("firstNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameLineEdit = new QLineEdit(personForm);
        firstNameLineEdit->setObjectName(QStringLiteral("firstNameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, firstNameLineEdit);

        lastNameLabel = new QLabel(personForm);
        lastNameLabel->setObjectName(QStringLiteral("lastNameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameEdit = new QLineEdit(personForm);
        lastNameEdit->setObjectName(QStringLiteral("lastNameEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lastNameEdit);

        cpfLabel = new QLabel(personForm);
        cpfLabel->setObjectName(QStringLiteral("cpfLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, cpfLabel);

        cpfLineEdit = new QLineEdit(personForm);
        cpfLineEdit->setObjectName(QStringLiteral("cpfLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, cpfLineEdit);

        userTypeLabel = new QLabel(personForm);
        userTypeLabel->setObjectName(QStringLiteral("userTypeLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, userTypeLabel);

        userTypeComboBox = new QComboBox(personForm);
        userTypeComboBox->setObjectName(QStringLiteral("userTypeComboBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, userTypeComboBox);

        registryLabel = new QLabel(personForm);
        registryLabel->setObjectName(QStringLiteral("registryLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, registryLabel);

        registryLineEdit = new QLineEdit(personForm);
        registryLineEdit->setObjectName(QStringLiteral("registryLineEdit"));
        registryLineEdit->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, registryLineEdit);

        functionalRegistryLabel = new QLabel(personForm);
        functionalRegistryLabel->setObjectName(QStringLiteral("functionalRegistryLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, functionalRegistryLabel);

        functionalRegistryLineEdit = new QLineEdit(personForm);
        functionalRegistryLineEdit->setObjectName(QStringLiteral("functionalRegistryLineEdit"));
        functionalRegistryLineEdit->setEnabled(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, functionalRegistryLineEdit);

        employeeTypeLabel = new QLabel(personForm);
        employeeTypeLabel->setObjectName(QStringLiteral("employeeTypeLabel"));

        formLayout->setWidget(9, QFormLayout::LabelRole, employeeTypeLabel);

        employeeTypeLineEdit = new QLineEdit(personForm);
        employeeTypeLineEdit->setObjectName(QStringLiteral("employeeTypeLineEdit"));
        employeeTypeLineEdit->setEnabled(false);

        formLayout->setWidget(9, QFormLayout::FieldRole, employeeTypeLineEdit);

        companyLabel = new QLabel(personForm);
        companyLabel->setObjectName(QStringLiteral("companyLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, companyLabel);

        companyComboBox = new QComboBox(personForm);
        companyComboBox->setObjectName(QStringLiteral("companyComboBox"));
        companyComboBox->setEnabled(false);

        formLayout->setWidget(10, QFormLayout::FieldRole, companyComboBox);

        saveUser = new QPushButton(tab_2);
        saveUser->setObjectName(QStringLiteral("saveUser"));
        saveUser->setGeometry(QRect(530, 470, 141, 41));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 470, 141, 41));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionUserRegister->setText(QApplication::translate("MainWindow", "Cadastrar Usu\303\241rio", 0));
        actionReserveRegister->setText(QApplication::translate("MainWindow", "Cadastrar Reserva", 0));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Nome", 0));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "CPF", 0));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Deletar", 0));
        identifyUserButton->setText(QApplication::translate("MainWindow", "Identificar Usu\303\241rio", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Acesso", 0));
        firstNameLabel->setText(QApplication::translate("MainWindow", "Nome:", 0));
        lastNameLabel->setText(QApplication::translate("MainWindow", "Sobrenome:", 0));
        cpfLabel->setText(QApplication::translate("MainWindow", "CPF:", 0));
        userTypeLabel->setText(QApplication::translate("MainWindow", "Tipo de Usu\303\241rio:", 0));
        userTypeComboBox->clear();
        userTypeComboBox->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Professor", 0)
         << QApplication::translate("MainWindow", "Estudante", 0)
         << QApplication::translate("MainWindow", "Funcion\303\241rio", 0)
        );
        registryLabel->setText(QApplication::translate("MainWindow", "Matr\303\255cula", 0));
        functionalRegistryLabel->setText(QApplication::translate("MainWindow", "Registro Funcional", 0));
        employeeTypeLabel->setText(QApplication::translate("MainWindow", "Tipo de Funcion\303\241rio", 0));
        companyLabel->setText(QApplication::translate("MainWindow", "Empresa", 0));
        saveUser->setText(QApplication::translate("MainWindow", "Salvar", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Limpar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Cadastrar Usu\303\241rio", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Reservas", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Cadastrar Reservas", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
