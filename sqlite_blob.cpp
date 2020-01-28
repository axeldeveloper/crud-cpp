#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <time.h>

using namespace std;

// Store gmtime data structure as a blob
// See man pages for information on gmtime data structure: man gmtime

int main(int argc, char **argv)
{
  sqlite3 *db;
  sqlite3_stmt *ppStmt;
  char *zErrMsg = 0;
  const char   *zSql = "INSERT INTO btest(ID, MyData) VALUES('1',?)";

  time_t tt = 0;
  time_t now = time(&tt);          // seconds since the Epoch
  struct tm *blob = gmtime(&now);  // Create the blob to store in the database

  cout << "Year stored: " << blob->tm_year+1900 << endl;
  cout << endl;

  int rc = sqlite3_open("/tmp/bedrock.db", &db);
  if( rc )
  {
    cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
    exit(1);
  }

  // Insert blob data into database

  if( sqlite3_prepare_v2(db, zSql, -1, &ppStmt, NULL) != SQLITE_OK )
  {
      cerr << "db error: " << sqlite3_errmsg(db) << endl;
      sqlite3_close(db);
      exit(1);
  }

  if(ppStmt)
  {
      // For Blob collumn bind 1
      sqlite3_bind_blob(ppStmt, 1, blob, sizeof(struct tm), SQLITE_TRANSIENT);
      sqlite3_step(ppStmt);
      sqlite3_finalize(ppStmt);
      sqlite3_exec(db, "COMMIT", NULL, NULL, NULL);
  }
  else
  {
      cerr << "Error: ppStmt is NULL" << endl;
      sqlite3_close(db);
      exit(1);
  }

  // Select rows from database

  const char *zSqlSelect = "select * from btest";
  if( sqlite3_prepare_v2(db, zSqlSelect, -1, &ppStmt, NULL) != SQLITE_OK )
  {
      cerr << "db error: " << sqlite3_errmsg(db) << endl;
      sqlite3_close(db);
      exit(1);
  }

  // Name of DB table
  cout << sqlite3_column_table_name(ppStmt,0) << endl;

  // For each row returned
  while (sqlite3_step(ppStmt) == SQLITE_ROW)
  {
      // For each collumn
      for(int jj=0; jj < sqlite3_column_count(ppStmt); jj++)
      {
          // Print collumn name
          cout << sqlite3_column_name(ppStmt,jj) << " = ";

          // Print collumn data
          switch(sqlite3_column_type(ppStmt, jj))
          {
             case SQLITE_INTEGER: cout << sqlite3_column_int(ppStmt, jj) << endl;
                  break;
             case SQLITE_FLOAT:   cout << sqlite3_column_double(ppStmt, jj) << endl;
                  break;
             case SQLITE_TEXT:    cout << sqlite3_column_text(ppStmt, jj) << endl;
                  break;
             case SQLITE_BLOB:    cout << "BLOB " << endl;
                  cout << "Size of blob: " << sqlite3_column_bytes(ppStmt, jj) << endl;
                  struct tm *blobRetreived;
                  blobRetreived = (struct tm *) sqlite3_column_blob(ppStmt, jj);
                  cout << "Year retrieved from blob: " << blobRetreived->tm_year+1900 << endl;
                  break;
             case SQLITE_NULL:    cout << "NULL " << endl;
                  break;
             default: cout << "default " << endl;
                  break;
          }
      }
  }
  sqlite3_finalize(ppStmt);

  sqlite3_exec(db, "END", NULL, NULL, NULL);

  // Close database

  sqlite3_close(db);
  return 0;
}

