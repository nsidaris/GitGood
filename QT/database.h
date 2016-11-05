#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

class Database : public QSqlDatabase
{
public:
    ~Database();
    static Database *getInstance();
private:
    Database();
    static Database *db;  ///< accesses database
};

#endif // DATABASE_H
