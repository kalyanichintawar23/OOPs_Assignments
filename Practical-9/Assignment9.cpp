#include <iostream>
#include <string>
#include <utility>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double* balance;

public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = new double(initialBalance);
        cout << "Constructor: Created Account " << accountNumber << " with $" << *balance << endl;
    }

    ~BankAccount() {
        if (balance != nullptr) {
            cout << "Destructor: Freeing memory for Account " << accountNumber << endl;
            delete balance;
        } else {
            cout << "Destructor: Account " << accountNumber << " has no balance memory (Moved)" << endl;
        }
    }

    BankAccount(const BankAccount& source) {
        accountNumber = source.accountNumber;
        if (source.balance != nullptr) {
            balance = new double(*source.balance);
        } else {
            balance = nullptr;
        }
        cout << "Copy Constructor: DEEP COPY created for " << accountNumber << endl;
    }

    BankAccount(BankAccount&& source) {
        accountNumber = source.accountNumber;
        balance = source.balance;

        source.balance = nullptr;
        source.accountNumber = "EMPTY";
        cout << "Move Constructor: STOLE resource from " << accountNumber << endl;
    }

    BankAccount& operator=(BankAccount&& source) {
        if (this != &source) {
            delete balance;

            accountNumber = source.accountNumber;
            balance = source.balance;

            source.balance = nullptr;
            source.accountNumber = "EMPTY";
            cout << "Move Assignment: STOLE resource via assignment" << endl;
        }
        return *this;
    }

    void display() const {
        if (balance != nullptr) {
            cout << "Account: " << accountNumber << " | Balance: $" << *balance << endl;
        } else {
            cout << "Account: " << accountNumber << " | [No Balance / Resource Transferred]" << endl;
        }
    }
};

int main() {
    cout << "=== 1. Standard Copy Constructor (Deep Copy) ===" << endl;
    BankAccount acc1("ACC1001", 5000.0);
    BankAccount acc2 = acc1;
    acc1.display();
    acc2.display();

    cout << "\n=== 2. Move Constructor using std::move() ===" << endl;
    BankAccount acc3 = std::move(acc1);
    cout << "Source (acc1) after std::move:" << endl;
    acc1.display();
    cout << "Destination (acc3) after std::move:" << endl;
    acc3.display();

    cout << "\n=== 3. Move Assignment Operator ===" << endl;
    BankAccount acc4("ACC2002", 12000.0);
    acc4 = std::move(acc2);
    cout << "Source (acc2) after move assignment:" << endl;
    acc2.display();
    cout << "Destination (acc4) after move assignment:" << endl;
    acc4.display();

    cout << "\n=== Cleanup Operations ===" << endl;
    return 0;
}
