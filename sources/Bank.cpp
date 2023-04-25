#include "../headers/Bank.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <ctime>
#include <utility>


Bank::Bank(std::string bank_name, std::string branch_location)
        : bank_name(std::move(bank_name)), branch_location(std::move(branch_location)) {}

void Bank::create_account(const std::string &name, const std::string &acc_number, double initial_balance) {
    accounts.emplace_back(acc_number, name, initial_balance);

}

void Bank::deposit(const std::string &acc_number, double amount) {
    for (Account &account: accounts) {
        if (account.get_account_number() == acc_number) {
            account.deposit(amount);
            transactions.emplace_back("DEP_" + acc_number, TransactionType::Deposit, amount, acc_number);
            return;
        }
    }
    throw std::runtime_error("Account not found.");
}

void Bank::withdraw(const std::string &acc_number, double amount) {
    for (Account &account: accounts) {
        if (account.get_account_number() == acc_number) {
            account.withdraw(amount);
            transactions.emplace_back("WDR_" + acc_number, TransactionType::Withdrawal, amount, acc_number);
            return;
        }
    }
    throw std::runtime_error("Account not found.");
}

void Bank::transfer(const std::string &sender_acc_number, const std::string &recipient_acc_number, double amount) {
    Account *sender_account = nullptr;
    Account *recipient_account = nullptr;

    for (Account &account: accounts) {
        if (account.get_account_number() == sender_acc_number) {
            sender_account = &account;
        } else if (account.get_account_number() == recipient_acc_number) {
            recipient_account = &account;
        }
    }

    if (sender_account && recipient_account) {
        sender_account->withdraw(amount);
        recipient_account->deposit(amount);
        transactions.emplace_back("TRF_" + sender_acc_number, TransactionType::Transfer, amount, sender_acc_number);
        transactions.emplace_back("TRF_" + recipient_acc_number, TransactionType::Transfer, amount,
                                  recipient_acc_number);
    } else {
        throw std::runtime_error("Sender or recipient account not found.");
    }
}

void Bank::view_balance(const std::string &acc_number) const {
    for (const Account &account: accounts) {
        if (account.get_account_number() == acc_number) {
            std::cout << "Account balance: $" << account.get_balance() << std::endl;
            return;
        }
    }
    throw std::runtime_error("Account not found.");
}

void Bank::view_transaction_history(const std::string &acc_number) const {
    std::cout << "Transaction history for account " << acc_number << ":\n";
    for (const Transaction &transaction: transactions) {
        if (transaction.get_account_number() == acc_number) {
            std::time_t t = transaction.get_transaction_date();
            std::stringstream date_ss;
            date_ss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");
            std::cout << transaction.get_transaction_id() << " | " << date_ss.str() << " | ";
            switch (transaction.get_transaction_type()) {
                case TransactionType::Deposit:
                    std::cout << "Deposit";
                    break;
                case TransactionType::Withdrawal:
                    std::cout << "Withdrawal";
                    break;
                case TransactionType::Transfer:
                    std::cout << "Transfer";
                    break;
            }
            std::cout << " | $" << transaction.get_transaction_amount() << std::endl;
        }
    }
}

void Bank::close_account(const std::string &acc_number) {
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->get_account_number() == acc_number) {
            accounts.erase(it);
            std::cout << "Account " << acc_number << " closed successfully." << std::endl;
            return;
        }
    }
    throw std::runtime_error("Account not found.");
}

void Bank::display_all_accounts() const {
    std::cout << "All accounts registered with the bank:\n";
    for (const Account &account: accounts) {
        std::cout << "Account number: " << account.get_account_number()
                  << " | Account holder name: " << account.get_account_holder_name()
                  << " | Balance: $" << account.get_balance() << std::endl;
    }
}