#include "addproduct_dialog.h"
#include "ui_addproduct_dialog.h"
#include "mainwindow.h"

addproduct_dialog::addproduct_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addproduct_dialog)
{
    ui->setupUi(this);
    ui->available_listWidget->clear();
    for (int i = 0; i < database::instance()->part().length(); i++) {
        ui->available_listWidget->addItem(database::instance()->part()[i]->getname());
    }
}

addproduct_dialog::~addproduct_dialog()
{
    delete ui;
}

void addproduct_dialog::on_addpart_pushButton_clicked()
{
    if(ui->available_listWidget->currentRow() >= 0)
        ui->coposition_listWidget->addItem(ui->available_listWidget->takeItem(ui->available_listWidget->currentRow())->text());
}


void addproduct_dialog::on_delpart_pushButton_clicked()
{
    if(ui->coposition_listWidget->currentRow() >= 0)
        ui->available_listWidget->addItem(ui->coposition_listWidget->takeItem(ui->coposition_listWidget->currentRow())->text());
}

void addproduct_dialog::on_add_pushButton_clicked()
{
    QVector<QString> composition;
    if (ui->productname_lineEdit->text() != "" && ui->coposition_listWidget->count() > 0) {
        for (int i = 0; i < ui->coposition_listWidget->count(); i++) {
            composition.push_back(ui->coposition_listWidget->item(i)->text());
        }
        database::instance()->addProduct(ui->productname_lineEdit->text(), composition);
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Empty string");
        return;
    }
    close();
}

void addproduct_dialog::on_back_pushButton_clicked()
{
    close();
}

