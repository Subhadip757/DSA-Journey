#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(char str[], int size) {
    int start = 0;
    int end = size - 1;

    while(start < end){
        if(str[start] == str[end]){
            return true;
        }
        start++;
        end--;
    }
    return false;
}

int armStrong(int num){

    int ans = 0;
    int original = num;

    while(num != 0){
        int digit = num % 10;
        ans += digit * digit * digit;
        num = num / 10;
    }
    return ans;

}

int main() {
    int nums = 156;
    if(armStrong(nums) == nums){
        cout<<"it is"<<endl;
    }else{
        cout<<"not"<<endl;
    }
}
