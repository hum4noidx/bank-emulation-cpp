#include <utility>
#include <stdexcept>

#include "../headers/Account.h"

Account::Account(std::string number, std::string name, double initial_balance)
        : account_number(std::move(number)), account_holder_name(std::move(name)), balance(initial_balance) {}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        throw std::runtime_error("Insufficient funds.");
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
