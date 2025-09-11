#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n = 13, c = 0;

    while(n > 1){
        c += (n & 1);
        n >>= 1;
    }

    if(n == 1){
        c++;
    }

    cout<<"Number of set bits: "<<c<<endl;
    return 0;
}