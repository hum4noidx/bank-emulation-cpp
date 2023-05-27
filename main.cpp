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

void print_menu() {
    std::cout << "Select an option:\n";
    std::cout << "1. Create account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Transfer\n";
    std::cout << "5. View Balance\n";
    std::cout << "6. View Transaction History\n";
    std::cout << "7. Close Account\n";
    std::cout << "8. Display all accounts\n";
    std::cout << "9. Exit\n";
}

int main() {
    Bank myBank("Awesome Bank", "Main Street");

    while (true) {
        print_menu();

        int choice;
        std::cin >> choice;
        std::cin.ignore();  // to clear the newline character from the buffer

        if (choice == 9) break;

        std::vector<std::string> args;
        std::string arg1, arg2;
        double amount;

        switch (choice) {
            case 1:
                std::cout << "Enter account name, account number and initial amount: ";
                std::cin >> arg1 >> arg2 >> amount;
                handle_create(myBank, arg1, arg2, amount);
                break;
            case 2:
                std::cout << "Enter account number and deposit amount: ";
                std::cin >> arg1 >> amount;
                handle_deposit(myBank, arg1, amount);
                break;
            case 3:
                std::cout << "Enter account number and withdrawal amount: ";
                std::cin >> arg1 >> amount;
                handle_withdraw(myBank, arg1, amount);
                break;
            case 4:
                std::cout << "Enter from account number, to account number and transfer amount: ";
                std::cin >> arg1 >> arg2 >> amount;
                handle_transfer(myBank, arg1, arg2, amount);
                break;
            case 5:
                std::cout << "Enter account number: ";
                std::cin >> arg1;
                handle_balance(myBank, arg1);
                break;
            case 6:
                std::cout << "Enter account number: ";
                std::cin >> arg1;
                handle_history(myBank, arg1);
                break;
            case 7:
                std::cout << "Enter account number: ";
                std::cin >> arg1;
                handle_close(myBank, arg1);
                break;
            case 8:
                myBank.display_all_accounts();
                break;
            default:
                std::cout << "Invalid option, try again.\n";
        }
    }

    return 0;
}