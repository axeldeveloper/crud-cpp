#include <stdio.h>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <sstream>
#include <list>
#include <string> // for string class
#include <iterator>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


const string FAILED_DB          = "FAILED TO OPEN DB";
const string PROGRAMA           = "CRUD IN CPP ";
const string NOT_OPEN_DB        = "CANNOT OPEN DATABASE";
const string FAILED_EXE_STM     = "FAILED TO EXECUTE STATEMENT";
const string ERROR_CREATE_TABLE = "ERROR CREATE TABLE";
const string TABLE_CREATED      = "TABLE CREATED SUCCESSFULLY";
const string INSERT_SUCCESS     = "INSERT SUCCESSFULLY";
const string UPDATE_SUCCESS     = "UPDATE SUCCESSFULLY";
const string DB_ERROR           = "DB ERROR: ";
const string FAILED_OPEN_DB     = "FAILED TO OPEN DB";
const string SQL_ERROR          = "SQL ERROR: ";

string quotesql( const string& s ) {
    return string("'") + s + string("'");
};

struct PERSON {
    int ID;
    char NAME[80];
    char SURNAME[80];
    int AGE;
    char ADDRESS[100];
    double SALARY;    
};

struct Person {
    
    int id;  
    std::string name;
    std::string surname; 
    int age;
    std::string addres;
    double salary;  
    Person(
        int Id, 
        std::string Name, 
        std::string SurName, 
        int Age, 
        std::string Addres, 
        double Salary) :
            id(Id), 
            name(Name),
            surname(SurName), 
            age(Age), 
            addres(Addres), 
            salary(Salary)

        {
        }
};

struct Constants {
    static const string s1;
    static const string s2;
};