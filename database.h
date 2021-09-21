#ifndef DATABASE_H
#define DATABASE_H

#include <QVector>
#include <QString>
#include "user.h"
#include "part.h"
#include "product.h"


class database
{
private:
    //статический указатель на базу данных
    //нужен для того чтобы контролировать создание ровно одного
    //объекта базы данных
    static database* _instance;
    //файл в котором хранятся пользователи
    const QString USERS_SAVE_FILE_NAME = "users.dat";
    QVector<user *> _users;
    //файл в котором хранятся детали
    const QString PARTS_SAVE_FILE_NAME = "parts.dat";
    QVector<part *> _parts;
    //файл в котором хранятся изделия
    const QString PRODUCTS_SAVE_FILE_NAME = "products.dat";
    QVector<product *> _products;

public:
    database() = default;

    //вектор ссылок на пользователей
    const QVector<user *> &user() const;
    //функция регистрации пользователя
    class user* registerUser(const QString &fullName, const QString &login, const QString &password, const UserType& usertype);
    //функция поиска пользователя
    class user* findUser(const QString userLogin);

    //вектор ссылок на детали
    const QVector<part *> &part() const;
    //функция добавления детали в базу данных
    class part* addPart(const QString& partName);
    //функция удаления детали из базы данных
    class part* removePart(const QString& partName);
    //функция поиска детали по айди
    class part* findPartID(const unsigned partID);
    //функция поиска детали по названию
    class part* findPartName(const QString PartName);

    //вектор ссылок на изделия
    const QVector<product *> &product() const;
    //функция добавления изделия в базу данных
    class product* addProduct(const QString& productName, const QVector<QString> composition);
    //функция удаления изделия из базы данных
    class product* removeProduct(const QString& productName);
    //функция поиска изделия
    class product* findProductName(const QString ProductName);

    //функция сохранения базы данных на диск
    void save();
    //функция загрузки базы данных с диска
    void load();

    //функция создания одной базы данных
    //если база данных уже создана, функция возвращает
    //указатель на эту базу данных (новую не создает)
    static database *instance();
};

#endif // DATABASE_H
