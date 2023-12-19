#include "accounts.h"


uint64_t Accounts::Account::getId() const { return m_id; };

std::string Accounts::Account::getDateOfBirth() const {
    std::stringstream ss;
    ss << m_date_of_birth.tm_mon << '/' << m_date_of_birth.tm_mday << '/' << m_date_of_birth.tm_year + 1900;
    return ss.str();
};
std::string Accounts::Account::getName() const {
    return m_name;
};

uint64_t Accounts::generate_random_id() {
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution id{100000000, 999999999};
    return id(mt);
};

// Accounts::Account Accounts::openChequingAccount() {
//     std::string name{};
//     std::cout << "\n\t\tOpening a new chequing account.\n\n";
//     std::cout << "Enter your full name: ";
//     std::getline(std::cin, name);
//     Account newChequingAcc{name};
//     return newChequingAcc;
// };

// Accounts::Account Accounts::openSavingsAccount() {
//     Account newSavingsAccount{};
//     return newSavingsAccount;
// };
