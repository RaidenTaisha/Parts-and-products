#ifndef ADDPRODUCT_DIALOG_H
#define ADDPRODUCT_DIALOG_H

#include <QDialog>

namespace Ui {
class addproduct_dialog;
}

class addproduct_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addproduct_dialog(QWidget *parent = nullptr);
    ~addproduct_dialog();

private slots:
    void on_addpart_pushButton_clicked();

    void on_delpart_pushButton_clicked();

    void on_back_pushButton_clicked();

    void on_add_pushButton_clicked();

private:
    Ui::addproduct_dialog *ui;
};

#endif // ADDPRODUCT_DIALOG_H
