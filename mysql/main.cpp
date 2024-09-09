#include <iostream>
#include <mysql/mysql.h>

int main() {
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    // Initialize the MySQL connection
    conn = mysql_init(NULL);
    if (conn == NULL) {
        std::cerr << "mysql_init() failed\n";
        return 1;
    }

    // Connect to the MySQL server
    if (!mysql_real_connect(conn, "localhost", "thuyetpq", "123456a@", "demo_db", 0, NULL, 0)) {
        std::cerr << "Failed to connect to MySQL: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }

    // Execute a SQL query
    if (mysql_query(conn, "SELECT * FROM employees")) {
        std::cerr << "Failed to execute query: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }

    // Get the result set
    res = mysql_store_result(conn);
    if (res == NULL) {
        std::cerr << "Failed to retrieve result set: " << mysql_error(conn) << std::endl;
        mysql_close(conn);
        return 1;
    }

    // Iterate through the result set
    while ((row = mysql_fetch_row(res)) != NULL) {
        // Process the row data
        std::cout << "Column 1 , 2 , 3 value: " << (row[0] ? row[0] : "NULL") << " " << (row[1] ? row[1] : "NULL") << " " << (row[2] ? row[2] : "NULL") << std::endl;
        // Add more code to process additional columns as needed
    }

    // Clean up
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
