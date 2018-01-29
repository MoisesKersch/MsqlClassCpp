#include "DataBase.h"

#include <iostream>

#include <winsock.h>
#include "mysql.h"


DataBase::DataBase(string localhost, string user, string password, string database)
{
    connection = mysql_init(0);
    connection = mysql_real_connect(connection, localhost.c_str(), user.c_str(), password.c_str(), database.c_str(), 0, NULL, 0);
    if (connection)
    {
        cout << "Connected to database ("+database+")!" << endl;
    }
}

void DataBase::insertInto(string name, string lastname, string birth, string password)
{
    query = "insert into person (name, lastname, birth, password) value ('"+name+"', '"+lastname+"', '"+birth+"', '"+password+"');";
    cout << query << endl;
    querystate = mysql_query(connection, query.c_str());
}









