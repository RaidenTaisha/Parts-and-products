#ifndef PRODUCT_DIALOG_H
#define PRODUCT_DIALOG_H

#include <QDialog>

namespace Ui {
class product_dialog;
}

class product_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit product_dialog(QWidget *parent = nullptr);
    ~product_dialog();

private:
    Ui::product_dialog *ui;
};

#endif // PRODUCT_DIALOG_H
