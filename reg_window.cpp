#include "reg_window.h"
#include "ui_reg_window.h"
#include "mainwindow.h"

reg_window::reg_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg_window)
{
    ui->setupUi(this);
}

reg_window::~reg_window()
{
    delete ui;
}

void reg_window::on_RegisterPushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    QString confirm = ui->lineEdit_confirm->text();

    if (password != confirm)
    {
        QMessageBox::warning(this, "Warning", "password not equal confirm");
        return;
    }

    if (name.length() == 0 || login.length() == 0 || password.length() == 0)
    {
        QMessageBox::warning(this, "Warning", "No full name, login or password supplied");
        return;
    }
    user *_user = database::instance()->registerUser(name, login, password);
    if (_user->userType() == UserType::ERROR)
    {
        QMessageBox::critical(this, "Error", "User with such login already exists");
        return;
    }

    QMessageBox::information(this, "Success", tr("Succsessfully registered %1 (%2), you are %3").arg(_user->name()).arg(_user->login()).arg(_user->userType() == UserType::ADMIN? "administrator" : "user"));

    auth_window *w = new auth_window();
    close();
    w->show();
}

