#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "../header.h"
#include "../mysql/mysql.h"

namespace Accounts {

// Function to generate a uniformly distributed number from 100,000,000 to
// 999,999,999
uint64_t generate_random_id();

void closeCurrentAccount();


class Account {
  public:
    std::string m_name;
    uint64_t m_id{generate_random_id()};

  private:
    
    std::tm m_tm_date_of_birth{};
    std::string m_date_of_birth{};

  public:
    Account() { std::cout << "\nWelcome, Anonymous, to the Bank of Kovalov!\n"; };
    Account(std::string name, std::string date_of_birth)
        : m_name{name}, m_date_of_birth{date_of_birth} {

        // Convert date of birth to more accessible std::tm variable
        std::istringstream ss(date_of_birth);
        ss >> std::get_time(&m_tm_date_of_birth, "%m/%d/%Y");

        bool result{mSQL::createAccount(m_id, m_name, m_tm_date_of_birth)};

        std::cout << "\nWelcome, " << m_name << ", to the Bank of Kovalov!\n" <<"Created an account in DB:" << result << '\n';
    };

    ~ Account() {};

    friend std::ostream& operator<<(std::ostream &out, const Account &account);

    uint64_t getId() const;
    std::string getDateOfBirth() const;
    std::string getName() const;
};

Account openChequingAccount(std::string name, std::string dateOfBirth);
// Account openSavingsAccount(std::string name, std::string dateOfBirth);

}; // namespace Accounts

#endif
