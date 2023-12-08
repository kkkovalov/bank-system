#include <accounts.h>
#include <currency.h>
#include <iostream>

void accessAccount(){

};

void openAccount() {
    std::cout << "\t\tOpening an account!\n\n";
    std::cout << "Please enter your full name: ";
    std::string full_name{};
    std::getline(std::cin, full_name);
    std::cout << "Select the type of the account:\n" std::cout
              << "1 - Chequing\n";
    std::cout << "2 - Savings\n";
    int selection{0};
    bool validSelection{false};
    do {
        std::cout << "Selected: ";
        std::cin >> selection;
        switch (selection) {
        case 1:
            validSelection = true;
            Accounts::openChequingAccount();
            break;
        case 2:
            validSelection = true;
            Accounts::openSavingsAccount();
        default:
            std::cout << "Invalid input. Please try again!\n";
            break;
        }
    } while () return;
};

void exitBank() {
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
    std::cout
        << "\n\t\tWelcome to the Bank of Kovalov!\n\nWe are here to assist "
           "you with everyday banking.\n";
    std::cout << "Select from options below:\n\n";
    std::cout << "1 - Access my account.\n";
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
    std::cout << "end of initiation.\n";
};

int main() {

    initiateBanking();

    return 0;
};
