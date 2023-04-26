# Console-based Banking Application

A simple console-based banking application in C++ that allows users to manage their bank accounts and perform various
operations like creating an account, depositing, withdrawing, transferring funds, checking balance, viewing transaction
history, closing an account, and displaying all accounts.

## Prerequisites

- A C++ compiler with support for C++23 (e.g., GCC, Clang, or Visual Studio)

## How to Compile and Run

### Using CMake

1. Clone or download the repository.
2. Create a build directory in the project root:

   `mkdir build`

   `cd build`
3. Run CMake and compile the project:
   ```bash 
   cmake ..
   cmake --build .
   ```
4. Run the generated executable file (named `your_project_name` or `your_project_name.exe` on Windows):

`./your_project_name`
## Example Commands

- Create a new account: `create JohnDoe 1234567890 1000`

This command creates an account for `John Doe` with the account number `1234567890` and an initial deposit of `$1000`.

- Deposit money into an account: `deposit 1234567890 500`

This command deposits `$500` into the account with the account number `1234567890`.

- Withdraw money from an account: `withdraw 1234567890 200`

This command withdraws $200 from the account with the account number `1234567890`.

- Transfer money between two accounts: `transfer 1234567890 9876543210 300`

This command transfers `$300` from the account with the account number `1234567890` to the account with the account
number `9876543210`.

- View the account balance: `balance 1234567890`

This command displays the balance of the account with the account number `1234567890`.

- View the transaction history of an account: `history 1234567890`

This command shows the transaction history for the account with the account number `1234567890`.

- Close an account: `close 1234567890`

This command closes the account with the account number `1234567890`.

- Display all registered accounts: `display`

This command shows the account number, account holder name, and balance of all registered accounts.

- Exit the application: `exit`

This command exits the console-based banking application.

## Project structure

```js
bank - emulation - app /
    ├── main.cpp
    ├── CMakeLists.txt
    ├── headers /
    │   ├── Account.h
    │   ├── Bank.h
    │   ├── Transaction.h
    ├── sources /
    │   ├── Account.cpp
    │   ├── Bank.cpp
    │   ├── Transaction.cpp
    └── CMakeLists.txt
```