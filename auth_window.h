#ifndef AUTH_WINDOW_H
#define AUTH_WINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "reg_window.h"
#include "database.h"
#include "user.h"

namespace Ui {
class auth_window;
}

class auth_window : public QDialog
{
    Q_OBJECT

public:
    explicit auth_window(QWidget *parent = nullptr);
    ~auth_window();

private slots:
    void on_RegisterPushButton_clicked();

    void on_loginPushButton_clicked();

private:
    Ui::auth_window *ui;
    reg_window *registerwindow;
};

#endif // AUTH_WINDOW_H
