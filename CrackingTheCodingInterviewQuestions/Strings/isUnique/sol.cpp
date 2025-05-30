// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // using a data structure set
    bool isUnique(string s)
    {
        vector<int> arr(128, 0);
        
        for(char ch : s){
            int temp = (int)ch;
            arr[temp]++;

            if(arr[temp] > 1){
                return false;
            }
        }
        return true;
    }

    // without using any data structure
    bool isUnique2(string s){
        int checker = 0;
        for(int i = 0; i < s.length(); i++){
            int val = s[i] - 'a';
            if((checker & (1 << val)) > 0){
                return false;
            }
            checker |= (1 << val);
        }
        return true;
    }
};
int main()
{
    Solution obj;
    string s = "abca";

    if (obj.isUnique2(s))
    {
        cout << "Is Unique";
    }
    else
    {
        cout << "Not Unique";
    }
    return 0;
}