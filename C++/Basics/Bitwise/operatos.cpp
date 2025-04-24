#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 3, b = 7;

    int n = 1;

    cout << (a & b) << endl;
    cout << (a | b) << endl;
    cout << (a ^ b) << endl;

    // Left Shift formula -> a * 2^b
    cout << (n << 3) << endl;
    cout << (10 << 2) << endl;

    // Right Shift formula -> a / 2^b
    cout << (10 >> 1) << endl;
    cout << (8 >> 2) << endl;

    return 0;
}