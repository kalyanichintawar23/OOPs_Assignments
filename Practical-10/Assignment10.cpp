#include <iostream>
using namespace std;

template <typename T>
T getMax(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

template <class T>
class Calculator {
private:
    T num1;
    T num2;

public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    T divide() {
        if (num2 != 0) {
            return num1 / num2;
        } else {
            cout << "Division by zero error!" << endl;
            return 0;
        }
    }

    void displayResults() {
        cout << "Numbers: " << num1 << " and " << num2 << endl;
        cout << "Addition: " << add() << endl;
        cout << "Subtraction: " << subtract() << endl;
        cout << "Multiplication: " << multiply() << endl;
        cout << "Division: " << divide() << endl;
        cout << "Maximum: " << getMax(num1, num2) << endl;
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    cout << "=== Integer Operations ===" << endl;
    Calculator<int> intCalc(10, 5);
    intCalc.displayResults();

    cout << "=== Floating Point Operations ===" << endl;
    Calculator<float> floatCalc(12.5f, 2.5f);
    floatCalc.displayResults();

    return 0;
}
