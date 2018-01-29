#include <iostream>
#include <DataBase.h>

using namespace std;

int main()
{
    DataBase database("localhost", "root", "", "register");
    database.insertInto("Fernando", "Db", "1000-10-10", "root");
    database.clearTable();

    database.displayAllRecords();
}
