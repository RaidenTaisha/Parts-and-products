#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setUser(class user* user) {
    this->_user = user;
    drawList();
    /*
    if (this->_user.userType() != UserType::PROVIDER) {
        ui->add_part->hide();
        ui->remove_part->hide();
        ui->add_product->hide();
        ui->remove_product->hide();
        ui->add_provider->hide();
        ui->remove_provider->hide();
        ui->add_storage->hide();
        ui->remove_storage->hide();
    }
    */
}

//функция отображения списков (деталей, изделий, складов, пользователей)
void MainWindow::drawList()
{
    ui->parts_listWidget->clear();
    ui->products_listWidget->clear();
    for (int i = 0; i < database::instance()->part().length(); i++) {
        ui->parts_listWidget->addItem(database::instance()->part()[i]->getname());
    }
    for (int i = 0; i < database::instance()->product().length(); i++) {
        ui->products_listWidget->addItem(database::instance()->product()[i]->getname());
    }
}

//Функция добавления детали
void MainWindow::on_add_part_clicked()
{
    auto *w = new addpart_dialog(this);
    w->exec();
    drawList();
}

//Функция удаления детали
void MainWindow::on_remove_part_clicked()
{
    database::instance()->removePart(ui->parts_listWidget->currentItem()->text());
    drawList();
}

//Функция добавления изделия
void MainWindow::on_add_product_clicked()
{
    auto *w = new addproduct_dialog(this);
    w->exec();
    drawList();
}

//Функция удаления изделия
void MainWindow::on_remove_product_clicked()
{
    database::instance()->removeProduct(ui->products_listWidget->currentItem()->text());
    drawList();
}

//Функция просмотра информации об изделия
void MainWindow::on_products_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    auto *w = new product_dialog(this);
    w->exec();
}

//Функция добавления склада
void MainWindow::on_add_storage_clicked()
{

}

//Функция удаления склада
void MainWindow::on_remove_storage_clicked()
{

}

