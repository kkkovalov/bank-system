#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <iostream>
#include <string>
#include "randomuuid.h"

namespace Accounts {

class Account{
    private:
        uint32_t m_id{generate_random_id()};
    public:
        std::string m_name;

        Account(std::string_view name) : m_name{name}{
            std::cout << "\nWelcome, " << m_name << "to the Bank of Kovalov!";
        };

        uint32_t getId();
};

Account openChequingAccount();
void openSavingsAccount();

void closeCurrentAccount();

} // namespace Accounts

#endif
