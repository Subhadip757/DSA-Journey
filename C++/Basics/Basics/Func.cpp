#include <iostream>
using namespace std;

int power(){
    int a,b;
    cin>>a>>b;
    int ans = 1;

    for(int i=1;i<=b;i++){
        ans = ans * a;
    }
    return ans;
}

bool oddEven(int num){
    if(num % 2 == 0){
        return 1;
    }else{
        return 0;
    }
}

int factorial(int n){
    int ans = 1;
    for(int i = 1;i<=n;i++){
        ans = ans * i;
    }
    return ans;
}

int nCr(int n,int r){
    int num = factorial(n);

    int denom = factorial(r) * factorial(n-r);

    int result = num/denom;

    return result;
}

int main(){
    // int answer = power();
    // cout<<"Answer is: "<<answer<<endl;

    // int even = oddEven(99);
    // cout<<"Answer is: "<<even;

    int ncr = nCr(8,2);
    cout<<"Answer is: "<<ncr;
}