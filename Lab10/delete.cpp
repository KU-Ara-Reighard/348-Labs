#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

sql::mysql::MySQL_Driver *driver;
sql::Connection *con; // to establish connection
sql::Statement *stmt; // to execute SQL statement
sql::ResultSet *res; // a place to store the query results

driver = sql::mysql::get_mysql_driver_instance();
con = driver=>connect("mysql.eecs.ku.edu");

stmt = con->createStatement();






stmt->execute("CREATE TABLE test 
    ( id  INT   NOT_NULL,
      label VARCHAR(6) NOT_NULL)");

stmt->execute("INSERT INTO test(id, label)
VALUES (2, 'label1')");

stmt->execute("UPDATE label
SET label = 'label2'
WHERE id = 2");

res = stmt->query("SELECT label FROM test
WHERE id < 10");
while (res->next()) {
    cout << "Label: " << res->getString("label") << endl;
}

