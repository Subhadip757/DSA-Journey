#include <iostream>

using namespace std;

int fibonacci(int n){
    for(int i = 0; i < n; i++){
        if(n <= 1){
            return 1;
        }else{
            return fibonacci(n-1) + fibonacci(n-2);
        }
    }

}

int main(){
    int n;
    cout<<"Enter range: ";
    cin>>n;
    cout<<endl;
    int result = fibonacci(n);
    cout<<result;
}