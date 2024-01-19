#ifndef MYSQL_H
#define MYSQL_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <mysqlx/xdevapi.h>
#include <string>
#include <ctime>

namespace mSQL {

    mysqlx::Session getSession();
    bool createAccount(uint64_t id, std::string name, std::tm date_of_birth);
};

#endif
