#include <iostream>
using namespace std;

class ShoppingCart {
private:
    double totalAmount;
public:
    ShoppingCart() {
        totalAmount = 0.0;
    }

    ShoppingCart(double amount) {
        totalAmount = amount;
    }

    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart temp;
        temp.totalAmount = totalAmount + other.totalAmount;
        return temp;
    }

    void display() {
        cout << "Total Amount: $" << totalAmount << endl;
    }
};
int main() {
    ShoppingCart cart1(45.50);
    ShoppingCart cart2(25.25);

    ShoppingCart finalCart;
    finalCart = cart1 + cart2;

    cout << "Cart 1 ";
    cart1.display();

    cout << "Cart 2 ";
    cart2.display();

    cout << "Combined ";
    finalCart.display();

    return 0;
}
