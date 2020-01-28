#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>
#include <list>
#include <string> // for string class
#include <iterator>
#include <algorithm>
#include <vector>
#include "utils.cpp"

// g++ -std=c++17 sqlite_select_all.cpp -o main -lsqlite3
// g++ -o all sqlite_select_all.cpp -lsqlite3
// g++ -o all sqlite_select_all.cpp -lsqlite3
// g++ sqlite_select_all.cpp -l sqlite3
// gcc sqlite_select_all.cpp -l sqlite3


using namespace std;


//https://github.com/fnc12/sqlite_orm

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


int main()
{
    std::cout << ":) " << PROGRAMA << std::endl;

    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::list<Person> listOfPersons;
    
    
    if (sqlite3_open("abeserver.db", &db) == SQLITE_OK)
    {
        sqlite3_prepare(db, "SELECT * from PERSON;", -1, &stmt, NULL ); //preparing the statement
        while(sqlite3_step(stmt) == SQLITE_ROW) 
        {
            std::stringstream pn , ps , pa;
            pn << sqlite3_column_text(stmt, 1);
            ps << sqlite3_column_text(stmt, 2);;
            pa << sqlite3_column_text(stmt, 4);;

            //string try1 = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,4))); 

            Person person;
            person.ID      = sqlite3_column_int(stmt, 0) ;
            person.NAME    = pn.str();
            person.SURNAME = ps.str();
            person.AGE     = sqlite3_column_int(stmt, 3) ;;
            person.ADDRESS = pa.str();
            person.SALARY  = sqlite3_column_double(stmt, 5);;    
            listOfPersons.push_back(person);
        }     

            // getting size of the list 
            int size = listOfPersons.size(); 

            for (const Person & row : listOfPersons)
            {   
                std::cout << "ID : " << row.ID << " :: " << row.NAME << std::endl;
            }

            std::cout << "list : " << size << std::endl;  
    }
    else
    {
        std::cout << FAILED_DB << "\n" << std::endl;  
    }
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}