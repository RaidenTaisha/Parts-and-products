#include "product_dialog.h"
#include "ui_product_dialog.h"

product_dialog::product_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::product_dialog)
{
    ui->setupUi(this);
}

product_dialog::~product_dialog()
{
    delete ui;
}
