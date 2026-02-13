#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;

    for (int i = 0; i < x.length(); i++) {
        int digit = x[i] - '0';
        int inverted = 9 - digit;

        // Don't invert if:
        // 1. It's the first digit and inversion would lead to a 0
        // 2. Inversion doesn't make it smaller
        if (i == 0 && inverted == 0) continue;

        if (inverted < digit) {
            x[i] = inverted + '0';
        }
    }

    cout << x << endl;
    return 0;
}