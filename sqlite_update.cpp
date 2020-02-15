#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "utils.cpp" 


// g++ -std=c++17 main.cxx -o main -lsqlite3
// g++ -o update sqlite_update.cpp -lsqlite3
// g++ -o update sqlite_update.cpp -lsqlite3
// g++ sqlite_update.cpp -l sqlite3
// gcc sqlite_update.cpp -l sqlite3


using namespace std;


const char *query =  "UPDATE PERSON set NAME = \"%s\" , \
                      SURNAME = \"%s\",  AGE = \"%d\",  \
                      ADDRESS = \"%s\", SALARY = \"%f\"  \
                      WHERE ID = %d ";

int main(int argc, char* argv[]) {

    std::cout << ":) " << PROGRAMA << std::endl;
    std::cout << "SQLITE VERSION %s\n" <<  sqlite3_libversion() << std::endl; 

    sqlite3 *db;
    int rc;  
    char *zErrMsg = 0; 
    char SQ[1000] = {0};
    
    PERSON p = { 24, "AXL", "Martins", 34,  "Marques de Pombal", 9.900 };
   

  
    /* format SQL  */
    sprintf(SQ, query, p.NAME, p.SURNAME, p.AGE, p.ADDRESS, p.SALARY, p.ID);

    if (sqlite3_open("abeserver.db", &db) == SQLITE_OK)
    {        
        /* Execute SQL statement */
        rc = sqlite3_exec(db, SQ,  NULL,  NULL, &zErrMsg);
         
        if ( rc != SQLITE_OK ) //SQLITE_OK = 0
        {       
            std::cout << stderr << SQL_ERROR << zErrMsg << std::endl; 
            sqlite3_free(zErrMsg);      
        }
        else{
            std::cout << stdout << UPDATE_SUCCESS << std::endl;
        }        
    }
    else
    {
        std::cout << FAILED_OPEN_DB << "\n" << std::endl; 
    }
    sqlite3_close(db);
    return 0;
}