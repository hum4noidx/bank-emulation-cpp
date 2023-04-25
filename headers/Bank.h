#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "Account.h"
#include "Transaction.h"

class Bank {
private:
    std::string bank_name;
    std::string branch_location;
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;

public:
    Bank(std::string name, std::string location);
    void create_account(const std::string &name, const std::string &acc_number, double initial_balance);
    void deposit(const std::string &acc_number, double amount);
    void withdraw(const std::string &acc_number, double amount);
    void transfer(const std::string &sender_acc_number, const std::string &recipient_acc_number, double amount);
    void view_balance(const std::string &acc_number) const;
    void view_transaction_history(const std::string &acc_number) const;
    void close_account(const std::string &acc_number);
    void display_all_accounts() const;
};

#endif
