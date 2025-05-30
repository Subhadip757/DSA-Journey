#include <bits/stdc++.h>
using namespace std;

bool isValid(char ch){
    return (ch == ' ' || ch == '.' || ch == ',' || ch == '!' || ch =='?' || ch == ',');
}

string reverseWords(string w){
    string word;
    string res;

    for(int i = 0; i < w.length(); i++){
        if(!isValid(w[i])){
            word += w[i];
        }
        else{
            if(!word.empty()){
                reverse(word.begin(), word.end());
                res += word + w[i];
                word.clear();
            }
            else{
                res += w[i];
            }
        }
    }

    if(!word.empty()){
        reverse(word.begin(), word.end());
        res += word;
    }

    return res;
}

int main()
{
    string res = "zopsmart is hiring";
    string ans = reverseWords(res);
    cout<<ans;
    return 0;
}