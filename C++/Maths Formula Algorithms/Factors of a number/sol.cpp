#include<bits/stdc++.h>
using namespace std;

// Efficient
void printFactors(int n){
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            cout<<i<<" ";
            if(n != i){
                cout<<n/i<<" ";
            }
        }
    }
}

int main(){
    int n = 36;
    printFactors(n);
}