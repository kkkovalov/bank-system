#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "../header.h"

namespace Accounts {

// [x] - Function to generate a uniformly distributed number from 100,000,000 to 999,999,999
uint64_t generate_random_id();

// [ ] - Class to hold SQL stringified information
class Account {
  public:
    uint64_t m_id{generate_random_id()};
    std::string m_name{};

  private:
    // date of birth in std::tm format for easier manipulation
    std::tm m_tm_date_of_birth{};
    std::string m_date_of_birth{};

    // available funds on the account at any given moment
    double m_available_funds{0};
    // double pending_inflow_funds{0};
    // double pending_outflow_funds{0};
    // double total_funds{0};

    // std::tm m_date_joined{};

  public:
    Account(std::string name, std::string date_of_birth) : m_name{name}, m_date_of_birth{date_of_birth} {

        // Convert date of birth to more accessible std::tm variable
        std::istringstream ss(date_of_birth);
        ss >> std::get_time(&m_tm_date_of_birth, "%Y/%m/%d");

        // [ ] -
        mSQL::createAccount(m_id, m_name, m_tm_date_of_birth);

        std::cout << "\nWelcome, " << m_name << ", to the Bank of Kovalov!\n";
    };

    ~Account(){};

    friend std::ostream &operator<<(std::ostream &out, const Account &account);

    uint64_t getId() const;
    std::string getDateOfBirth() const;
    std::string getName() const;

    void addFunds(double funds);
};

// [ ] - Function to disable access to the account and delete it from database.
void closeAccount();

Account openChequingAccount(std::string name, std::string dateOfBirth);
// Account openSavingsAccount(std::string name, std::string dateOfBirth);

}; // namespace Accounts

#endif
