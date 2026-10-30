#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show function" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function" << endl;
    }

    void display() {
        cout << "Derived class display function" << endl;
    }
};

int main() {
    int num;
    cout << "Enter an integer to convert to double: ";
    cin >> num;
    double d = static_cast<double>(num);
    cout << "Static Cast result: " << d << endl;

    double pi;
    cout << "\nEnter a floating-point number to cast to int: ";
    cin >> pi;
    int integerPi = (int)pi;
    cout << "C-Style Cast result: " << integerPi << endl;

    cout << "\nDemonstrating Dynamic Cast:" << endl;
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        cout << "Dynamic Cast successful!" << endl;
        derivedPtr->display();
    } else {
        cout << "Dynamic Cast failed!" << endl;
    }

    int val;
    cout << "\nEnter an integer for const_cast demo: ";
    cin >> val;
    const int constVal = val;
    int* nonConstVal = const_cast<int*>(&constVal);
    cout << "Const Cast value: " << *nonConstVal << endl;

    int x;
    cout << "\nEnter an ASCII integer (e.g., 65 for 'A'): ";
    cin >> x;
    char* charPtr = reinterpret_cast<char*>(&x);
    cout << "Reinterpret Cast (int pointer to char pointer): " << *charPtr << endl;

    delete basePtr;
    return 0;
}
