#include <iostream>

void accessAccount(){

};

void openAccount() { 
    std::cout << "\t\tOpening an account!\n\n";
    
    return; 

};

void exitBank() {
    std::cout << "Are you sure you want to end this session?\n";
    std::cout << "1 - End session.\n";
    std::cout << "2 - Continue the current session.\n";
    std::cout << "Selected: ";
    int selection{0};
    bool validSelection{false};
    do {
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
            std::cout << "Please try again!\nSelect an option: ";
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
    std::cout << "Selected: ";
    int selection{0};
    bool validSelection{false};
    do {
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
            std::cout << "Please try again!\nSelect an option: ";
            break;
        }
    } while (!validSelection);
    std::cout << "end of initiation.\n";
};

int main() {

    initiateBanking();

    return 0;
};
