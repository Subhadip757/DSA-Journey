#include<bits/stdc++.h>
using namespace std;

int main(){
    long result = pow(2,31);
    long ans = result % 5;

    if(ans < 0){
        ans += 5;
    }

    cout<<ans;

    ofstream fout;

    fout.open("new.txt");

    fout<<"This is a new file";

    fout.close();
}