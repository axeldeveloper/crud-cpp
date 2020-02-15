#include <iostream> 
#include <sqlite3.h> 
#include <string> 
  
using namespace std; 
  
static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 
  
int main(int argc, char** argv) 
{ 
    sqlite3* DB; 
    char* messaggeError; 
    int exit = sqlite3_open("abeserver.db", &DB); 
    string query = "SELECT * FROM PERSON;"; 
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl; 
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
  
    string sql("INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
               "INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
               "INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);"); 
  
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
    if (exit != SQLITE_OK) { 
        std::cerr << "Error Insert" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Records created Successfully!" << std::endl; 
  
    cout << "STATE OF TABLE AFTER INSERT" << endl; 
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
  
    sql = "DELETE FROM PERSON WHERE ID = 2;"; 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
    if (exit != SQLITE_OK) { 
        std::cerr << "Error DELETE" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Record deleted Successfully!" << std::endl; 
  
    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl; 
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
  
    sqlite3_close(DB); 
    return (0); 
} 