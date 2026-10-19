#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string holderName;
    double balance;

public:
    BankAccount(string accNum, string name, double bal) {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited cash: $" << amount << endl;
    }

    void deposit(double amount, int chequeNumber) {
        balance += amount;
        cout << "Deposited cheque #" << chequeNumber << " for amount: $" << amount << endl;
    }

    bool operator==(const BankAccount& other) {
        return (this->accountNumber == other.accountNumber);
    }

    virtual void calculateInterest() {
        cout << "Standard Bank Account: Base interest applied." << endl;
    }

    virtual void displayDetails() {
        cout << "Account No: " << accountNumber << " | Name: " << holderName << " | Balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string name, double bal, double rate) 
        : BankAccount(accNum, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100.0);
        balance += interest;
        cout << "Savings Account Interest Added: $" << interest << endl;
    }

    void displayDetails() override {
        cout << "[Savings] Account No: " << accountNumber << " | Name: " << holderName << " | Balance: $" << balance << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double maintenanceFee;

public:
    CurrentAccount(string accNum, string name, double bal, double fee) 
        : BankAccount(accNum, name, bal) {
        maintenanceFee = fee;
    }

    void calculateInterest() override {
        balance -= maintenanceFee;
        cout << "Current Account: No interest. Maintenance fee deducted: $" << maintenanceFee << endl;
    }

    void displayDetails() override {
        cout << "[Current] Account No: " << accountNumber << " | Name: " << holderName << " | Balance: $" << balance << endl;
    }
};

int main() {
    cout << "=== 1. Function Overloading ===" << endl;
    SavingsAccount sa1("SAV101", "Rahul Sharma", 5000.0, 4.0);
    sa1.deposit(1200.0);
    sa1.deposit(3500.0, 882104);

    cout << "\n=== 2. Operator Overloading ===" << endl;
    SavingsAccount sa2("SAV101", "Rahul Sharma", 5000.0, 4.0);
    SavingsAccount sa3("SAV102", "Aman Verma", 3000.0, 4.0);

    if (sa1 == sa2) {
        cout << "sa1 and sa2 represent the SAME bank account." << endl;
    } else {
        cout << "sa1 and sa2 represent DIFFERENT bank accounts." << endl;
    }

    if (sa1 == sa3) {
        cout << "sa1 and sa3 represent the SAME bank account." << endl;
    } else {
        cout << "sa1 and sa3 represent DIFFERENT bank accounts." << endl;
    }

    cout << "\n=== 3. Virtual Functions & Dynamic Binding ===" << endl;
    BankAccount* accounts[2];
    accounts[0] = new SavingsAccount("SAV200", "Priya Patil", 10000.0, 5.0);
    accounts[1] = new CurrentAccount("CUR500", "Suresh Pawar", 20000.0, 150.0);

    for (int i = 0; i < 2; i++) {
        accounts[i]->displayDetails();
        accounts[i]->calculateInterest();
        accounts[i]->displayDetails();
        cout << "-----------------------------------" << endl;
    }

    delete accounts[0];
    delete accounts[1];

    return 0;
}
