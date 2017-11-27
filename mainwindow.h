#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_userTypeComboBox_activated(const QString &arg1);

    void on_saveUser_clicked();

private:
    Ui::MainWindow *ui;
    void alertMessage();
};

#endif // MAINWINDOW_H
