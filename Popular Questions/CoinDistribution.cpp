#include <iostream>
using namespace std;

int main(){
    int n;
    cin >>n;
    int f = (n-4)/5;
    int o;
    if((n-5*f)%2 == 0){
        o = 2;
    }else{
        o = 1;
    }
    int t = (n-5*f-o)/2;
    cout<<o+t+f<<" "<<f<<" "<<t<<" "<<o<<endl;
}