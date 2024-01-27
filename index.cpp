/*      TASKS TO COMPLETE:

Bank account encompasses a generic information, with no access to funds. Chequing or Savings account
may be linked to your bank account. Thus allowing you to utilize bank in your day-to-day activities.

[ ] - Basic interaction with a bank
    [ ] - Create new account
        [ ] -  see accounts.h for tasks

    [ ] - Access existing account
    [ ] - Transfer funds between two accounts
    [x] - Exit the bank


[x] - SQL Connection
    [x] - see mysql.h for implementation
*/

#include "header.h"

// Forward function declaration
void exitBank(const char &typeOfExit);

void accessAccount(){

};

// Function to verify that date of birth is in format MM/DD/YYYY
bool isValidDate(const std::string &date_of_birth) {
    std::istringstream ss(date_of_birth);
    std::tm date = {};

    // Parse the date string
    ss >> std::get_time(&date, "%Y/%m/%d");

    if (ss.fail()) {
        std::cerr << "Invalid date format. Please try again.\n";
        return false;
    };

    if (date.tm_mon < 0 || date.tm_mon > 11) {
        std::cerr << "Invalid month. Please try again.\n";
        return false;
    };

    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm currentYearTM = *std::localtime(&now);
    int inputYear = date.tm_year + 1900;
    int currentYear = currentYearTM.tm_year + 1900;
    if (inputYear < 1900 || inputYear > currentYear) {
        std::cerr << "Invalid year. Please try again.\n";
        return false;
    } else if (currentYear - inputYear < 18) {
        std::cerr << "Unfortunately you cannot be under 18 to open an account with us.\n"
                  << "We will be glad to have your business when you turn 18.";
        exitBank('F');
        return false;
    };

    int maxDays = 31;
    if (date.tm_mon == 3 || date.tm_mon == 5 || date.tm_mon == 8 || date.tm_mon == 10)
        maxDays = 30;
    else if (date.tm_mon == 1) {
        maxDays = (date.tm_year);
    };
    if (date.tm_mday < 1 || date.tm_mday > maxDays) {
        std::cerr << "Invalid day for the given month. Please try again.\n";
        return false;
    };
    return true;
};

void openAccount() {
    std::cout << "\t\tOpening an account!\n\n";
    std::cout << "Enter your full name: ";
    std::string full_name{};
    std::cin.ignore();
    std::getline(std::cin, full_name);
    std::string date_of_birth{};
    do {
        std::cout << "Enter your date of birth in format YYYY/MM/DD: ";
        std::cin.clear();
        std::cin >> date_of_birth;
    } while (!isValidDate(date_of_birth));
    // std::cout << "Select the type of the account:\n";
    // std::cout << "1 - Chequing\n";
    // std::cout << "2 - Savings\n";
    // int selection{0};
    // bool validSelection{false};
    // do {
    //     std::cout << "Selected: ";
    //     std::cin >> selection;
    //     switch (selection) {
    //     case 1:
    //         validSelection = true;
        Accounts::openChequingAccount(full_name, date_of_birth);
        // accessAccount(id, verified=true;
    // break;
    // case 2:
    //     validSelection = true;
    //     std::cout << Accounts::openSavingsAccount(full_name, date_of_birth);
    //     break;
    // default:
    //     std::cout << "Invalid input. Please try again!\n";
    //     break;
    // }
    // }
    // while (!validSelection)
    //     ;
};

void exitBank(const char &typeOfExit = 'R') {
    if (typeOfExit == 'F')
        std::exit(0);
    std::cout << "Are you sure you want to end this session?\n";
    std::cout << "1 - End session.\n";
    std::cout << "2 - Continue the current session.\n";
    int selection{0};
    bool validSelection{false};
    do {
        std::cout << "Selected: ";
        std::cin >> selection;
        switch (selection) {
        case 1:
            validSelection = true;
            std::exit(0);
            break;
        case 2:
            validSelection = true;
            return;
            break;
        default:
            validSelection = false;
            std::cout << "Invalid input. Please try again!\n";
            break;
        }
    } while (validSelection);
};

void initiateBanking() {
    std::cout << "\n\t\tWelcome to the Bank of Kovalov!\n\nWe are here to assist you with everyday banking.\n";
    std::cout << "Select from options below:\n\n";
    std::cout << "1 - Enter my account.\n";
    std::cout << "2 - Open a new account.\n";
    std::cout << "3 - Exit the bank.\n";

    int selection{0};
    bool validSelection{false};
    do {
        std::cout << "Selected: ";
        std::cin >> selection;
        switch (selection) {
        case 1:
            validSelection = true;
            accessAccount();
            break;
        case 2:
            validSelection = true;
            openAccount();
            break;
        case 3:
            validSelection = true;
            exitBank();
            break;
        default:
            validSelection = false;
            std::cout << "Invalid input. Please try again!\n";
            break;
        }
    } while (!validSelection);
    // std::cout << "end of initiation.\n";
};

int main() {
    initiateBanking();

    return 0;
};
