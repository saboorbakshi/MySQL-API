# MySQL-API

A MySQL database connector for C++ applications that connect to MySQL servers.

Prerequisites before compiling:
1. sudo apt-get install libmysqlcppconn-dev
2. sudo apt-get install libmysqlclient-dev

Compiling:
g++ connector.cpp -o connector -L/usr/include/mysql/mysql -lmysqlclient
