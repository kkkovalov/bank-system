#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../header.h"

namespace Transactions {

uint64_t generateRandomTransactionId();

class Transaction {
  public:
    uint64_t m_id{};
    Accounts::Account m_sender{};
    Accounts::Account m_receiver{};
    double m_amount{0.0};

    Transaction(const Accounts::Account &sender, const Accounts::Account &receiver,
                const double &amount)
        : m_sender{sender}, m_receiver{receiver},
          m_amount{amount} {m_id = generateRandomTransactionId()};
}

}; // namespace Transactions

#endif
