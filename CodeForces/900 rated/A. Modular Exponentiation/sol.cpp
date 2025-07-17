#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    if (n >= 63) {
        cout << m << endl;
    }
     else {
        long long mod = 1LL << n; 
        cout << m % mod << endl;
    }
    return 0;
}