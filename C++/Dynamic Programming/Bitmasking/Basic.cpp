#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void add(int &subset, int x){
    subset = (subset ^ (1 << (x - 1)));
}

void remove(int &subset, int x){
    subset = (subset ^ (1 << (x - 1)));
}

void display(int subset){
    for(int bit_no = 0; bit_no <= 9; bit_no++){
        if(subset & (1 << bit_no)){
            cout<<bit_no + 1 <<" ";
        }
    }
    cout<<endl;
}

int main(){
    int set = 15;
    remove(set, 2);
    add(set, 9);
    display(set);
    return 0;
}