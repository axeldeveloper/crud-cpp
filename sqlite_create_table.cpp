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


std::string sql = "CREATE TABLE PERSON("
                    "ID INTEGER PRIMARY KEY  AUTOINCREMENT, "
                    "NAME           TEXT    NOT NULL, "
                    "SURNAME        TEXT    NOT NULL, "
                    "AGE            INT     NOT NULL, "
                    "ADDRESS        CHAR(50), "
                    "SALARY         REAL );"; 


// g++ -std=c++17 sqlite_create_table.cpp -o main -lsqlite3
// g++ -o update sqlite_create_table.cpp -lsqlite3
// g++ -o update sqlite_create_table.cpp -lsqlite3
// g++ sqlite_create_table.cpp -l sqlite3
// gcc sqlite_create_table.cpp -l sqlite3



int main(int argc, char** argv) 
{ 
    
    std::cout << ":) " << PROGRAMA << std::endl;

    sqlite3* DB; 

    int exit = 0; 
    exit = sqlite3_open("abeserver.db", &DB); 
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