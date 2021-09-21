#ifndef ADDPART_DIALOG_H
#define ADDPART_DIALOG_H

#include <QDialog>

namespace Ui {
class addpart_dialog;
}

class addpart_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit addpart_dialog(QWidget *parent = nullptr);
    ~addpart_dialog();

private slots:

    void on_addpart_pushButton_clicked();

    void on_back_pushButton_clicked();

private:
    Ui::addpart_dialog *ui;
};

#endif // ADDPART_DIALOG_H
