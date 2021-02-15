#include <iostream> 
#include <sqlite3.h> 
#include "utils.cpp" 


#define SQL_CREATE_TABLE_PERSON_CONFIG      \
	"CREATE TABLE IF NOT EXISTS PERSON (\n" \
    "  ID INTEGER PRIMARY KEY  AUTOINCREMENT, \n" \
	"  NAME      TEXT NOT NULL,  \n" \
	"  SURNAME   TEXT NOT NULL,  \n" \
	"  AGE       NOT NULL,       \n" \
	"  ADDRESS   TEXT,           \n" \
    "  SALARY    REAL            \n" \
	")"

int main(int argc, char** argv) 
{ 
    // g++ -std=c++17 sqlite_create_table.cpp -o main -lsqlite3
    // g++ -o update sqlite_create_table.cpp -lsqlite3
    // g++ sqlite_create_table.cpp -l sqlite3
    // g++ sqlite_create_table.cpp -o main -lsqlite3
    // g++ sqlite_create_table.cpp -o create_talbe -lsqlite3



    std::cout << ":) " << PROGRAMA << std::endl;

    sqlite3* DB; 

    int exit = 0; 
    exit = sqlite3_open("DEV.db", &DB); 
    char* messaggeError; 
    exit = sqlite3_exec(DB, SQL_CREATE_TABLE_PERSON_CONFIG, NULL, 0, &messaggeError); 
  
    if (exit != SQLITE_OK) { 
        std::cerr << ERROR_CREATE_TABLE << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << TABLE_CREATED << std::endl; 
    
    sqlite3_close(DB); 
    return (0); 
} 