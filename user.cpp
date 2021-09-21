#include "user.h"

//функция получения имени пользователя
const QString &user::name() const {
    return _name;
}

//функция установки имени пользователя
void user::setName(const QString &newName) {
    _name = newName;
}

//функция получения логина пользователя
const QString &user::login() const {
    return _login;
}

//функция установки логина пользователя
void user::setLogin(const QString &newLogin) {
    _login = newLogin;
}

//функция получения пароля пользователя
const QString &user::password() const {
    return _password;
}

//функция установки пароля пользователя
void user::setPassword(const QString &newPassword) {
    _password = newPassword;
}

//функция получения типа пользователя
UserType user::userType() const {
    return _userType;
}

//функция установки типа пользователя
void user::setUserType(UserType newUserType) {
    _userType = newUserType;
}
