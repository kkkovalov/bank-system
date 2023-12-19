#include "header.h"

int main() {
    std::istringstream ss("08/31/2003");
    std::tm date = {};

    // Parse the date string
    ss >> std::get_time(&date, "%m/%d/%Y");
    Accounts::Account newAcc{"Vladyslav Kovalov", date};

    std::cout << "newAcc.id: " << newAcc.getId() << '\n';
    std::cout << "newAcc.name: " << newAcc.getName() << '\n';
    std::cout << "newAcc.date_of_birth: " << newAcc.getDateOfBirth() << '\n';
};
