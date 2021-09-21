#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QListWidget>
#include "auth_window.h"
#include "reg_window.h"
#include "addpart_dialog.h"
#include "addproduct_dialog.h"
#include "product_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //переменная текущего пользователя
    user *_user = new user;
    //функция установки пользователя
    void setUser(class user* user);
    //функция отображения списков (деталей, изделий, складов, пользователей)
    void drawList();

private slots:
    //Функция добавления детали
    void on_add_part_clicked();
    //Функция удаления детали
    void on_remove_part_clicked();
    //Функция добавления изделия
    void on_add_product_clicked();
    //Функция удаления изделия
    void on_remove_product_clicked();
    //Функция просмотра информации об изделия
    void on_products_listWidget_itemDoubleClicked(QListWidgetItem *item);
    //Функция добавления склада
    void on_add_storage_clicked();
    //Функция удаления склада
    void on_remove_storage_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
