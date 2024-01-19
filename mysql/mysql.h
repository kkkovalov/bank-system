#ifndef MYSQL_H
#define MYSQL_H

#include <cstdlib>
#include <iostream>
#include <mysqlx/xdevapi.h>
#include <string>

namespace mSQL {

    mysqlx::Session getSession(int argc, const char *argv[]);

};

#endif
