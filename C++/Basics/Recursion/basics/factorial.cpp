#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int result = n * factorial(n - 1);
    return result;
}

int main(){
    int n = 5;
    int ans = factorial(n);

    cout<<"factorial: "<<ans;
}