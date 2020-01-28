#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "utils.cpp" 

// g++ -std=c++17 sqlite_update_prepare_call.cpp -o main -lsqlite3
// g++ -o update sqlite_update_prepare_call.cpp -lsqlite3
// g++ -o update sqlite_update_prepare_call.cpp -lsqlite3
// g++ sqlite_update_prepare_call.cpp -l sqlite3
// gcc sqlite_update_prepare_call.cpp -l sqlite3
using namespace std;



const char * SQL_UPDATE_ALL_PERSON  = "UPDATE PERSON SET NAME=?, \n" \
                                        "SURNAME=?,  \n" \
                                        "AGE=?,      \n" \
                                        "ADDRESS=?,  \n" \
                                        "SALARY=?    \n" \
                                        "WHERE ID=?  \n;" \
                                        "SELECT * from PERSON";

                                    
//int main(int argc, char* argv[]) {
int main() {

    std::cout << ":) " << PROGRAMA << std::endl;
    std::cout << "SQLITE VERSION %s\n" <<  sqlite3_libversion() << std::endl; 

    sqlite3 *db;
    sqlite3_stmt * stmt;
    int rc;

    PERSON p = { 24, "AXL", "Martins", 34,  "Marques de Pombal", 9.900 };
  
    if (sqlite3_open("abeserver.db", &db) == SQLITE_OK)
    {
           
        /* Execute SQL statement */
        sqlite3_prepare_v2(db, SQL_UPDATE_ALL_PERSON, -1, &stmt, NULL ); 
        sqlite3_bind_text(stmt,   1, p.NAME, -1, SQLITE_STATIC);  
        sqlite3_bind_text(stmt,   2, p.SURNAME, -1, SQLITE_STATIC);                                           /* 2 */
        sqlite3_bind_int(stmt,    3, p.AGE); 
        sqlite3_bind_text(stmt,   4, p.ADDRESS, -1, SQLITE_STATIC); 
        sqlite3_bind_double(stmt, 5, p.SALARY);
        sqlite3_bind_int(stmt,    6, p.ID);
 
              
        //executing the statement
        rc = sqlite3_step(stmt);

        if ( rc == SQLITE_DONE ) // 101
        {
            std::cout << stdout << UPDATE_SUCCESS << std::endl; 
        }
        else{
            std::cout << SQL_ERROR << sqlite3_errmsg(db) << std::endl;
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