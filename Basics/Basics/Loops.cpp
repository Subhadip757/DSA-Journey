#include <iostream>
using namespace std;

int main(){
    
    /*int n;
    cin>>n;

    int i = 1;
    while(i<=n){
        cout<<i<<" ";
        i=i+1;
    }*/

    /*int n;
    cin>>n;

    int i = 1;
    int sum = 0;
    while(i<=n){
        if(i%2 == 0){
            sum += i;
        }
        i++;
    }
    cout<<sum;*/

    /*int n;
    cin >> n;

    int i = 2;

    while(i < n){
        if(n%i == 0){
            cout<<"Not prime";
        }else{
            cout<<"Prime";
        }
        i= i + 1;
    }*/

    /*int n;
    cin>>n;

    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= n){
            cout<<i;
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;
    }*/


    // For Loops //
    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    cout<<"Printing count from 1 to n"<<endl;
    for(int i = 0; i<n;i++){
        cout<<i<<endl;
    }

    for(int a=0,b=1; a>=0 && b>=1;a--,b--){
        cout<<a<<" "<<b<<endl;
    }
}