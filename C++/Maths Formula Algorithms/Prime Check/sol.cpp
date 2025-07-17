#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int val = 7;

    if(checkPrime(val)){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }
}