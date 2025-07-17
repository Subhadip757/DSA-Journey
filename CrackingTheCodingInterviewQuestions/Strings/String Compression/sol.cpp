// Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase
// (a - z)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string compress(string str){
        string res;
        int count = 1;

        for(int i = 1; i <= str.size(); i++){
            if(i < str.length() && str[i] == str[i - 1]){
                count++;
            }
            else{
                res += str[i - 1];
                res += to_string(count);
                count = 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string str = "aabcccccaa";
    
    string ans = sol.compress(str);
    cout<<"\nNew String: "<<ans<<endl;
    cout<<"\nSize of the String: "<<ans.size()<<endl<<endl;
    return 0;
}