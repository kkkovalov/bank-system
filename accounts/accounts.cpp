#include "accounts.h"

// -------------------------GETTER functions for Accounts class-----------------------------------
uint64_t Accounts::Account::getId() const { return m_id; };
std::string Accounts::Account::getDateOfBirth() const { return m_date_of_birth; };
std::string Accounts::Account::getName() const { return m_name; };
// -----------------------------------------------------------------------------------------------

// Function to generate random IDs for the bank account
uint64_t Accounts::generate_random_id() {
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution id{100000000, 999999999};
    return id(mt);
};

// Friend function to overload "operator<<" for proper(easier) output of Account class
std::ostream &Accounts::operator<<(std::ostream &out, const Account &account) {
    out << "Account ID: " << account.m_id << '\n'
        << "Name on the file: " << account.m_name << '\n'
        << "Date of Birth: " << account.m_date_of_birth << '\n';

    return out;
}

Accounts::Account Accounts::openChequingAccount(std::string name, std::string date_of_birth) {
    std::cout << "\n\t\tOpening a new chequing account.\n\n";
    Accounts::Account newChequingAcc{name, date_of_birth};
    return newChequingAcc;
};

// Accounts::Account Accounts::openSavingsAccount(std::string name, std::string date_of_birth) {
//     Account newSavingsAccount{};
//     return newSavingsAccount;
// };

void Accounts::Account::addFunds(double funds){
    m_available_funds = mSQL::depositFunds(m_id, funds);
    std::cout << "Money deposited: " << funds << '\n';
};
