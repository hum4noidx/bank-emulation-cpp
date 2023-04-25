#include "../headers/Transaction.h"

Transaction::Transaction(const std::string &id, TransactionType type, double amount, const std::string &acc_number)
        : transaction_id(id), transaction_type(type), transaction_amount(amount), account_number(acc_number) {
    transaction_date = std::time(nullptr);
}

const std::string &Transaction::get_transaction_id() const {
    return transaction_id;
}

std::time_t Transaction::get_transaction_date() const {
    return transaction_date;
}

TransactionType Transaction::get_transaction_type() const {
    return transaction_type;
}

double Transaction::get_transaction_amount() const {
    return transaction_amount;
}

const std::string &Transaction::get_account_number() const {
    return account_number;
}
