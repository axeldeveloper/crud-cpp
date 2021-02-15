#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "utils.cpp" 


using namespace std;


const char *SQL_UPDATE_ALL_PERSON  = "UPDATE PERSON SET NAME='%s', \n" \
                                        "SURNAME='%s',  \n" \
                                        "AGE=%d,        \n" \
                                        "ADDRESS='%s',  \n" \
                                        "SALARY=%f      \n" \
                                        "WHERE ID=%d    \n;" \
                                        "SELECT * from PERSON";                                        


static int callback(void *data, int argc, char **argv, char **columns){
   int i;
   
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", columns[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

//int main(int argc, char* argv[]) {
int main() {


    // g++ -std=c++17 sqlite_update_callback.cpp -o main -lsqlite3
    // g++ -o update sqlite_update_callback.cpp -lsqlite3
    // g++ -o update sqlite_update_callback.cpp -lsqlite3
    // g++ sqlite_update_callback.cpp -l sqlite3


    std::cout << ":) " << PROGRAMA << std::endl;
    std::cout << "SQLITE VERSION %s\n" <<  sqlite3_libversion() << std::endl; 

    sqlite3 *db;
    sqlite3_stmt * stmt;
    const char *query = NULL;

    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char* data = "Callback function called";

    PERSON p = { 25, "Beau", "Mary", 21,  "Marques", 9.900 };

    // Person piano_cat = Person(25, "coult", "Beauh", 21,  "Marques", 9.900);
    // std::cout << ":) " << piano_cat.id << std::endl;


    char SQ[1000]     = {0};

    /* Create merged SQL statement */
    sprintf(SQ, SQL_UPDATE_ALL_PERSON, p.NAME, p.SURNAME, p.AGE, p.ADDRESS, p.SALARY, p.ID);
   
    if (sqlite3_open("DEV.db", &db) == SQLITE_OK)
    {       
        /* Execute SQL statement */
        rc = sqlite3_exec(db, SQ, callback, (void*)data,  &zErrMsg);         
           
        if ( rc != SQLITE_OK )
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

    //sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}