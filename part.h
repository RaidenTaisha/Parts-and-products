#ifndef PART_H
#define PART_H

#include<QString>

class part
{
public:
    part() = default;
    ~part() = default;

    //название предмета
    QString _name;
    //айди предмета
    unsigned _ID;

    //функция получения название предмета
    const QString &getname() const;
    //функция получения айди предмета
    const unsigned &getID() const;
    //функция установки название предмета
    void setname(const QString &newName);
    //функция установки айди предмета
    void setID(const unsigned &newID);
};

#endif // PART_H
