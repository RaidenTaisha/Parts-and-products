#ifndef REG_WINDOW_H
#define REG_WINDOW_H

#include <QDialog>

namespace Ui {
class reg_window;
}

class reg_window : public QDialog
{
    Q_OBJECT

public:
    explicit reg_window(QWidget *parent = nullptr);
    ~reg_window();

private slots:
    void on_RegisterPushButton_clicked();

    void on_cbx_user_type_textActivated(const QString &arg1);

private:
    Ui::reg_window *ui;
};

#endif // REG_WINDOW_H
