#include <bits/stdc++.h>
using namespace std;

void f(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }

    cout << prev1;
}

int main()
{
    int n = 10;
    f(n);
}