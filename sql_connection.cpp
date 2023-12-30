#include <iostream>
#include <mysql/mysql.h>

int main() {
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL *connection, mysql;

    int state;

    mysql_init(&mysql);

    connection = mysql_real_connect(&mysql, "127.0.0.1", "root", "AdGjL1029+-", "bank_of_kovalov", 3306, 0, 0);

    if (connection == NULL) {
        std::cout << mysql_error(&mysql) << '\n';
    };

    state = mysql_query(connection, "SHOW TABLES");
    if (state != 0) {
        std::cout << mysql_error(connection) << '\n';
    };

    result = mysql_store_result(connection);

    std::cout << "tables: " << mysql_num_rows(result) << std::endl;
    while ((row = mysql_fetch_row(result)) != NULL) {
        std::cout << row[0] << std::endl;
    }

    mysql_free_result(result);
    mysql_close(connection);
}
