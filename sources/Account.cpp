#include "../headers/Account.h"

Account::Account(const std::string &number, const std::string &name, double initial_balance)
        : account_number(number), account_holder_name(name), balance(initial_balance) {}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}

double Account::get_balance() const {
    return balance;
}

const std::string &Account::get_account_number() const {
    return account_number;
}

const std::string &Account::get_account_holder_name() const {
    return account_holder_name;
}
