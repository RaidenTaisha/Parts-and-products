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

private:
    Ui::reg_window *ui;
};

#endif // REG_WINDOW_H
