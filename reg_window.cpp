#include "reg_window.h"
#include "ui_reg_window.h"
#include "mainwindow.h"

reg_window::reg_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg_window)
{
    ui->setupUi(this);
    if (database::instance()->user().length() == 0) {
        ui->label_user_type->hide();
        ui->cbx_user_type->hide();
        ui->label_name->hide();
        ui->lineEdit_name->hide();
    }
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
    UserType usertype = UserType::ERROR;
    if (database::instance()->user().length() == 0) {
        name = "Админ";
        usertype = UserType::ADMIN;
    } else {
        if (ui->cbx_user_type->currentText() == "Поставщик")
            usertype = UserType::PROVIDER;
        if (ui->cbx_user_type->currentText() == "Диспетчер")
            usertype = UserType::DISP;
    }

    if (password != confirm)
    {
        QMessageBox::warning(this, "Warning", "Password was incorrectly confirmed");
        return;
    }

    if (name.length() == 0 || login.length() == 0 || password.length() == 0)
    {
        QMessageBox::warning(this, "Warning", "No full name, login or password supplied");
        return;
    }
    user *_user = database::instance()->registerUser(name, login, password, usertype);
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


void reg_window::on_cbx_user_type_textActivated(const QString &arg1)
{
    if (arg1 == "Поставщик") {
        ui->label_name->setText("Наименование организации");
    }
    if (arg1 == "Диспетчер") {
        ui->label_name->setText("Имя");
    }
}

