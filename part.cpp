#include "part.h"

//функция получения название предмета
const QString &part::getname() const {
    return _name;
}

//функция получения айди предмета
const unsigned int &part::getID() const {
    return _ID;
}

//функция установки название предмета
void part::setname(const QString &newName) {
    _name = newName;
}

//функция установки айди предмета
void part::setID(const unsigned &newID) {
    _ID = newID;
}
