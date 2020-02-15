#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "sqlite3.h"
#include "utils.cpp" 
//#include "sqlite_exception.h"

//g++ -o insert sqlite_insert.cpp -lsqlite3
using namespace std;


int main()
{
       
    std::cout << ":) " << PROGRAMA << std::endl;
    
    int counter = 0;

    sqlite3 *db;
    sqlite3_stmt * stmt;

    string NAME    = "Axel Alexander";
    string SURNAME = "Panda";
    string AGE     = "30";
    string ADDRESS = "Marques";
    string SALARY  = "9.700";



    
    string sql =
        "INSERT INTO PERSON (NAME, SURNAME, AGE, ADDRESS, SALARY) VALUES ("
        + quotesql(NAME) + ","
        + quotesql(SURNAME) + ","
        + quotesql(AGE) + ","
        + quotesql(ADDRESS) + ","
        + quotesql(SALARY) + ");";


    if (sqlite3_open("abeserver.db", &db) == SQLITE_OK)
    {
        //preparing the statement
        sqlite3_prepare( db, sql.c_str(), -1, &stmt, NULL ); 

        //executing the statement
        int result = sqlite3_step( stmt );
        
        if ( result == SQLITE_DONE )
        {
            std::cout << INSERT_SUCCESS << std::endl;   
        }
        else{
       
            std::cout << DB_ERROR << sqlite3_errmsg(db) << std::endl; 
        }        

    }
    else
    {
        std::cout << FAILED_OPEN_DB << "\n" << std::endl; 
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);


    return 0;

}