#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

enum class TransactionType {
    Deposit,
    Withdrawal,
    Transfer
};

class Transaction {
private:
    std::string transaction_id;
    std::time_t transaction_date;
    TransactionType transaction_type;
    double transaction_amount;
    std::string account_number;

public:
    Transaction(const std::string &id, TransactionType type, double amount, const std::string &acc_number);
    const std::string &get_transaction_id() const;
    std::time_t get_transaction_date() const;
    TransactionType get_transaction_type() const;
    double get_transaction_amount() const;
    const std::string &get_account_number() const;
};

#endif
