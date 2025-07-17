#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    vector<int> hash(26, 0);
    
    vector<string> arr = {"abcd", "abz", "abcd", "abd", "axtuv"};
    int n = arr.size();
    
    for(const string& itr : arr){
        for(char ch : itr){
            hash[ch - 'a']++;
        }
    }
    
    int count = 0;
    
    for(int i = 0; i < 26; i++){
        if(hash[i] == n){
            count++;
        }
    }
    
    cout<<"Common Substring: "<<count;

    return 0;
}