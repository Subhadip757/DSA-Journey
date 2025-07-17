#include<bits/stdc++.h>
using namespace std;

int findPow(int a, int b, int m){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }

    int x = findPow(a, b/2, m) % m;
    int ans = 0;
    if(b % 2 != 0){
        ans = (x % m * x % m) % m;
        ans = (ans % m * a % m) % m;
    }
    else{
        ans = (x % m * x % m) % m;
    }
    return ans;
}

int main()
{
    int a, b;
    cin>>a>>b;

    int m = 100;

    cout<<findPow(a, b, m);
    return 0;
}