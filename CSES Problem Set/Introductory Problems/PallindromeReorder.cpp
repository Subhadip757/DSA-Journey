#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin>>s;

    int n = s.length();

    vector<int> hash(26, 0);
    int oddCount = 0;
    char oddChar = 0;

    for(int i = 0; i < n; i++){
        hash[s[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++){
        if(hash[i] % 2 != 0){
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    if((n % 2 == 0 && oddCount > 0) || (n % 2 == 1 && oddCount != 1)){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    string half = "";
    for(int i = 0; i < 26; i++){
        half.append(hash[i] / 2, 'A' + i);
    }

    string scHalf = half;
    reverse(scHalf.begin(), scHalf.end());

    if(n % 2 == 0){
        cout<<half << scHalf <<endl;
    }
    else{
        cout<<half<<oddChar<<scHalf<<endl;
    }
    return 0;
}