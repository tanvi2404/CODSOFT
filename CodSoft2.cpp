#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    cout << "Enter second number: ";
    cin >> num2;

    switch(operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;

        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            } else {
                cout << "Error! Division by zero is not allowed.";
            }
            break;

        default:
            cout << "Invalid operator. Please use +, -, *, or /.";
            break;
    }

    return 0;
}

