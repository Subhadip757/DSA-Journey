#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a = 12, b = 18;
    std::cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << std::endl;
    return 0;
}