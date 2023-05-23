#include <iostream>
#include <string>
#include "headers/Bank.h"
#include <sstream>

bool check_account(std::string& account) {
    if(account.empty()) {
        std::cout << "Error: account number is required." << std::endl;
        return false;
    }
    return true;
}

bool check_amount(double amount) {
    if (amount <= 0) {
        std::cout << "Error: amount must be greater than zero." << std::endl;
        return false;
    }
    return true;
}

void handle_create(Bank& myBank, std::string& arg1, std::string& arg2, double amount) {
    if(!check_account(arg1) || !check_account(arg2) || !check_amount(amount)) return;
    myBank.create_account(arg1, arg2, amount);
    std::cout << "Account created successfully." << std::endl;
}

void handle_deposit(Bank& myBank, std::string& arg1, double amount) {
    if(!check_account(arg1) || !check_amount(amount)) return;
    myBank.deposit(arg1, amount);
    std::cout << "Deposit successful." << std::endl;
}

void handle_withdraw(Bank& myBank, std::string& arg1, double amount) {
    if(!check_account(arg1) || !check_amount(amount)) return;
    myBank.withdraw(arg1, amount);
    std::cout << "Withdrawal successful." << std::endl;
}

void handle_transfer(Bank& myBank, std::string& arg1, std::string& arg2, double amount) {
    if(!check_account(arg1) || !check_account(arg2) || !check_amount(amount)) return;
    myBank.transfer(arg1, arg2, amount);
    std::cout << "Transfer successful." << std::endl;
}

void handle_balance(Bank& myBank, std::string& arg1) {
    if(!check_account(arg1)) return;
    myBank.view_balance(arg1);
}

void handle_history(Bank& myBank, std::string& arg1) {
    if(!check_account(arg1)) return;
    myBank.view_transaction_history(arg1);
}

void handle_close(Bank& myBank, std::string& arg1) {
    if(!check_account(arg1)) return;
    myBank.close_account(arg1);
    std::cout << "Account closed successfully." << std::endl;
}

void handle_command(Bank& myBank, std::string& command, std::vector<std::string>& args) {
    try {
        if (command == "create") handle_create(myBank, args[0], args[1], std::stod(args[2]));
        else if (command == "deposit") handle_deposit(myBank, args[0], std::stod(args[1]));
        else if (command == "withdraw") handle_withdraw(myBank, args[0], std::stod(args[1]));
        else if (command == "transfer") handle_transfer(myBank, args[0], args[1], std::stod(args[2]));
        else if (command == "balance") handle_balance(myBank, args[0]);
        else if (command == "history") handle_history(myBank, args[0]);
        else if (command == "close") handle_close(myBank, args[0]);
        else if (command == "display") myBank.display_all_accounts();
        else std::cout << "Invalid command." << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    Bank myBank("Awesome Bank", "Main Street");

    std::string input;
    while (true) {
        std::cout << "Enter a command (create, deposit, withdraw, transfer, balance, history, close, display, exit): ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        std::istringstream iss(input);
        std::string command;
        std::vector<std::string> args;
        std::string arg;
        while(iss >> arg) args.push_back(arg);

        if (!args.empty()) {
            command = args[0];
            args.erase(args.begin());
        }

        handle_command(myBank, command, args);
    }

    return 0;
}
