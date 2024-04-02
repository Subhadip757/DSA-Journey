#include <iostream>
using namespace std;
 
int main(){

    // sum of n numbers
    /*int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    int sum = 0;
    for(int i = 1;i<=n;i++){
        sum += i;
    }
    cout<<sum<<endl;*/

    // Fibonacci
    /*int n = 10;
    int a = 0;
    int b = 1;

    cout<<a<<" "<<b<<" ";
    for(int i = 1;i<=n;i++){
        int nextNum = a+b;
        cout<<nextNum<<" ";

        a=b;
        b=nextNum;
    }*/

    // Prime
    /*int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;

    bool isPrime = 1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            isPrime = 0;
            break;
        }
    }
    if(isPrime == 0){
        cout<<"Not a Prime number";
    }else{
        cout<<"Prime Number";
    }*/

    for(int i=0; i<5;i++){
        for(int j=1;j<=5;j++){
            if(i+j==10){
                break;
            }
            cout<<i<< " "<<j<<endl;
        }
    }
}