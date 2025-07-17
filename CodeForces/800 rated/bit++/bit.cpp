#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;cin>>n;
    int val = 0;
    int countPlus = 0;

    while(n--){
        string inp;cin>>inp;
        for(char ch : inp){
            if(ch == '+'){
                countPlus++;
            }
        }

        if(countPlus == 2){
            val++;
            countPlus = 0;
        }
        else{
            val--;
        }
    }
    cout<<val;
}