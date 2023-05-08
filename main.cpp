#include <iostream>
#include <string>
#include "headers/Bank.h"

int main() {
    Bank myBank("Awesome Bank", "Main Street");

    std::string input;
    while (true) {
        std::cout << "Enter a command (create, deposit, withdraw, transfer, balance, history, close, display, exit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        std::string command;
        std::string arg1, arg2, arg3;
        double amount = 0;
        size_t space_pos1 = input.find(' ');
        size_t space_pos2 = std::string::npos;
        size_t space_pos3 = std::string::npos;

        if (space_pos1 != std::string::npos) {
            command = input.substr(0, space_pos1);
            space_pos2 = input.find(' ', space_pos1 + 1);
        } else {
            command = input;
        }

        if (space_pos2 != std::string::npos) {
            arg1 = input.substr(space_pos1 + 1, space_pos2 - space_pos1 - 1);
            space_pos3 = input.find(' ', space_pos2 + 1);
        }

        if (space_pos3 != std::string::npos) {
            arg2 = input.substr(space_pos2 + 1, space_pos3 - space_pos2 - 1);
            amount = std::stod(input.substr(space_pos3 + 1));
        } else if (space_pos2 != std::string::npos) {
            arg2 = input.substr(space_pos2 + 1);
        } else {
            arg1 = input.substr(space_pos1 + 1);
        }

        try {
            if (command == "create") {
                try {
                    if (arg1.empty() || arg2.empty()) {
                        throw std::runtime_error("Error: name and account number are required.");
                    } else if (amount <= 0) {
                        throw std::runtime_error("Error: initial balance must be greater than zero.");
                    } else {
                        myBank.create_account(arg1, arg2, amount);
                        std::cout << "Account created successfully." << std::endl;
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else if (command == "deposit") {
                try {
                    if (arg1.empty()) {
                        throw std::runtime_error("Error: account number is required.");
                    } else if (amount <= 0) {
                        throw std::runtime_error("Error: deposit amount must be greater than zero.");
                    } else {
                        myBank.deposit(arg1, amount);
                        std::cout << "Deposit successful." << std::endl;
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else if (command == "withdraw") {
                try {
                    if (arg1.empty()) {
                        throw std::runtime_error("Error: account number is required.");
                    } else if (amount <= 0) {
                        throw std::runtime_error("Error: withdrawal amount must be greater than zero.");
                    } else {
                        myBank.withdraw(arg1, amount);
                        std::cout << "Withdrawal successful." << std::endl;
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else if (command == "transfer") {
                try {
                    if (arg1.empty() || arg2.empty()) {
                        throw std::runtime_error("Error: sender and recipient account numbers are required.");
                    } else if (amount <= 0) {
                        throw std::runtime_error("Error: transfer amount must be greater than zero.");
                    } else {
                        myBank.transfer(arg1, arg2, amount);
                        std::cout << "Transfer successful." << std::endl;
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else if (command == "balance") {
                try {
                    if (arg1.empty()) {
                        throw std::runtime_error("Error: account number is required.");
                    } else {
                        myBank.view_balance(arg1);
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else if (command == "history") {
                try {
                    if (arg1.empty()) {
                        throw std::runtime_error("Error: account number is required.");
                    } else {
                        myBank.view_transaction_history(arg1);
                    }
                } catch (const std::exception &e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                }
            } else if (command == "close") {
                myBank.close_account(arg1);
            } else if (command == "display") {
                myBank.display_all_accounts();
            } else {
                std::cout << "Invalid command." << std::endl;
            }
        } catch (const std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
