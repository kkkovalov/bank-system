#include "transactions.h"

std::string Transactions::generateRandomTransactionId() {
    const std::string alphanumericChars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int idLength = 10;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, alphanumericChars.size() - 1);

    std::string randomId;

    for (int i = 0; i < idLength; ++i) {
        randomId += alphanumericChars[distribution(gen)];
    };
    return randomId;
};

bool verifyAccountId(uint64_t accountId) const{
    // SQL Database look up for accountId
};


std::string Transactions::Transaction::getTimestampAsString() const{
    auto time = std::chrono::system_clock::to_time_t(m_timestamp);
    std::tm tm_time = *std::localtime(&time); // Convert to local time

    // Format the date and time as MM/DD/YYYY HH:MM:SS
    std::ostringstream oss;
    oss << std::put_time(&tm_time, "%m/%d/%Y %H:%M:%S");

    return oss.str();
};

std::ostream &Transactions::operator<<(std::ostream &out, const Transaction &transaction) {
    out << transaction.getTimestampAsString() << " -> ID: " << transaction.m_id << " || " << transaction.m_sender_id
        << " -> " << transaction.m_receiver_id << " || " << transaction.m_amount << '\n';

    return out;
};
