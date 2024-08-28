#include<iostream>
using namespace std;

int fact(int n){
    if(n <= 1){
        return 1;
    }
    return n * fact(n - 1);
}

int fibo(int n){
    if(n == 1){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    return fibo(n - 1) + fibo(n - 2);
}

int main(){

    // cout<<fact(100)<<endl;
    // cout<<fibo(10)<<endl;

    // int a = 5;
    // int b = 10;

    // a = a + b;
    // b = a - b;
    // a = a - b;

    // cout<<"A: "<<a <<" B: "<< b <<endl;

    // int sumEven = 0;
    // int sumOdd = 0;

    // for(int i = 0; i < 5; i++){
    //     int a;
    //     cin>>a;

    //     if(a % 2 == 0){
    //         sumEven += a;
    //     }
    //     if(a % 2 == 1){
    //         sumOdd += a;
    //     }
    // }
    // cout<<"SumEven: "<<sumEven<<" SumOdd: "<<sumOdd<<endl;


    // int n;
    // cin>>n;
    // int i = 1;
    // while(i <= n){
    //     int space = n - i;
    //     while(space){
    //         cout<<" ";
    //         space--;
    //     }
    //     int j = 1;
    //     while(j<=i){
    //         cout<<j;
    //         j++;
    //     }
    //     int start = i-1;
    //     while(start){
    //         cout<<start;
    //         start--;
    //     }
    //     cout<<endl;
    //     i++;
    // }


    // int n = 3;
    
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n - i; j++) {
    //         cout << " ";
    //     }

    //     for(int j = i; j <= 2 * i - 1; j++) {
    //         cout << j;
    //     }

    //     for(int j = 2 * i - 2; j >= i; j--) {
    //         cout << j;
    //     }
    //     cout << endl;
    // }

}