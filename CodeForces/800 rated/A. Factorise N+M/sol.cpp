#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    if(n == 0 || n == 1) return false;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }

    return true;
}

int main()
{
    int n;cin>>n;
    while(n--){
        int a;
        cin>>a;

        for(int i = 1; i <= 10; i++){
            if(checkPrime(i)){
                if(!checkPrime(a + i)){
                    cout<<i<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}