#include <iostream>
using namespace std;

double functionA(int n) {
    if (n == 1)
        return 1.0;
    return (1.0 / n) + functionA(n - 1);
}
double overloadedFunctionA() {
    int x;
    cout << "Enter a positive integer: ";
    cin >> x;

    if (x <= 0) {
        cout << "Please enter a positive integer." << endl;
        return -1;
    }

    return functionA(x);
}



int main() {
    int n;
    double x;
    cout << "Enter a positive integer n: ";
    cin >> n;
    x = overloadedFunctionA();

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    double result = functionA(n);
    cout << "First Result is " << result << endl;
    cout << "Second Result is " << x << endl;




    return 0;
}
