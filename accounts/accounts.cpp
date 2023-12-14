#include <iostream>
#include <string>
#include "accounts.h"
using namespace Accounts;


uint32_t Account::getId(){
    return m_id;
};


Account openChequingAccount(){
    std::string name{};
    std::cout << "\n\t\tOpening a new chequing account.\n\n";
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    Account newChequingAcc{name};
    return newChequingAcc;
};
