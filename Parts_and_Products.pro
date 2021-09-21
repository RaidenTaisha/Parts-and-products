QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addpart_dialog.cpp \
    addproduct_dialog.cpp \
    auth_window.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    part.cpp \
    product.cpp \
    product_dialog.cpp \
    reg_window.cpp \
    user.cpp

HEADERS += \
    addpart_dialog.h \
    addproduct_dialog.h \
    auth_window.h \
    database.h \
    mainwindow.h \
    part.h \
    product.h \
    product_dialog.h \
    reg_window.h \
    user.h

FORMS += \
    addpart_dialog.ui \
    addproduct_dialog.ui \
    auth_window.ui \
    mainwindow.ui \
    product_dialog.ui \
    reg_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/About-toynote.svg \
    icons/Close.svg \
    icons/Exit.svg \
    icons/Lottery.svg \
    icons/Note-add.svg \
    icons/Note-remove.svg \
    icons/Notebook-new.svg \
    icons/Notebook-open.svg \
    icons/Notebook-save-as-text.svg \
    icons/Notebook-save-as.svg \
    icons/Notebook-save.svg \
    icons/Send-email.svg \
    icons/Visit-eCourses.svg \
    icons/Зелёная стрелка вправо.svg \
    icons/Зелёная стрелка вправо.svg \
    icons/Красная стрелка влево.svg \
    icons/Красная стрелка влево.svg \
    icons/зелёная стрелка вправо.svg \
    icons/красная стрелка влево.svg \
    img/Зелёная стрелка вправо.png \
    img/Зелёная стрелка вправо.png \
    img/Зелёная стрелка вправо.png \
    img/Красная стрелка влево.png \
    img/Красная стрелка влево.png \
    img/Красная стрелка влево.png
