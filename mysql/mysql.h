#ifndef MYSQL_H
#define MYSQL_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <mysqlx/xdevapi.h>
#include <string>
#include <ctime>

namespace mSQL {

    mysqlx::Table getAccountsTable();

    // [ ] - create and entry in the database for this user with 0 initial funds
    void createAccount(uint64_t id, std::string name, std::tm date_of_birth);

    // [ ] - deposit funds to the account with specified id
    double depositFunds(uint64_t id, double deposit_amount);

    // [ ] - withdraw funds from the account with specified id
    double withdrawFunds(uint64_t id, double withdraw_amount);
};

#endif
