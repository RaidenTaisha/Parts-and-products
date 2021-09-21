#include "product.h"

//функция получения название предмета
const QString &product::getname() const {
    return _name;
}

//функция получения айди предмета
const unsigned int &product::getID() const {
    return _ID;
}

//функция получения айди предметов из которых состоит product
const QVector<unsigned int> &product::getcomposition() const {
    return _composition;
}

//функция добавления айди предмета из состава product
void product::setcomposition(const unsigned &newID) {
    _composition.push_back(newID);
}

//функция установки название предмета
void product::setname(const QString &newName) {
    _name = newName;
}

//функция установки айди предмета
void product::setID(const unsigned &newID) {
    _ID = newID;
}
