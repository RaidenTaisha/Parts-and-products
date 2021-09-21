#include "parts.h"

//функция получения названия детали
const QString &part::partname() const {
    return _partname;
}

//функция получения айди детали
const unsigned &part::partID() const {
    return _partID;
}
