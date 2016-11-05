#include "database.h"

Database* Database::db = nullptr;

Database::Database() : QSqlDatabase(addDatabase("QSQLITE")){
    this->setHostName("localhost");
    this->setDatabaseName("../Database/football.db");

    this->open();
    QSqlQuery query(*this);
    query.exec("PRAGMA foreign_keys = 1;");
}
Database::~Database() {
    this->close();
}

Database* Database::getInstance() {
    if(!db)
        db = new Database;

    return db;
}
