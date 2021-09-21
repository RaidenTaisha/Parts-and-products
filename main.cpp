#include "mainwindow.h"
#include "auth_window.h"

#include <QApplication>

int main(int argc, char *argv[]){    
    QApplication a(argc, argv);

    database::instance()->load();

    auth_window *w = new auth_window();
    w->show();
    int exitCode = a.exec();

    database::instance()->save();

    return exitCode;
}
