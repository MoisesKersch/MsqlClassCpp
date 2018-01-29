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
    else
    {
        cout << "Sorry, no connection!" << endl;
    }
}

void DataBase::insertInto(string name, string lastname, string birth, string password)
{
    query = "insert into person (name, lastname, birth, password) value ('"+name+"', '"+lastname+"', '"+birth+"', '"+password+"');";
    if (connection != 0 && !(querystate = mysql_query(connection, query.c_str())))
    {
        cout << "Data saved successfully!!" << endl;
    }
    else
    {
        cout << "Sorry, your data could not be saved!" << endl;
    }
}

bool DataBase::clearTable()
{
    query = "truncate table person;";
    if (connection != 0 && !(querystate = mysql_query(connection, query.c_str())))
    {
        cout << "Table successfully cleared!" << endl;
    }
    else
    {
        cout << "Sorry, your table could not be cleared!" << endl;
    }
}

void DataBase::displayAllRecords()
{
    querystate = mysql_query(connection, "select* from person");

        if (!querystate)
        {
            //get all records from conn object to res pointer
            result = mysql_store_result(connection);
            // read and display all records
            bool check = false;
            while (row=mysql_fetch_row(result))
            {
                check = true;
                cout << "\n";
                cout << "Name: " << row[0] << endl;
                cout << "Last Name: " << row[1] << endl;
                cout << "Birthday : " << row[2] << endl;
            }
            if (!check)
                cout << "Nothing to be shown, table is clear!" << endl;

        }
}








