#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
    int ans = 0;
    int power = 1;

    while (n > 0)
    {
        int digit = n % 10;
        ans += digit * power;
        power *= 2;
        n /= 10;
    }

    return ans;
}

int decimalToBinary(int n)
{
    int ans = 0;
    int power = 1;

    while (n > 0)
    {
        int dig = n % 2;
        ans += dig * power;
        power *= 10;
        n /= 2;
    }
    return ans;
}

int main()
{

    cout << binaryToDecimal(101) << endl;
    cout << decimalToBinary(4) << endl;
    return 0;
}