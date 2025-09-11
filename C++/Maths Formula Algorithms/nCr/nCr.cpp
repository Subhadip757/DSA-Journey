#include<iostream>
using namespace std;

int fact(int n){
    if(n <= 1) return n;
    return n * fact(n - 1);
}

int ncrFactorial(int n, int r){
    if(r == 0 || r == n) return 1;
    if(r > n) return 0;

    return fact(n)/fact(r)/fact(n-r);
}

int ncr(int n, int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int main(){
    int n = 5, r = 2;
    cout<<"Value: "<<ncrFactorial(n, r);
}