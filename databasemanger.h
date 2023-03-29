#ifndef DATABASEMANGER_H
#define DATABASEMANGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlIndex>
#include <QSqlRecord>

#include <QMessageBox>
#include <QDebug>
#include "people.h"


class DataBaseManger
{

public:
    DataBaseManger();

    static DataBaseManger* getInstance();

    bool connectDB(const QString& connectName = nullptr);

    bool initDB(const QString& db_name);

    void Run(const QString& table_name = "people");


public:
    void insertPrjName(const QString& tableName,
                       const People& people);

    void insertPrjName(const QString& tableName,
                       const int& id,
                       const QString& name,
                       const QString& className,
                       const int& age,
                       const bool& sex);

    QVector<People> queryAll(const QString& tableName);

    void queryByCls(const QString& tableName);

    void queryBySex(const QString& tableName);

    void query(const QString& sql);

    void deleteIndex(const QString& tableName,const QString& id);

    void deleteAll(const QString& tableName);

    void deleteTable(const QString& tableName);

private:
    static DataBaseManger *instance;

    QSqlDatabase db;
};

#endif // DATABASEMANGER_H
