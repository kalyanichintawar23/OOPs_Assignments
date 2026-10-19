#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
        cout << "Account created for " << accountHolder << endl;
    }

    ~BankAccount() {
        cout << "Account closed for " << accountHolder << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid or insufficient funds!" << endl;
        }
    }

    void displayDetails() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Holder Name: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-----------------------\n" << endl;
    }
};

int main() {
    BankAccount myAccount("Alex Smith", 1001, 500.0);

    myAccount.displayDetails();
    myAccount.deposit(150.50);
    myAccount.withdraw(200.0);
    myAccount.displayDetails();

    return 0;
}