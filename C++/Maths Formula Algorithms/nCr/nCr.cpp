#include<iostream>
using namespace std;

int ncr(int n, int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

int main(){
    int n = 4, r = 2;
    cout<<"Value: "<<ncr(n, r);
}