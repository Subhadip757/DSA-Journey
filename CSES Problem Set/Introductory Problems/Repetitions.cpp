#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string str; cin>>str;
    if(str.length() == 1){
        cout<<1<<endl;
        return 0;
    }
    int count = 1;
    int maxi = 0;
    
    for(int i = 1; i < static_cast<int>(str.length()); i++){
        if(str[i] == str[i - 1]){
            count++;
        }
        else{
            count = 1;
        }
        maxi = max(count, maxi);
    }

    cout<<maxi<<endl;

    return 0;
}