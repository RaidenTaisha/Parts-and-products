#include "auth_window.h"
#include "ui_auth_window.h"
#include "mainwindow.h"

auth_window::auth_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth_window)
{
    ui->setupUi(this);
}

auth_window::~auth_window()
{
    delete ui;
}

void auth_window::on_RegisterPushButton_clicked()
{
    close();
    registerwindow = new reg_window(this);
    registerwindow->show();
}


void auth_window::on_loginPushButton_clicked()
{
    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();
    if (login.length() == 0 || password.length() == 0)
    {
        QMessageBox::warning(this, "Warning", "No login or password supplied");
        return;
    }

    user *_user = new user;
    _user = database::instance()->findUser(login);
    if (_user->userType() == UserType::ERROR)
    {
        QMessageBox::critical(this, "Error", "No such user");
        return;
    }
    if (_user->password() != password)
    {
        QMessageBox::critical(this, "Error", "Wrong password");
        return;
    }

    QMessageBox::information(this, "Success", tr("Hello %1 (%2), you are %3").arg(_user->name()).arg(_user->login()).arg(_user->userType() == UserType::ADMIN? "administrator" : "just a user"));

    MainWindow *w = new MainWindow();
    close();
    w->show();
    w->setUser(_user);
}

