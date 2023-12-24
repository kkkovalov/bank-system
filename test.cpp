#include "header.h"

int main() {
    Accounts::Account newReceiver{};
    Accounts::Account newSender{};
    Transactions::Transaction newTransaction{newSender.getId(), newReceiver.getId(), 100.12};

    std::cout << newTransaction;
};
