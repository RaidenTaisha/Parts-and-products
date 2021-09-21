#include "addpart_dialog.h"
#include "ui_addpart_dialog.h"
#include "mainwindow.h"

addpart_dialog::addpart_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addpart_dialog)
{
    ui->setupUi(this);
}

addpart_dialog::~addpart_dialog()
{
    delete ui;
}

void addpart_dialog::on_addpart_pushButton_clicked()
{
    if (ui->partname_lineEdit->text() != "")
        database::instance()->addPart(ui->partname_lineEdit->text());
    else
    {
        QMessageBox::warning(this, "Warning", "Empty string");
        return;
    }
    close();
}


void addpart_dialog::on_back_pushButton_clicked()
{
    close();
}

