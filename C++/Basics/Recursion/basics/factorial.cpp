#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
    
    int result = n * factorial(n-1);
    return result;
}

int main(){
    int n;
    cout<<"Enter number: "<<endl;
    cin>>n;

    int ans = factorial(n);
    cout<<ans<<endl;
}