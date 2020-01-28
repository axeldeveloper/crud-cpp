#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>
#include <string> // for string class
#include <iterator>
#include <algorithm>
#include "utils.cpp"



// g++ -std=c++17 sqlite_select_param.cpp -o main -lsqlite3
// g++ -o update sqlite_select_param.cpp -lsqlite3
// g++ -o update sqlite_select_param.cpp -lsqlite3
// g++ sqlite_select_param.cpp -l sqlite3
// gcc sqlite_select_param.cpp -l sqlite3

using namespace std;


class Person {
   
    // constructor
    public:
        int ID;
        string NAME ;
        string SURNAME;
        int AGE;
        string ADDRESS;
        float SALARY;
};


int main(void) {
    
    std::cout << ":) " << PROGRAMA << std::endl;

    sqlite3 *db;
    sqlite3_stmt *res;
    char *err_msg = 0;
   
    int param = 25;
    
    int rc = sqlite3_open("abeserver.db", &db);
    
    if (rc != SQLITE_OK) {
        
        std::cout << NOT_OPEN_DB << sqlite3_errmsg(db) << std::endl;
        
        sqlite3_close(db);
        
        return 1;
    }
    
    const char *sql = "SELECT ID, NAME, SURNAME, AGE, ADDRESS, SALARY FROM PERSON WHERE ID = ?";
        
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    if (rc == SQLITE_OK) {    
        sqlite3_bind_int(res, 1, param);
    } 
    else
    {       
        std::cout << stderr << FAILED_EXE_STM << sqlite3_errmsg(db) << std::endl;    
    }
    
    int step = sqlite3_step(res);

   

    if (step == SQLITE_ROW) {    
       
        std::stringstream pn , ps , pa;
        pn << sqlite3_column_text(res, 1);
        ps << sqlite3_column_text(res, 2);;
        pa << sqlite3_column_text(res, 4);;

        Person person;
        person.ID      = sqlite3_column_int(res, 0) ;
        person.NAME    = pn.str();
        person.SURNAME = ps.str();
        person.AGE     = sqlite3_column_int(res, 3) ;
        person.ADDRESS = pa.str();
        person.SALARY  = sqlite3_column_double(res, 5);

        std::cout << "Person ID :"      << person.ID << std::endl;   
        std::cout << "Person Name :"    << person.NAME << std::endl; 
        std::cout << "Person SURNAME :" << person.SURNAME << std::endl;   
        std::cout << "Person AGE :"     << person.AGE << std::endl;   
        std::cout << "Person ADDRESS :" << person.ADDRESS << std::endl;   
        std::cout << "Person SALARY :"  << person.SALARY << std::endl;   
    } 

    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return 0;
}
