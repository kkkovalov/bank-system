#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "../header.h"

namespace Accounts {

// Function to generate a uniformly distributed number from 100,000,000 to
// 999,999,999
uint64_t generate_random_id();

class Account {
  private:
    uint64_t m_id{generate_random_id()};

  public:
    std::string m_name;
    Account() {
        std::cout << "\nWelcome, Anonymous, to the Vank of Kovalov!\n";
    };
    Account(std::string_view name) : m_name{name} {
        std::cout << "\nWelcome, " << m_name << ", to the Bank of Kovalov!\n";
    };

    uint64_t getId();
};

Account openChequingAccount();
Account openSavingsAccount();

void closeCurrentAccount();

} // namespace Accounts

#endif
