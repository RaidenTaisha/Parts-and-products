#ifndef PRODUCT_H
#define PRODUCT_H

#include<QString>
#include <QVector>

class product
{
public:
    product() = default;
    ~product() = default;

    //название предмета
    QString _name;
    //айди предмета
    unsigned int _ID;
    //вектор айди предметов из которых состоит product
    QVector<unsigned int> _composition;

    //функция получения название предмета
    const QString &getname() const;
    //функция получения айди предмета
    const unsigned int &getID() const;
    //функция получения айди предметов из которых состоит product
    const QVector<unsigned int> &getcomposition() const;

    //функция добавления айди предмета из состава product
    void setcomposition(const unsigned &newID);
    //функция установки название изделия
    void setname(const QString &newName);
    //функция установки айди изделия
    void setID(const unsigned &newID);
};

#endif // PRODUCT_H
