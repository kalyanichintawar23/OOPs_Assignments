#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "\nEnter number of elements for this test case: ";
        cin >> n;

        vector<int> numbers(n);

        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        cout << "\nElements in vector: ";
        for (int i = 0; i < n; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;

        if (!numbers.empty()) {
            numbers.pop_back();
            cout << "After removing last element (pop_back): ";
            for (int val : numbers) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
