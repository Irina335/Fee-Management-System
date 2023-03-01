#ifndef CONN_H
#define CONN_H

#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"

static bool isconnected(){
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("ges_frais_school");

    if (database.open()){
        return true;
    }else{
        return false;
    }
}

#endif // CONN_H
