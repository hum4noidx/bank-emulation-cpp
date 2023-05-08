#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string account_number;
    std::string account_holder_name;
    double balance;

public:
    Account(std::string number, std::string name, double initial_balance);
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    const std::string &get_account_number() const;
    const std::string &get_account_holder_name() const;
};

#endif
