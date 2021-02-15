#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include <string.h>
#include <locale.h>
#include "sqlite3.h"
#include "utils.cpp" 



using namespace std;

int main()
{
   
    // g++ -std=c++17 sqlite_insert_2.cpp -o insert2 -lsqlite3
    // g++ sqlite_insert_2.cpp  -o main -lsqlite3
    // g++ -o insert2 sqlite_insert_2.cpp -lsqlite3
    // g++ -o insert2 sqlite_insert_2.cpp -lsqlite3
    // g++ sqlite_insert_2.cpp -l sqlite3
  

    std::cout << ":) " << PROGRAMA << std::endl;

    sqlite3 *db;
    sqlite3_stmt * stmt;

    string NAME    = "Masarico";
    string SURNAME = "masaranduba";
    int AGE        = 30;
    string ADDRESS = "Marques";
    double SALARY  = 9.700;

    const char *query = NULL;
    
    query = "INSERT INTO PERSON (NAME, SURNAME, AGE, ADDRESS, SALARY) VALUES (?1, ?2, ?3, ?4, ?5);";
    

    if (sqlite3_open("DEV.db", &db) == SQLITE_OK)
    {
        //preparing the statement
        sqlite3_prepare_v2( db, query, strlen(query), &stmt, NULL ); 
        sqlite3_bind_text(stmt,   1, NAME.c_str(),    -1, SQLITE_STATIC);  
        sqlite3_bind_text(stmt,   2, SURNAME.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt,    3, AGE); 
        sqlite3_bind_text(stmt,   4, ADDRESS.c_str(), -1, SQLITE_STATIC); 
        sqlite3_bind_double(stmt, 5, SALARY);

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