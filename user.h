#ifndef USER_H
#define USER_H

#include<QString>

//типы пользователей
enum class UserType {
    ERROR, ADMIN, USER, DISP, PROVIDER
};

class user {
private:
    //имя пользователя
    QString _name;
    //логин пользователя
    QString _login;
    //пароль пользователя
    QString _password;
    //тип пользователя
    UserType _userType = UserType::ERROR;

public:
    user() = default;

    //функция получения имени пользователя
    const QString &name() const;

    //функция установки имени пользователя
    void setName(const QString &newName);

    //функция получения логина пользователя
    const QString &login() const;

    //функция установки логина пользователя
    void setLogin(const QString &newLogin);

    //функция получения пароля пользователя
    const QString &password() const;

    //функция установки пароля пользователя
    void setPassword(const QString &newPassword);

    //функция получения типа пользователя
    UserType userType() const;

    //функция установки типа пользователя
    void setUserType(UserType newUserType);
};

#endif // USER_H
