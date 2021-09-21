#include "database.h"
#include <QFile>
#include <QDataStream>

database *database::_instance = nullptr;

//функция возвращает вектор пользователей
const QVector<user *> &database::user() const {
    return _users;
}

//функция возвращает вектор деталей
const QVector<part *> &database::part() const {
    return _parts;
}

//функция возвращает вектор изделий
const QVector<product *> &database::product() const {
    return _products;
}

//функция добавления детали в базу данных
part* database::addPart(const QString& partName) {
    class part *out = nullptr;

    if (findPartName(partName) == nullptr) {
        out = new class part;
        out->setname(partName);
        if (database::instance()->part().length() > 0) {
            out->setID(database::instance()->part().last()->getID() + 1);
        }
        else {
            out->setID(0);
        }
        _parts.push_back(out);
        return out;
    }

    return out;
}

//функция удаления детали из базы данных
part* database::removePart(const QString& partName) {
    auto part = findPartName(partName);
    _parts.removeOne(part);
    return part;
}

//функция добавления изделия в базу данных
product* database::addProduct(const QString& productName, const QVector<QString> composition) {
    class product *out = nullptr;

    if (findProductName(productName) == nullptr) {
        out = new class product;
        out->setname(productName);
        if (database::instance()->product().length() > 0) {
            out->setID(database::instance()->product().last()->getID() + 1);
        }
        else {
            out->setID(0);
        }
        for(int i = 0; i < composition.length(); i++) {
            out->setcomposition(database::instance()->findPartName(composition[i])->getID());
        }
        _products.push_back(out);
        return out;
    }

    return out;
}

//функция удаления изделия из базы данных
product* database::removeProduct(const QString& productName) {
    auto product = findProductName(productName);
    _products.removeOne(product);
    return product;
}

//функция регистрации пользователя
user* database::registerUser(const QString& fullName, const QString& login, const QString& password, const UserType& usertype) {
    class user *out = nullptr;

    if (findUser(login) == nullptr) {
        out = new class user;
        out->setName(fullName);
        out->setLogin(login);
        out->setPassword(password);
        out->setUserType(usertype);
        _users.push_back(out);
        return out;
    }

    return nullptr;
}

//функция поиска пользователя
user* database::findUser(const QString userLogin) {
    class user *out = nullptr;

    for (int i = 0; i < _users.length(); i++) {
        if(_users[i]->login() == userLogin) {
            out = _users[i];
            return out;
        }
    }
    return nullptr;
}

//функция поиска детали по айди
part* database::findPartID(const unsigned partID) {
    for (int i = 0; i < _parts.length(); i++) {
        if(_parts[i]->getID() == partID) {
            return _parts[i];
        }
    }
    return nullptr;
}

//функция поиска детали по имени
part* database::findPartName(const QString PartName) {
    class part *out = nullptr;

    for (int i = 0; i < _parts.length(); i++) {
        if(_parts[i]->getname() == PartName) {
            out = _parts[i];
            return out;
        }
    }
    return nullptr;
}

//функция поиска изделия
product* database::findProductName(const QString ProductName) {
    class product *out = nullptr;

    for (int i = 0; i < _products.length(); i++) {
        if(_products[i]->getname() == ProductName) {
            out = _products[i];
            return out;
        }
    }
    return nullptr;
}

//функция сохранения базы данных на диск
void database::save() {
    //Сохранение файла пользователей
    {
    QFile usersfile(database::USERS_SAVE_FILE_NAME);
    usersfile.open(QIODevice::WriteOnly);
    QDataStream out(&usersfile);
    out << (qint32)_users.length();                                         //запись количества пользователей
    for (qint32 i = 0; i < _users.length(); i++) {
        out << _users[i]->name();                                           //запись имени пользователя
        out << _users[i]->login();                                          //запись логина пользователя
        out << _users[i]->password();                                       //запись пароля пользователя
        out << _users[i]->userType();                                       //запись типа пользователя
    }
    usersfile.close();
    }

    //Сохранение файла деталей
    {
    QFile partsfile(database::PARTS_SAVE_FILE_NAME);
    partsfile.open(QIODevice::WriteOnly);
    QDataStream outparts(&partsfile);
    outparts << (qint32)_parts.length();                                    //запись количества деталей
    for (qint32 i = 0; i < _parts.length(); i++) {
        outparts << (qint32)_parts[i]->getID();                             //запись айди детали
        outparts << _parts[i]->getname();                                   //запись названия детали
    }
    partsfile.close();
    }

    //Сохранение файла изделий
    {
    QFile productsfile(database::PRODUCTS_SAVE_FILE_NAME);
    productsfile.open(QIODevice::WriteOnly);
    QDataStream outproducts(&productsfile);
    outproducts << (qint32)_products.length();                              //запись количества изделий
    for (qint32 i = 0; i < _products.length(); i++) {
        outproducts << (qint32)_products[i]->getID();                       //запись айди изделия
        outproducts << _products[i]->getname();                             //запись названия изделия
        outproducts << (qint32)_products[i]->_composition.length();         //запись количества предметов из которых состоит изделие
        for (qint32 z = 0; z < _products[i]->_composition.length(); z++) {
            outproducts << (qint32)_products[i]->_composition[z];           //поочередная запись всех предметов из которых состоит изделие
        }
        
    }
    productsfile.close();
    }
}

//функция загрузки базы данных с диска
void database::load() {
    //загрузка данных пользователей
    {
    _users.clear();
    QFile usersfile(database::USERS_SAVE_FILE_NAME);
    if (!usersfile.open(QIODevice::ReadOnly)) {
        return;
    }
    QDataStream inusers(&usersfile);
    qint32 usersCount = 0;                                                  //создание переменной количества пользователей
    inusers >> usersCount;                                                  //считывание количества пользователей
    for (qint32 i = 0; i < usersCount; i++) {
        class user *_user = new class user;                                 //создание переменной пользователя
        QString username, login, password;                                  //создание переменных имени, логина, пароля
        UserType userType;                                                  //создание переменной типа пользователя
        inusers >> username;                                                //чтение имени пользователя
        inusers >> login;                                                   //чтение логина пользователя
        inusers >> password;                                                //чтение пароля пользователя
        inusers >> userType;                                                //чтение типа пользователя
        _user->setName(username);                                           //установка имени пользователя
        _user->setLogin(login);                                             //установка логина пользователя
        _user->setPassword(password);                                       //установка пароля пользователя
        _user->setUserType(userType);                                       //установка типа пользователя
        _users.push_back(_user);                                            //вставка пользователя в вектор пользователей
    }
    usersfile.close();
    }

    //загрузка данных деталей
    {
    _parts.clear();
    QFile partsfile(database::PARTS_SAVE_FILE_NAME);
    if (!partsfile.open(QIODevice::ReadOnly)) {
        return;
    }
    QDataStream inparts(&partsfile);
    qint32 partsCount = 0;                                                  //создание переменной количества деталей
    inparts >> partsCount;                                                  //считывание количества деталей
    for (qint32 i = 0; i < partsCount; i++) {
        class part *_part = new class part;                                 //создание переменной детали
        QString partname;                                                   //создание переменной названия детали
        unsigned partID;                                                    //создание переменной айди детали
        inparts >> partID;                                                  //чтение айди детали
        inparts >> partname;                                                //чтение названия детали
        _part->setID(partID);                                               //установка айди детали
        _part->setname(partname);                                           //установка названия детали
        _parts.push_back(_part);                                            //вставка детали в вектор деталей
    }
    partsfile.close();
    }

    //загрузка данных изделий
    {
    _products.clear();
    QFile productsfile(database::PRODUCTS_SAVE_FILE_NAME);
    if (!productsfile.open(QIODevice::ReadOnly)) {
        return;
    }
    QDataStream inproducts(&productsfile);
    qint32 productsCount = 0;                                               //создание переменной количества изделий
    qint32 compositionCount = 0;                                            //создание переменной количества деталей состава одного изделия
    inproducts >> productsCount;                                            //считывание количества изделий
    for (qint32 i = 0; i < productsCount; i++) {
        class product *_product = new class product;                        //создание переменной изделия
        QString productname;                                                //создание переменной названия изделия
        unsigned productID;                                                 //создание переменной айди изделия
        inproducts >> productID;                                            //чтение айди изделия
        inproducts >> productname;                                          //чтение названия изделия
        inproducts >> compositionCount;                                     //чтение количества деталей состава изделия
        _product->setID(productID);                                         //установка айди изделия
        _product->setname(productname);                                     //установка названия изделия
        for (qint32 z = 0; z < compositionCount; z++) {
            unsigned newID;                                                 //создание переменной айди детали из изделия
            inproducts >> newID;                                            //поочерёдное чтение айди деталей состава изделия
            _product->setcomposition(newID);                                //поочерёдная установка айди деталей состава изделия
        }
        _products.push_back(_product);                                      //вставка изделия в вектор изделий
    }
    productsfile.close();
    }
}

//функция создания одной базы данных
//если база данных уже создана, функция возвращает
//указатель на эту базу данных (новую не создает)
database *database::instance() {
    if (_instance == nullptr)
        _instance = new database;
    return _instance;
}
