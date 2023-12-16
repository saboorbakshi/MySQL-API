#include <fstream>
#include <iostream>
#include <strings.h>
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

#define SPACE -20

using namespace std;

// void printTable(MYSQL *connection) {
//     auto result = mysql_use_result(connection);
//     MYSQL_FIELD *field;
//     while ((field = mysql_fetch_field(result)) != NULL) {
//         printf("%*s", SPACE, field->name);
//     }
//     cout << endl;

//     unsigned int num = mysql_field_count(connection);

//     MYSQL_ROW row;
//     while ((row = mysql_fetch_row(result)) != NULL) {
//         for (int i = 0; i < num; ++i) {
//             printf("%*s", SPACE, row[i]);
//         }
//         cout << endl;
//     }
//     mysql_free_result(result);
// }

int main(int argc, char const **argv) {

    string server = "localhost", user = "root", password = "lamPtorQue123!", db = "testDB", query;
    bool success = true;

    MYSQL *connection = mysql_init(NULL);

    bool val = true;

    mysql_options(connection, MYSQL_OPT_RECONNECT, &val);

    // connect to database
    if (!mysql_real_connect(connection, server.c_str(), user.c_str(), password.c_str(), db.c_str(), 0, NULL, 0)) {
        cout << mysql_error(connection) << endl;
        success = false;
        return -1;
    }

    ifstream file("input.txt");

    int counter = 1;

    while (getline(file, query)) {
        if (mysql_query(connection, query.c_str())) {
            cout << mysql_error(connection) << endl;
        } else {
            cout << "Query " << counter << endl;
            cout << query << endl << endl;
            ++counter;
        }
        mysql_free_result(mysql_use_result(connection));
    }

    // send queries to db
    // while (success) {
    //     cout << "Please enter query: ";
    //     getline(cin, query);
    //     if (query == "exit") {
    //         success = false;
    //     } else if (mysql_query(connection, query.c_str())) {
    //         cout << mysql_error(connection) << endl;
    //     } else {
    //         if (strcasecmp(query.substr(0, 6).c_str(), "SELECT") == 0) {
    //             printTable(connection);  
    //         }
    //         cout << "Query successful." << endl;
    //     }
    // }

    mysql_close(connection);

    return 0;
}