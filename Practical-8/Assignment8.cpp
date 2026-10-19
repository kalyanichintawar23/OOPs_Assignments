#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(string accNum, string name, double initialBalance) {
        if (initialBalance < 0) {
            throw "Initial balance cannot be negative!";
        }
        accountNumber = accNum;
        holderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw "Deposit amount must be greater than zero!";
        }
        balance += amount;
        cout << "Deposit successful! New Balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw "Withdrawal amount must be greater than zero!";
        }
        if (amount > balance) {
            throw "Insufficient balance for withdrawal!";
        }
        balance -= amount;
        cout << "Withdrawal successful! Remaining Balance: $" << balance << endl;
    }

    void transfer(BankAccount& receiver, double amount, int targetAccLength) {
        if (targetAccLength != 10) {
            throw 101;
        }
        if (amount > balance) {
            throw "Insufficient balance for transfer!";
        }
        balance -= amount;
        receiver.balance += amount;
        cout << "Transfer successful! $" << amount << " sent to " << receiver.holderName << endl;
    }

    void verifyPin(int enteredPin, int correctPin) {
        if (enteredPin != correctPin) {
            throw 401;
        }
        cout << "PIN verification successful!" << endl;
    }

    void displayDetails() {
        cout << "Account: " << accountNumber << " | Name: " << holderName << " | Balance: $" << balance << endl;
    }
};

int main() {
    cout << "=== 1. Valid Account Operations ===" << endl;
    try {
        BankAccount acc1("ACC1001", "Rahul Sharma", 5000.0);
        acc1.displayDetails();
        acc1.deposit(1500.0);
        acc1.withdraw(2000.0);
    } 
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    } 
    catch (...) {
        cout << "An unexpected error occurred!" << endl;
    }

    cout << "\n=== 2. Handling Negative Deposit/Withdrawal Exception ===" << endl;
    try {
        BankAccount acc2("ACC1002", "Aman Verma", 3000.0);
        acc2.withdraw(-500.0);
    } 
    catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
    }

    cout << "\n=== 3. Handling Insufficient Balance Exception ===" << endl;
    try {
        BankAccount acc3("ACC1003", "Priya Patil", 1000.0);
        acc3.withdraw(2500.0);
    } 
    catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
    }

    cout << "\n=== 4. Handling Integer Error Code (Invalid Account Length) ===" << endl;
    try {
        BankAccount acc4("ACC1004", "Suresh Pawar", 4000.0);
        BankAccount acc5("ACC1005", "Neha Gupta", 2000.0);
        acc4.transfer(acc5, 500.0, 7);
    } 
    catch (int errorCode) {
        cout << "Caught Error Code: " << errorCode << " - Invalid target account number length!" << endl;
    } 
    catch (const char* msg) {
        cout << "Caught Exception: " << msg << endl;
    }

    cout << "\n=== 5. Handling Authentication Exception ===" << endl;
    try {
        BankAccount acc6("ACC1006", "Rohan Mehta", 6000.0);
        acc6.verifyPin(1234, 9999);
    } 
    catch (int errorCode) {
        cout << "Caught Error Code: " << errorCode << " - Authentication Failed! Incorrect PIN." << endl;
    }

    return 0;
}
