#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../accounts/accounts.h"
#include "../header.h"

namespace Transactions {

// Generates a random 10-character alphanumeric string for transaction identification.
std::string generateRandomTransactionId();

class Transaction {
  public:
    std::string m_id{};
    uint64_t m_sender_id;
    uint64_t m_receiver_id;
    double m_amount{0.0};
    std::chrono::system_clock::time_point m_timestamp{};

    Transaction(const uint64_t sender_id, const uint64_t receiver_id, const double &amount)
        : m_sender_id{sender_id}, m_receiver_id{receiver_id}, m_amount{amount} {
        // verify sender_id function
        // verify receiver_id function
        // verify balance of the sender function

        // Generating a random transaction id
        std::srand(std::max(receiver_id, sender_id));
        m_id = generateRandomTransactionId();

        // Generating a timestamp of the transaction
        m_timestamp = std::chrono::system_clock::now();

        // To be removed latter
        std::cout << "Created a new transaction -> " << m_id << '\n';
    };

    // Get timestamp of the transaction in string format "MM/DD/YYYY HH:MM:SS"
    std::string getTimestampAsString() const;

    friend std::ostream &operator<<(std::ostream &out, const Transaction &transaction);
};

}; // namespace Transactions

#endif
