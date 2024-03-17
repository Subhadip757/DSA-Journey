#include <iostream>
#include <cmath>
using namespace std;

int armstrong(int n){
    int sum = 1;
    while(n!=0){
        int digit = n % 10;
        int cube = pow(digit,3);
        sum += cube;
        n /= 10;
    }
    return sum;
}

int main(){
    int number = 154;
    int result = armstrong(number);

    if(number == result){
        cout<<"This is a armstrong number";
    }else{
        cout<<"This is not a armstrong number";
    }
}