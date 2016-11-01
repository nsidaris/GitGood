#include <QCoreApplication>
#include <QFile>
#include <QtSql>
#include <QString>
#include <QStringList>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("football.db");
    db.open();
    QSqlQuery query(db);

    QFile file("./teams.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    while(!in.atEnd())
    {
        QStringList data(in.readLine().split('\t'));
        QString blah = data.at(2);
        query.prepare("INSERT INTO STADIUM (TEAM_NAME, STADIUM_NAME, SEATING_CAP, LOCATION, CONFERENCE, SURFACE, ROOF_TYPE, STAR_PLAYER) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");
        query.bindValue(0, data.at(0));
        query.bindValue(1, data.at(1));
        query.bindValue(2, blah.remove(',').toInt());
        query.bindValue(3, data.at(3));
        query.bindValue(4, (data.at(4).at(0) == 'A'? "AFC": "NFC"));
        query.bindValue(5, data.at(5));
        query.bindValue(6, data.at(6).at(0));
        query.bindValue(7, data.at(7));
        query.exec();
    }
    file.close();
    db.close();
    return a.exec();
}
