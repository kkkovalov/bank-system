#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "../header.h"

namespace Accounts {

// Function to generate a uniformly distributed number from 100,000,000 to
// 999,999,999
uint64_t generate_random_id();

class Account {
  public:
    std::string m_name;

  private:
    uint64_t m_id{generate_random_id()};
    std::tm m_date_of_birth{};

  
  public:
    Account() { std::cout << "\nWelcome, Anonymous, to the Bank of Kovalov!\n"; };
    Account(std::string name, std::tm date_of_birth)
        : m_name{name}, m_date_of_birth{date_of_birth} {
        std::cout << "\nWelcome, " << m_name << ", to the Bank of Kovalov!\n";
    };

    uint64_t getId() const;
    std::string getDateOfBirth() const;
    std::string getName() const;
};

Account openChequingAccount();
Account openSavingsAccount();

void closeCurrentAccount();

} // namespace Accounts

#endif
