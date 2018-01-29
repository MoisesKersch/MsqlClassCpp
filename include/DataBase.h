#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <winsock.h>
#include <mysql.h>

// Developed by Moises Kerschner
// First off, go to mysql official website and search for c++ mysql headers, located it and download it


using namespace std;

class DataBase
{
private:
    string query;
    MYSQL* connection;
    MYSQL_ROW row;
    MYSQL_RES* result;
    int querystate; // store query status after execution error if 0.
public:
    DataBase(string localhost, string user, string password, string database);
    void insertInto(string name, string lastname, string birth, string password);



};

#endif // DATABASE_H
