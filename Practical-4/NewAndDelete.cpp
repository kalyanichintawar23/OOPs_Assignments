#include <iostream>
using namespace std;

void addTax(float &total) {
    total = total + (total * 0.05);
}

int main() {
    int days;
    
    cout << "Enter number of days: ";
    cin >> days;

    float* expenses = new float[days];

    cout << "Enter expenses for each day:" << endl;
    for (int i = 0; i < days; i++) {
        cout << "Day " << i + 1 << ": ";
        cin >> *(expenses + i);
    }

    float totalExpense = 0;
    for (int i = 0; i < days; i++) {
        totalExpense += *(expenses + i);
    }

    cout << "\nTotal Expense before tax: $" << totalExpense << endl;

    addTax(totalExpense);

    cout << "Total Expense after 5% tax: $" << totalExpense << endl;

    delete[] expenses;

    return 0;
}
