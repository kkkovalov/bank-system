#include "accounts.h"

uint64_t Accounts::Account::getId() { return m_id; };

uint64_t Accounts::generate_random_id() {
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution id{100000000, 999999999};
    return id(mt);
};

Accounts::Account Accounts::openChequingAccount() {
    std::string name{};
    std::cout << "\n\t\tOpening a new chequing account.\n\n";
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    Account newChequingAcc{name};
    return newChequingAcc;
};

Accounts::Account Accounts::openSavingsAccount() {
    Account newSavingsAccount{};
    return newSavingsAccount;
};
