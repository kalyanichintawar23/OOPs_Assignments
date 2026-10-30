#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        numbers.push_back(value);
    }

    cout << "List elements: ";
    for (int x : numbers)
        cout << x << " ";
    cout << endl;

    numbers.push_front(10);
    cout << "After push_front(10): ";
    for (int x : numbers)
        cout << x << " ";
    cout << endl;

    numbers.push_back(50);
    cout << "After push_back(50): ";
    for (int x : numbers)
        cout << x << " ";
    cout << endl;

    numbers.pop_front();
    cout << "After pop_front(): ";
    for (int x : numbers)
        cout << x << " ";
    cout << endl;

    numbers.pop_back();
    cout << "After pop_back(): ";
    for (int x : numbers)
        cout << x << " ";
    cout << endl;

    return 0;
}
